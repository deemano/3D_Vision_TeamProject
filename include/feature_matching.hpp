#ifndef FEATURE_MATCHING_HPP
#define FEATURE_MATCHING_HPP

#include <opencv2/opencv.hpp>
#include <vector>

// Forward declaration of FeatureType from feature_extraction.hpp
enum class FeatureType;

// Function to match features between two sets of descriptors
std::vector<cv::DMatch> matchFeatures(const cv::Mat& descriptors1, const cv::Mat& descriptors2, FeatureType type);

// Function to determine if the matches are good
cv::Mat isGoodMatch(const std::vector<cv::KeyPoint>& keypoints1,
    const std::vector<cv::KeyPoint>& keypoints2,
    const std::vector<cv::DMatch>& goodMatches,
    int someMinimumMatches);

// Process matching
cv::Mat processMatching(const std::vector<cv::KeyPoint>& targetKeypoints,
    const cv::Mat& targetDescriptors,
    const std::vector<cv::KeyPoint>& frameKeypoints,
    const cv::Mat& frameDescriptors,
    FeatureType currentFeatureType,
    int minGoodMatches, double ransacReprojThreshold = 3.0);


#endif // FEATURE_MATCHING_HPP