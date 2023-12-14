#ifndef CAMCALIBRATION_HPP  // Header guard
#define CAMCALIBRATION_HPP

//#include <QString>
#include <opencv2/core/core.hpp> // This will define cv::Size
#include <opencv2/opencv.hpp>
#include <Eigen/Core>
#include <vector>

// Include other dependencies
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <opencv2/core/utils/logger.hpp>

// Include other dependencies
#include <opencv2/imgproc.hpp>      // For image processing functions like cvtColor
#include <opencv2/imgcodecs.hpp>    // For image I/O functions like imread
#include <opencv2/calib3d.hpp>      // For camera calibration functions

namespace fs = std::filesystem;     // Handle looping through dir files in cpp
 
// Creating vectors to store points for each checkerboard image
extern std::vector<std::vector<cv::Point3f>> objpoints;
extern std::vector<std::vector<cv::Point2f>> imgpoints;

struct CalibrationConfig {
    enum Pattern { CHECKERBOARD, CHARUCO, SYMMETRIC_DOTS, ASYMMETRIC_DOTS } patternType = CHECKERBOARD;
    cv::Size boardSize = cv::Size(10, 7);    // Used for checkerboard and CHARUCO; for dots, define if needed
    std::string defaultDatasetPath = "../../../../resources/calibrationPix"; // Default path to dataset
    std::string customDatasetPath;              // Custom dataset path set by the user
    bool useDefaultDataset = true;              // Flag to use default dataset
    std::string defaultSavePath = "../../../../resources/";                 // Default save location
    std::string customSavePath;                 // Custom save path set by the user
    bool useDefaultSaveLocation = true;         // Flag to use default save location
    int numberOfImages = 30;                    // Default number of images for calibration
    bool showResults = true;                    // Flag to show results

    // Add additional fields here as needed, for example:
    // - Parameters specific to CHARUCO, Symmetric Dots, Asymmetric Dots
    // - Sizes for different pattern types
    // - Any other calibration parameters
};

void camCalibration(const CalibrationConfig& config);

// Declaration of additional helper functions
void setupObjectPoints(const CalibrationConfig& config, std::vector<cv::Point3f>& objp);
bool processImage(const std::string& filePath, const CalibrationConfig& config, const std::vector<cv::Point3f>& objp, cv::Size& imageSize, bool& isFirstImage);
void performCalibration(const CalibrationConfig& config, const cv::Size& imageSize);
void handleCalibrationResults(const CalibrationConfig& config, const cv::Mat& cameraMatrix, const cv::Mat& distCoeffs, double calibrationError);

#endif // CAMCALIBRATION_HPP

