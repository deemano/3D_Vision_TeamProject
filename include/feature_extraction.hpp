#ifndef FEATURE_EXTRACTION_HPP
#define FEATURE_EXTRACTION_HPP

#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>
#include <functional>
#include <vector>
#include <string>
#include <iostream>

// Feature type identifier
enum class FeatureType { ORB, SIFT, KAZE, BRISK, AKAZE };

// Default paths for image and video
const std::string defaultImagePath = "../../../../resources/ID5.jpg";
const std::string defaultVideoPath = "../../../../resources/vid3.mp4";

// Function to handle basic processing of each frame
void defaultProcessingFunction(cv::Mat& frame,
    const std::vector<cv::KeyPoint>& targetKeypoints,
    const cv::Mat& targetDescriptors,
    const std::vector<cv::KeyPoint>& frameKeypoints,
    const cv::Mat& frameDescriptors);

// Class definition for FeatureExtractor
class FeatureExtractor {
public:
    // Default parameter values
    static constexpr int defaultMaxFeatures = 2600;
    static constexpr int defaultInliersThreshold = 5;
    static constexpr int defaultSkipRate = 2;
    static constexpr int defaultVideoWidth = 1280;
    static constexpr int defaultVideoHeight = 720;
    static constexpr int defaultFps = 30;

    // Constructor: Initializes a feature extractor for the specified type and number of features
    FeatureExtractor(FeatureType type = FeatureType::ORB, int maxFeatures = defaultMaxFeatures);

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
void processImageAndVideo(
    const std::string& imagePath,  // Path to the target image for feature extraction
    const std::string& videoPath,  // Path to the video for feature extraction
    FeatureType featureType,       // Type of feature extractor to use (e.g., ORB, SIFT)
    int maxFeatures,               // Maximum number of features to detect
    int skipRate,                  // Number of frames to skip in the video processing
    void (*processFunction)(cv::Mat&, const std::vector<cv::KeyPoint>&, const cv::Mat&,
        const std::vector<cv::KeyPoint>&, const cv::Mat&, FeatureType));

// Define a default processing function
void defaultProcessingFunction(cv::Mat& frame,
    const std::vector<cv::KeyPoint>& targetKeypoints,
    const cv::Mat& targetDescriptors,
    const std::vector<cv::KeyPoint>& frameKeypoints,
    const cv::Mat& frameDescriptors,
    FeatureType featureType);

std::string featureTypeToString(FeatureType type);

#endif // FEATURE_EXTRACTION_HPP
