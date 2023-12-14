import argparse
import cv2
import numpy as np
import os
import sys
import csv
from objloader_simple import *
import math
import threading
import time

# Define the minimum number of matches required for object recognition
# Define the minimum number of matches required for object recognition
MIN_MATCHES = 10
DEFAULT_COLOR = (0, 0, 0)

# Define default file paths
DEFAULT_VIDEO_PATH = 'data/vid3.mp4'
DEFAULT_CALIBRATION_PATH = 'data/calibration_params.csv'
DEFAULT_POSE_MATRIX_PATH = 'data/poseMatrices.csv'
DEFAULT_MODEL_IMAGE_PATH = 'data/ID5.jpg'
DEFAULT_OBJ_MODEL_PATH = 'models/fox.obj'
DEFAULT_OUTPUT_DIR = 'output'

def render(img, obj, pose_matrix, model, color=False):
    """
    Render a loaded obj model into the current video frame using the pose matrix.
    """
    vertices = obj.vertices
    scale_matrix = np.eye(3) * 3
    h, w = model.shape

    for face in obj.faces:
        face_vertices = face[0]
        points = np.array([vertices[vertex - 1] for vertex in face_vertices])
        points = np.dot(points, scale_matrix)
        points = np.array([[p[0] + w / 2, p[1] + h / 2, p[2]] for p in points])
        dst = cv2.perspectiveTransform(points.reshape(-1, 1, 3), pose_matrix[:3, :4])
        imgpts = np.int32(dst)

        if color is False:
            cv2.fillConvexPoly(img, imgpts, DEFAULT_COLOR)
        else:
            color = hex_to_rgb(face[-1])
            color = color[::-1]  # Reverse the color order
            cv2.fillConvexPoly(img, imgpts, color)

    return img

def projection_matrix(camera_parameters, homography):
    """
    Computes the 3D projection matrix from camera parameters and homography.
    """
    homography = homography * (-1)
    rot_and_transl = np.dot(np.linalg.inv(camera_parameters), homography)
    col_1 = rot_and_transl[:, 0]
    col_2 = rot_and_transl[:, 1]
    col_3 = rot_and_transl[:, 2]
    l = math.sqrt(np.linalg.norm(col_1, 2) * np.linalg.norm(col_2, 2))
    rot_1 = col_1 / l
    rot_2 = col_2 / l
    translation = col_3 / l
    c = rot_1 + rot_2
    p = np.cross(rot_1, rot_2)
    d = np.cross(c, p)
    rot_1 = np.dot(c / np.linalg.norm(c, 2) + d / np.linalg.norm(d, 2), 1 / math.sqrt(2))
    rot_2 = np.dot(c / np.linalg.norm(c, 2) - d / np.linalg.norm(d, 2), 1 / math.sqrt(2))
    rot_3 = np.cross(rot_1, rot_2)
    projection = np.stack((rot_1, rot_2, rot_3, translation)).T
    return np.dot(camera_parameters, projection)

def hex_to_rgb(hex_color):
    """
    Converts hex color strings to RGB format.
    """
    hex_color = hex_color.lstrip('#')
    h_len = len(hex_color)
    return tuple(int(hex_color[i:i + h_len // 3], 16) for i in range(0, h_len, h_len // 3))

def read_csv(file_path):
    """
    Reads a CSV file to extract camera parameters and distortion coefficients.
    """
    with open(file_path, newline='') as csvfile:
        csvreader = csv.reader(csvfile, delimiter=',')
        camera_matrix = []
        dist_coeffs = []
        reading_camera_matrix = True

        for row in csvreader:
            if row and (row[0].strip() == 'Camera Matrix' or row[0].strip() == 'Distortion Coefficients'):
                reading_camera_matrix = row[0].strip() != 'Distortion Coefficients'
                continue

            if reading_camera_matrix:
                camera_matrix.append([float(x) for x in row])
            else:
                dist_coeffs = [float(x) for x in row]

    return np.array(camera_matrix), np.array(dist_coeffs)

# Read Pose csv data
def read_pose_estimation_data(file_path):
    """
    Reads pose estimation data from a CSV file.
    Each row in the CSV represents the pose matrix for a specific frame.
    """
    pose_matrices = []
    with open(file_path, newline='') as csvfile:
        csvreader = csv.reader(csvfile, delimiter=',')
        next(csvreader)  # Skip the header row
        for row in csvreader:
            # Convert the row into a 4x4 matrix
            matrix_values = [float(value) for value in row[1:]]  # Exclude frame number
            matrix = np.array(matrix_values).reshape(4, 4)
            pose_matrices.append(matrix)
    return pose_matrices

# Get absolute path to relative 
def resource_path(relative_path):
    """ Get absolute path to resource, works for dev and for PyInstaller """
    base_path = getattr(sys, '_MEIPASS', os.path.dirname(os.path.abspath(__file__)))
    return os.path.join(base_path, relative_path)

# Time Trigger for Data Input
def input_with_timeout(prompt, timeout):
    print(prompt, end='', flush=True)
    result = [None]
    def get_input():
        result[0] = input()
    input_thread = threading.Thread(target=get_input)
    input_thread.daemon = True
    input_thread.start()
    input_thread.join(timeout)
    if input_thread.is_alive():
        print("\nTimeout reached - proceeding with default values.")
    return result[0]

def main():
    """
    Main function to process the video and perform augmented reality overlay.
    """
    # Interactive prompts for file paths
    print("\nPress 'Enter' to define datasets or wait 10 seconds for default data.")
    video_path = input_with_timeout("Enter the path to the video file: ", 10) or DEFAULT_VIDEO_PATH

    if video_path == DEFAULT_VIDEO_PATH:
        # Use defaults for all
        calibration_path = DEFAULT_CALIBRATION_PATH
        pose_matrix_path = DEFAULT_POSE_MATRIX_PATH
        model_image_path = DEFAULT_MODEL_IMAGE_PATH
        obj_model_path = DEFAULT_OBJ_MODEL_PATH
        output_dir = DEFAULT_OUTPUT_DIR
    else:
        # User entered the video path, prompt for the rest
        calibration_path = input_with_timeout("Enter the path to the calibration CSV file: ", 10) or DEFAULT_CALIBRATION_PATH
        pose_matrix_path = input_with_timeout("Enter the path to the pose matrix CSV file: ", 10) or DEFAULT_POSE_MATRIX_PATH
        model_image_path = input_with_timeout("Enter the path to the model image file: ", 10) or DEFAULT_MODEL_IMAGE_PATH
        obj_model_path = input_with_timeout("Enter the path to the OBJ model file: ", 10) or DEFAULT_OBJ_MODEL_PATH
        output_dir = input_with_timeout("Enter the path to the output directory: ", 10) or DEFAULT_OUTPUT_DIR

    #
    global MIN_MATCHES

    # Read camera parameters and distortion coefficients from CSV
    try:
        camera_parameters, dist_coefficients = read_csv(calibration_path)
    except Exception as e:
        print(f"Error reading calibration file: {e}")
        return

    # Read pose estimation data from CSV
    try:
        pose_matrices = read_pose_estimation_data(pose_matrix_path)
    except Exception as e:
        print(f"Error reading pose matrix file: {e}")
        return

    # Initialize ORB keypoint detector and BFMatcher
    orb = cv2.ORB_create()
    bf = cv2.BFMatcher(cv2.NORM_HAMMING, crossCheck=True)

    # Load the reference surface and 3D model
    try:
        model = cv2.imread(model_image_path, 0)
        if model is None:
            raise FileNotFoundError(f"Model image not found at path: {model_image_path}")
        kp_model, des_model = orb.detectAndCompute(model, None)
        obj = OBJ(obj_model_path, swapyz=True)
    except Exception as e:
        print(f"Error loading model or OBJ file: {e}")
        return

    # Initialize video capture
    try:
        cap = cv2.VideoCapture(video_path)
        if not cap.isOpened():
            raise IOError(f"Cannot open video: {video_path}")
    except Exception as e:
        print(f"Error opening video file: {e}")
        return

    # Prepare output directory and writer
    try:
        os.makedirs(output_dir, exist_ok=True)
        output_path = os.path.join(output_dir, 'output.avi')
        fourcc = cv2.VideoWriter_fourcc(*'XVID')
        out = cv2.VideoWriter(output_path, fourcc, 20.0, (1280, 720))
    except Exception as e:
        print(f"Error setting up video writer: {e}")
        return

    # Video processing loop
    frame_count = 0
    while True:
        ret, frame = cap.read()
        if not ret:
            print("Video processing completed.")
            break

        kp_frame, des_frame = orb.detectAndCompute(frame, None)
        matches = bf.match(des_model, des_frame)
        matches = sorted(matches, key=lambda x: x.distance)

        if len(matches) > MIN_MATCHES:
            # Use homography if pose data is not available for the frame
            if frame_count % 2 == 0 and frame_count // 2 < len(pose_matrices):
                pose_matrix = pose_matrices[frame_count // 2]
                frame = render(frame, obj, pose_matrix, model, color=False)
            else:
                src_pts = np.float32([kp_model[m.queryIdx].pt for m in matches]).reshape(-1, 1, 2)
                dst_pts = np.float32([kp_frame[m.trainIdx].pt for m in matches]).reshape(-1, 1, 2)
                homography, _ = cv2.findHomography(src_pts, dst_pts, cv2.RANSAC, 5.0)
                if homography is not None:
                    projection = projection_matrix(camera_parameters, homography)
                    frame = render(frame, obj, projection, model, color=False)

        cv2.imshow("AR", frame)
        out.write(frame)

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

        frame_count += 1

    cap.release()
    out.release()
    cv2.destroyAllWindows()
    
if __name__ == '__main__':
    main()