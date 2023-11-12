# Project Title: 3D_Vision_TeamProject

## 


### To DO:
1. Camera Calibration			
   This step involves calculating the camera constants to correct lens distortion. 
   We'll need to use chessboard images and OpenCV functions like findChessboardCorners and calibrateCamera.

2. Feature Extraction and Description
   Identify distinctive features in the image that can be used to track objects. 
   Functions like SIFT, SURF, or ORB can be used to find and describe these keypoints.

3. Feature Matching 		
   After extracting features, we'll need to match them between the current video frame and the predefined token. 
   Functions such as BFMatcher or FLANN can be utilized for this purpose.

4. RANSAC - Homography Computation
   The Random Sample Consensus (RANSAC) algorithm is used to estimate the homography matrix that accounts for 
   perspective distortion. OpenCV's findHomography can be employed with RANSAC as the method.

5. Planar Pose Estimation
   With the homography matrix, compute the pose of the plane in the scene. 
   We'll need to extract the rotation and translation vectors, potentially using the solvePnP function.

6. 3D Object Integration
   This involves rendering a 3D object onto the video stream. You will have to transform the 3D coordinates 
   of the virtual object to match the pose of the token using the previously computed pose.

7. Display 
   The final step is to overlay the 3D object on the video stream in real-time. 
   This will involve updating the position of the object as the video plays.

8. Add Extras (possible ideas)
   Creation of a mobile app that uses the AR functionality.
   Animation of virtual objects to make them interact in the augmented reality environment.
   Token generalisation, so the application can recognize and augment various tokens.
   Frontend Development to make the application user-friendly.
   Optimisation of intermediate stages for better performance and stability.


Deadline: 6th December 2023.