#include "planar_pose_estimation.hpp"
// Include other necessary headers

// Function declarations (put these in your planar_pose_estimation.hpp)
bool loadCalibrationParameters(const std::string& filename, cv::Mat& cameraMatrix, cv::Mat& distCoeffs);
bool computePoseFromHomography(const cv::Mat& H, const cv::Mat& cameraMatrix, cv::Mat& pose);

// Load the camera matrix (K) and distortion coefficients from file
cv::Mat cameraMatrix, distCoeffs;
// Function to load calibration parameters
bool loadCalibrationParameters(const std::string& filename, cv::Mat& cameraMatrix, cv::Mat& distCoeffs) {
    cv::FileStorage fs(filename, cv::FileStorage::READ);
    if (!fs.isOpened()) {
        std::cerr << " Failed to open " << filename << std::endl;
        return false; // Return false to indicate failure
    }

    fs["cameraMatrix"] >> cameraMatrix;
    fs["distCoeffs"] >> distCoeffs;
    fs.release();
    return true; // Return true to indicate success
}

// Assume 'matches', 'targetKeypoints', and 'frameKeypoints' are provided from 'feature_matching.cpp'
std::vector<cv::DMatch> matches; // This should be filled with the matches found in the current frame
std::vector<cv::KeyPoint> targetKeypoints, frameKeypoints; // Fill with keypoints from the current frame

// Placeholder for the homography matrix H computed in 'feature_matching.cpp'
cv::Mat H;

// Function to compute pose from the homography matrix
bool computePoseFromHomography(const cv::Mat & H, const cv::Mat & cameraMatrix, cv::Mat & pose) {
    // Decompose the homography matrix to extract rotation and translation
    // You might need to adapt this depending on the specific method you choose for decomposition
    // OpenCV functions like cv::decomposeHomographyMat can be used if suitable for your case
    std::cout << " Computed Homography: \n" << H << std::endl; // Print the homography matrix

    // Placeholder for the outputs of the decomposition
    std::vector<cv::Mat> rotations, translations, normals;
    int numSolutions = cv::decomposeHomographyMat(H, cameraMatrix, rotations, translations, normals);

    // Print the possible rotations and translations
    int validIndex = -1; // Index of the valid solution
    for (size_t i = 0; i < numSolutions; ++i) {
        cv::Mat normal = rotations[i].col(2); // Plane normal
        cv::Mat cameraCenter = -translations[i]; // Camera center in the world coordinate system

        if (normal.dot(cameraCenter) < 0 && cameraCenter.at<double>(2) > 0) {
            validIndex = i;
            break;
        }
    }

    if (validIndex != -1) {
        pose = cv::Mat::eye(4, 4, CV_64F);
        rotations[validIndex].copyTo(pose(cv::Rect(0, 0, 3, 3)));
        translations[validIndex].copyTo(pose(cv::Rect(3, 0, 1, 3)));

        // Print only the selected rotation and translation matrices
        std::cout << "\n Selected Rotation Matrix: \n" << rotations[validIndex] << std::endl;
        std::cout << "\n Selected Translation Vector: \n" << translations[validIndex] << std::endl;
        std::cout << "\n Selected Pose Matrix: \n" << pose << "\n========================\n" << std::endl;

        return true;
    }
    else {
        std::cerr << " No valid pose found." << std::endl;
        return false;
    }
}

// The estimatePlanarPose function needs to be adjusted to work with dynamic H
void estimatePlanarPose(const cv::Mat& cameraMatrix,
    const std::vector<cv::KeyPoint>& targetKeypoints,
    const cv::Mat& targetDescriptors,
    const std::vector<cv::KeyPoint>& frameKeypoints,
    const cv::Mat& frameDescriptors,
    FeatureType currentFeatureType,
    int minGoodMatches) {
    // Get the homography matrix from processMatching (to be implemented in feature_matching.cpp)
    cv::Mat H = processMatching(targetKeypoints, targetDescriptors, frameKeypoints, frameDescriptors, currentFeatureType, minGoodMatches);

    // Check if H is not empty (which means it's valid)
    if (!H.empty()) {
        cv::Mat pose;
        if (computePoseFromHomography(H, cameraMatrix, pose)) {
            // Use 'pose' to position your 3D object in the scene
            // This is where you would integrate with your rendering system
            // Render the 3D object using the pose information
        }
        else {
            // Handle the case where the pose could not be computed
        }
    }
    else {
        // Handle the case where the homography could not be determined
    }
}

// Rest of your code...
