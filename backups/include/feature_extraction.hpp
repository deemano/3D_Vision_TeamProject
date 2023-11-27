#ifndef FEATURE_EXTRACTION_HPP
#define FEATURE_EXTRACTION_HPP

#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp> // For access to feature detectors and descript
#include <vector>
#include <string>
#include <iostream>

// Feature type identifier
enum class FeatureType { ORB, SIFT, KAZE, BRISK, AKAZE };

// Forward declarations


// Class definition for FeatureExtractor
class FeatureExtractor {
public: 
    // Constructor: Initializes a feature extractor for the specified type and number of features
    FeatureExtractor(FeatureType type = FeatureType::ORB, int maxFeatures = 500);

    // Method to detect keypoints and compute descriptors from an image
    void detectAndCompute(const cv::Mat& image, std::vector<cv::KeyPoint>& keypoints, cv::Mat& descriptors);

    // Method to get the type of feature extractor being used
    FeatureType getType() const;

private:
    // Pointer to the OpenCV feature detector and descriptor extractor base class
    cv::Ptr<cv::Feature2D> detector;
    FeatureType type; // Store the extracted type of feature

    // Method to log the detection info to the console for Debug
    void logDetectionInfo(const std::vector<cv::KeyPoint>& keypoints) const;
};

// Execute feature extraction & description
void processImageAndVideo(const std::string& imagePath,
    const std::string& videoPath, FeatureType featureType,
    int maxFeatures, int skipRate,
    std::function<void(const std::vector<cv::KeyPoint>&,
        const cv::Mat&, const std::vector<cv::KeyPoint>&,
        const cv::Mat&)> processFunction);

#endif // FEATURE_EXTRACTION_HPP