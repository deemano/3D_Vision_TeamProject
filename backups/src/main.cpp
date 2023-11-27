// Include all header structure:
#include "common.h"

// Include other necessary headers
#include <chrono>
//#include <opencv2/vizcore.hpp>
// Include OpenGL libraries
//#include <../../../../libs/GL/glew.h>
//#include <../../../../libs/glut-master/include/GL/glut.h>

// Main Loop
int main() {
    try {
        // Execute calibration
        camCalibration();

        // Start time for measuring execution of different algos
        auto start = std::chrono::high_resolution_clock::now();

        // Variables for feature_extraction.cpp
        int maxFeatures = 1000;
        int skipRate = 6;

        // Control variable to switch between ORB and SIFT, could be set by GUI
        int featSelection = 0;
        FeatureType currentFeatureType;
        if (featSelection == 1) { currentFeatureType = FeatureType::ORB; }
        else if (featSelection == 2) { currentFeatureType = FeatureType::KAZE; }
        else if (featSelection == 3) { currentFeatureType = FeatureType::BRISK; }
        else if (featSelection == 4) { currentFeatureType = FeatureType::AKAZE; }
        else {
            // Default or error handling
            currentFeatureType = FeatureType::SIFT; // // Best performance so far
        }

        // Load camera calibration parameters
        cv::Mat cameraMatrix, distCoeffs;
        if (!loadCalibrationParameters("calibration_params.yml", cameraMatrix, distCoeffs)) {
            std::cerr << "Error loading calibration parameters." << std::endl;
            return EXIT_FAILURE;
        }

        // Process the image and video for feature extraction and matching
        // The lambda function captures currentFeatureType by value since it's used inside the lambda
        processImageAndVideo("../../../../resources/ID.jpg", "../../../../resources/vid3.mp4", currentFeatureType, maxFeatures, skipRate,
            [&cameraMatrix, &currentFeatureType](const std::vector<cv::KeyPoint>& targetKeypoints, const cv::Mat& targetDescriptors,
                const std::vector<cv::KeyPoint>& frameKeypoints, const cv::Mat& frameDescriptors) {

                    // Match features between target image and the current frame of the video
                    auto matches = matchFeatures(targetDescriptors, frameDescriptors, currentFeatureType);

                    /*  Process matching results and check if there is a good match
                        If a good match is found, processMatching will print the result */
                        // Process matching results and get homography matrix H
                    cv::Mat H = processMatching(targetKeypoints, targetDescriptors, frameKeypoints, frameDescriptors, currentFeatureType, 30);

                    // Perform pose estimation if a valid homography matrix is found
                    if (!H.empty()) {
                        cv::Mat pose;
                        if (computePoseFromHomography(H, cameraMatrix, pose)) {
                            // Use 'pose' to position and render your 3D object in the scene
                            // This is where you integrate with your 3D rendering system
                        }
                    }
            });

        // Measure and print the time taken for the entire operation
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;

        // Execute dynamic pose estimation
        if (!loadCalibrationParameters("calibration_params.yml", cameraMatrix, distCoeffs)) {
            return EXIT_FAILURE;
        }
    }
    // exception handling
    catch (const std::exception& e) {
        std::cerr << " An error occurred: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;;
}