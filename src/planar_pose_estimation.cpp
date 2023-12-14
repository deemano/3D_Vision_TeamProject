#include "planar_pose_estimation.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>

// Global variables for camera calibration data
cv::Mat globalCameraMatrix, globalDistCoeffs;

// Load calibration parameters from a file
// GlobalCameraMatrix and globalDistCoeffs are defined globally
extern cv::Mat globalCameraMatrix;
extern cv::Mat globalDistCoeffs;
bool loadCalibrationParameters(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open calibration file: " << filename << std::endl;
        return false;
    }
    // Extract data 
    std::string line;
    std::vector<std::vector<double>> values;
    while (std::getline(file, line)) {
        // Skip header lines
        if (line.find("Camera Matrix") != std::string::npos || line.find("Distortion Coefficients") != std::string::npos) {
            continue;
        }

        std::stringstream lineStream(line);
        std::string cell;
        std::vector<double> rowValues;

        while (std::getline(lineStream, cell, ',')) {
            try {
                rowValues.push_back(std::stod(cell));
            }
            catch (const std::invalid_argument&) {
                std::cerr << "Invalid numeric value in file: " << filename << " in line: " << line << std::endl;
                return false;
            }
        }
        values.push_back(rowValues);
    }

    // Check if values contain the expected number of rows
    if (values.size() != 4) {
        std::cerr << "Unexpected format in file: " << filename << std::endl;
        return false;
    }

    // Assign values to globalCameraMatrix and globalDistCoeffs
    globalCameraMatrix = cv::Mat(3, 3, CV_64F);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            globalCameraMatrix.at<double>(i, j) = values[i][j];
        }
    }
    // Populate Matrix
    globalDistCoeffs = cv::Mat(values[3].size(), 1, CV_64F);
    for (size_t i = 0; i < values[3].size(); ++i) {
        globalDistCoeffs.at<double>(i, 0) = values[3][i];
    }
    // Distribute extracted values
    std::cout << "Calibration parameters loaded successfully." << std::endl;
    std::cout << "  K: \n" << globalCameraMatrix << std::endl;
    std::cout << "  Distortion: \n" << globalDistCoeffs << std::endl;
    return true;
}

// Estimate the pose from a homography matrix
bool estimatePose(const cv::Mat& H, PoseData& poseData) {
    // Verify that the homography matrix H is valid
    if (H.empty() || H.rows != 3 || H.cols != 3) {
        std::cerr << " Invalid homography matrix." << std::endl;
        return false;
    }

    // Verify that the global camera matrix has been loaded and is valid
    if (globalCameraMatrix.empty() || globalCameraMatrix.rows != 3 || globalCameraMatrix.cols != 3) {
        std::cerr << " Camera matrix has not been initialized." << std::endl;
        return false;
    }

    try { // Attempt to decompose the homography matrix into possible rotations and translations
        std::vector<cv::Mat> rotations, translations, normals;
        int numSolutions = cv::decomposeHomographyMat(H, globalCameraMatrix, rotations, translations, normals);
        // Check if at least one solution was found
        if (numSolutions <= 0) {
            std::cerr << " No valid solutions found in homography decomposition." << std::endl;
            return false;
        }
        // Iterate through the solutions to find a valid rotation and translation
        int validIndex = -1;
        for (size_t i = 0; i < numSolutions; ++i) { // rotations.size(); ++i) { // numSolutions

            // Check each solution to find one that meets the criteria for a valid pose
            cv::Mat normal = rotations[i].col(2);       // Normal of the plane
            cv::Mat cameraCenter = -translations[i];    // Camera center position

            // Select the solution where the camera is behind the normal (visible side of the plane)
            // and is positioned in front of the camera (positive Z value)
            if (normal.dot(cameraCenter) < 0 && cameraCenter.at<double>(2) > 0) {
                validIndex = i;
                break;
            }
        }
        // If a valid solution was found, populate the PoseData structure
        if (validIndex != -1) { // Store the valid rotation and translation
            poseData.rotationMatrices.push_back(rotations[validIndex]);
            poseData.translationVectors.push_back(translations[validIndex]);

            // Create the full pose matrix
            cv::Mat pose = cv::Mat::eye(4, 4, CV_64F);
            rotations[validIndex].copyTo(pose(cv::Rect(0, 0, 3, 3)));
            translations[validIndex].copyTo(pose(cv::Rect(3, 0, 1, 3)));
            poseData.poseMatrices.push_back(pose);

            // Log the valid rotation matrix and translation vector
            std::cout << " Valid Pose Found: " << std::endl;
            std::cout << " Rotation Matrix: " << std::endl;
            const cv::Mat& lastRotationMatrix = poseData.rotationMatrices.back();
            for (int i = 0; i < lastRotationMatrix.rows; ++i) {
                for (int j = 0; j < lastRotationMatrix.cols; ++j) {
                    std::cout << lastRotationMatrix.at<double>(i, j) << "  ";
                }
                std::cout << std::endl;
            }
            // Log Translation Matrix in the console
            std::cout << " Translation Vector: " << std::endl;
            const cv::Mat& lastTranslationVector = poseData.translationVectors.back();
            for (int i = 0; i < lastTranslationVector.rows; ++i) {
                std::cout << lastTranslationVector.at<double>(i, 0) << "  ";
            }
            std::cout << std::endl << std::endl;
            // Log the current size of poseMatrices vector
            std::cout << " Total number of valid poses found so far: " << poseData.poseMatrices.size() << std::endl << std::endl;
            // Directly print the entire pose matrix
            std::cout << " Pose: " << std::endl << pose << std::endl;
            return true;
        }
        else {
            std::cerr << " No valid pose solution matched the criteria." << std::endl;
            return false;
        }
    } // Catch and handle any errors that occur during the decomposition
    catch (const cv::Exception& e) {
        std::cerr << " OpenCV error during homography decomposition: " << e.what() << std::endl;
        return false;
    } 
}

// Store the Pose Data in a CSV file _NEEDS TO GET CALLED - DO NOT FORGET!!!
void savePoseMatrixToFile(const std::string& filename, const std::vector<cv::Mat>& poseMatrices) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << " Failed to open file for writing pose data: " << filename << std::endl;
        return;
    }

    file << " Frame,Pose Matrix\n";
    for (size_t frame = 0; frame < poseMatrices.size(); ++frame) {
        file << frame << " ,";
        // Assuming the pose matrix is 4x4 CV_64F
        for (int row = 0; row < 4; ++row) {
            for (int col = 0; col < 4; ++col) {
                file << std::fixed << std::setprecision(6) << poseMatrices[frame].at<double>(row, col);
                if (row < 3 || col < 3) file << ",";
            }
        }
        file << " \n";
    }
    // Close file
    file.close();
    std::cout << " Pose matrix data saved to " << filename << std::endl;
}