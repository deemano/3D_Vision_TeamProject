#ifndef PLANAR_POSE_ESTIMATION_HPP
#define PLANAR_POSE_ESTIMATION_HPP

#include <opencv2/opencv.hpp>
#include <vector>
#include <string>
#include "feature_matching.hpp" // Ensure this includes FeatureType definition

// Structure to hold pose estimation data
struct PoseData {
    std::vector<cv::Mat> rotationMatrices;      // Vector of rotation matrices
    std::vector<cv::Mat> translationVectors;    // Vector of translation vectors
    std::vector<cv::Mat> poseMatrices;          // Vector of pose matrices
};

struct PosesVector {
    std::vector<cv::Mat> poseMat;          // Vector of pose matrices
};

// Load camera calibration parameters from a file. This function populates 
// global variables for camera matrix and distortion coefficients.
bool loadCalibrationParameters(const std::string& filename);

// Estimate the pose from a given homography matrix. This function uses 
// global variables for camera matrix and distortion coefficients.
bool estimatePose(const cv::Mat& H, PoseData& poseData);

// For Pose Data saving to use in Projection
void savePoseMatrixToFile(const std::string& filename, const std::vector<cv::Mat>& poseMatrices);

#endif // PLANAR_POSE_ESTIMATION_HPP