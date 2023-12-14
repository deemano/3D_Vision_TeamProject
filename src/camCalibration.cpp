#include "camCalibration.hpp"
#include <fstream>

// Global vectors to store 3D world points and 2D image points for calibration
std::vector<std::vector<cv::Point3f>> objpoints;
std::vector<std::vector<cv::Point2f>> imgpoints;

// Main function to handle camera calibration
void camCalibration(const CalibrationConfig& config) {
    std::cout << " Starting camera calibration..." << std::endl;
    // Suppress detailed logging from OpenCV
    cv::utils::logging::setLogLevel(cv::utils::logging::LOG_LEVEL_SILENT);

    std::vector<cv::Point3f> objp;  // Object points for the current pattern
    cv::Size imageSize;             // Size of the images used for calibration
    bool isFirstImage = true;       // Flag to mark the first image processed

    // Setup the object points based on the selected calibration pattern
    setupObjectPoints(config, objp);

    // Iterate over the images in the dataset and process them, nomatter the compatible format
    std::string datasetPath = config.useDefaultDataset ? config.defaultDatasetPath : config.customDatasetPath;
    for (const auto& entry : fs::directory_iterator(datasetPath)) {
        if (!entry.is_regular_file()) continue;
        std::string filePath = entry.path().string();
        std::string extension = entry.path().extension().string();
        // Restrict Image Formats - if removed goes though all types & process compatibles
        if (extension == ".jpg" || extension == ".png" || extension == ".jpeg") {
            if (processImage(filePath, config, objp, imageSize, isFirstImage)) {
                std::cout << " Processed image: " << filePath << std::endl;
            }
        }
    }
    std::cout << " \n Gathering calibration results. This may take a while. \n Please hold tight...\n" << std::endl;
    // Perform the actual calibration process using the collected object and image points
    performCalibration(config, imageSize);
}

// Setup object points for calibration based on the pattern type
void setupObjectPoints(const CalibrationConfig& config, std::vector<cv::Point3f>& objp) {
    if (config.patternType == CalibrationConfig::CHECKERBOARD) {
        for (int i = 0; i < config.boardSize.height; ++i) {
            for (int j = 0; j < config.boardSize.width; ++j) {
                objp.push_back(cv::Point3f(j, i, 0)); // Assume square size is 1 unit
            }
        }
    }
    // Additional setup for other pattern types can be added here
}

// Process each image for corner detection
bool processImage(const std::string& filePath, const CalibrationConfig& config, const std::vector<cv::Point3f>& objp, cv::Size& imageSize, bool& isFirstImage) {
    cv::Mat img = cv::imread(filePath, cv::IMREAD_GRAYSCALE);
    if (img.empty()) {
        std::cerr << " Failed to load image: " << filePath << std::endl;
        return false;
    }

    // Set imageSize on first successful image load
    if (isFirstImage) {
        imageSize = img.size();
        isFirstImage = false;
    }

    std::vector<cv::Point2f> corner_pts; // Detected corners in the image
    // Find chessboard corners in the image
    bool success = cv::findChessboardCorners(img, config.boardSize, corner_pts, cv::CALIB_CB_ADAPTIVE_THRESH | cv::CALIB_CB_FAST_CHECK | cv::CALIB_CB_NORMALIZE_IMAGE);

    if (success) {
        // Refine corner positions
        cv::cornerSubPix(img, corner_pts, cv::Size(11, 11), cv::Size(-1, -1), cv::TermCriteria(cv::TermCriteria::EPS | cv::TermCriteria::MAX_ITER, 30, 0.001));
        objpoints.push_back(objp);          // Add object points for this image
        imgpoints.push_back(corner_pts);    // Add detected corners for this image
    }
    else {
        std::cerr << " Chessboard corners not found in image: " << filePath << std::endl;
        return false;
    }
    return true;
}

// Perform the camera calibration using the collected object and image points
void performCalibration(const CalibrationConfig& config, const cv::Size& imageSize) {
    cv::Mat cameraMatrix, distCoeffs, R, T; // Calibration result variables
    // Calibrate the camera and get the error of calibration
    double calibrationError = cv::calibrateCamera(objpoints, imgpoints, imageSize, cameraMatrix, distCoeffs, R, T);

    if (calibrationError == -1) {
        std::cerr << " Camera calibration failed." << std::endl;
        return;
    }
    else {
        std::cout << " Calibration successful. Error: " << calibrationError << std::endl;
        // Handle the results of the calibration (displaying and saving)
        handleCalibrationResults(config, cameraMatrix, distCoeffs, calibrationError);
    }
}

// Handle and display the results of the calibration
void handleCalibrationResults(const CalibrationConfig& config, const cv::Mat& cameraMatrix, const cv::Mat& distCoeffs, double calibrationError) {
    if (config.showResults) { // Print Resultsin Console
        std::cout << " Camera matrix:" << std::endl << cameraMatrix << std::endl;
        std::cout << " Distortion coefficients:" << std::endl << distCoeffs << std::endl;
    }
    namespace fs = std::filesystem; // Access filesystem functions
    std::string saveFilePath;       // Initialize filename string

    // Set saveFilePath to the current working directory if defaultSavePath is empty
    if (config.useDefaultSaveLocation && config.defaultSavePath.empty()) {
        saveFilePath = fs::current_path().string() + "/";
    }
    else { saveFilePath = config.useDefaultSaveLocation ? config.defaultSavePath : config.customSavePath; }

    saveFilePath += "calibration_params.csv";  // Append the filename

    // Write camera matrix and distortion coefficients to the file
    std::ofstream outputFile(saveFilePath);
    if (!outputFile.is_open()) {
        std::cerr << " Failed to open file for writing: " << saveFilePath << std::endl;
        return;
    }

    // Writing the camera matrix and distortion coefficients to the file
    outputFile << " Camera Matrix" << std::endl;
    for (int i = 0; i < cameraMatrix.rows; ++i) {
        for (int j = 0; j < cameraMatrix.cols; ++j) {
            outputFile << cameraMatrix.at<double>(i, j);
            if (j < cameraMatrix.cols - 1) outputFile << ", ";
        }
        outputFile << std::endl;
    }
    // Write header for distortion coefficients
    outputFile << " Distortion Coefficients" << std::endl;
    for (int i = 0; i < distCoeffs.rows; ++i) {
        for (int j = 0; j < distCoeffs.cols; ++j) {
            outputFile << distCoeffs.at<double>(i, j);
            if (j < distCoeffs.cols - 1) outputFile << ", ";
        }
        outputFile << std::endl;
    }

    outputFile.close(); // Close the output file
    std::cout << " Calibration data saved successfully to: \n" << saveFilePath << std::endl;
    std::cout << " Camera calibration completed.\n" << std::endl;
}
