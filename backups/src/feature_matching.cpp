#include "feature_matching.hpp"
#include "feature_extraction.hpp" // For FeatureType enum

// Define a threshold for the minimum number of inliers
const int someInliersThreshold = 10; // Example value, adjust as needed

std::vector<cv::DMatch> matchFeatures(const cv::Mat& descriptors1, const cv::Mat& descriptors2, FeatureType type) {
    std::vector<cv::DMatch> goodMatches;

    if (type == FeatureType::ORB) {
        // ORB descriptors are already in CV_8U, no need to convert
        cv::Ptr<cv::DescriptorMatcher> matcher = cv::DescriptorMatcher::create(cv::DescriptorMatcher::BRUTEFORCE_HAMMING);
        matcher->match(descriptors1, descriptors2, goodMatches);
    }
    else { // Assume FeatureType::SIFT
        // Convert descriptors to type CV_32F if necessary
        cv::Mat descriptors1Float = descriptors1;
        if (descriptors1.type() != CV_32F) {
            descriptors1.convertTo(descriptors1Float, CV_32F);
        }
        cv::Mat descriptors2Float = descriptors2;
        if (descriptors2.type() != CV_32F) {
            descriptors2.convertTo(descriptors2Float, CV_32F);
        }

        // Use FLANN matcher for SIFT descriptors
        cv::Ptr<cv::DescriptorMatcher> matcher = cv::DescriptorMatcher::create(cv::DescriptorMatcher::FLANNBASED);
        std::vector<std::vector<cv::DMatch>> knnMatches;
        matcher->knnMatch(descriptors1Float, descriptors2Float, knnMatches, 2); // Find the 2 nearest neighbors

        // Filter matches using the Lowe's ratio test
        const float ratioThresh = 0.75f;
        for (size_t i = 0; i < knnMatches.size(); i++) {
            if (knnMatches[i][0].distance < ratioThresh * knnMatches[i][1].distance) {
                goodMatches.push_back(knnMatches[i][0]);
            }
        }
    }

    return goodMatches;
}

cv::Mat isGoodMatch(const std::vector<cv::KeyPoint>& keypoints1,
    const std::vector<cv::KeyPoint>& keypoints2,
    const std::vector<cv::DMatch>& goodMatches,
    int someMinimumMatches) {
    // Check if the number of good matches is above the threshold
    if (goodMatches.size() < someMinimumMatches) {
        std::cout << "Not enough matches: " << goodMatches.size() << std::endl;
        return cv::Mat(); // Return an empty cv::Mat to indicate failure
    }

    // Check the quality of the homography
    std::vector<cv::Point2f> points1, points2;
    for (const auto& match : goodMatches) {
        points1.push_back(keypoints1[match.queryIdx].pt);
        points2.push_back(keypoints2[match.trainIdx].pt);
    }

    // Find homography with RANSAC and also retrieve the inlier mask
    std::vector<char> inliersMask(points1.size());
    cv::Mat H = cv::findHomography(points1, points2, cv::RANSAC, 3, inliersMask);

    int inliersCount = cv::countNonZero(inliersMask); // Count the number of inliers
    bool isGood = !H.empty() && inliersCount >= someInliersThreshold;

    std::cout << "Homography is " << (isGood ? "valid" : "not valid") << " with " << inliersCount << " inliers." << std::endl;

    // Return the homography matrix H if it's good, otherwise an empty cv::Mat
    return isGood ? H : cv::Mat();
}

// Function to process matching features with different algos
cv::Mat processMatching(const std::vector<cv::KeyPoint>& targetKeypoints,
    const cv::Mat& targetDescriptors,
    const std::vector<cv::KeyPoint>& frameKeypoints,
    const cv::Mat& frameDescriptors,
    FeatureType currentFeatureType,
    int minGoodMatches) {
    auto matches = matchFeatures(targetDescriptors, frameDescriptors, currentFeatureType);

    cv::Mat H = isGoodMatch(targetKeypoints, frameKeypoints, matches, minGoodMatches);
    if (!H.empty()) {
        // If H is not empty, a significant match was found and a valid homography was computed
        std::string featureTypeName;
        switch (currentFeatureType) {
        case FeatureType::ORB: featureTypeName = "ORB"; break;
        case FeatureType::SIFT: featureTypeName = "SIFT"; break;
        case FeatureType::KAZE: featureTypeName = "KAZE"; break;
        case FeatureType::AKAZE: featureTypeName = "AKAZE"; break;
            // Add other cases as needed
        default: featureTypeName = "Unknown"; break;
        }
        std::cout << "Significant match found using " << featureTypeName << "." << std::endl;
        return H; // Return the valid homography matrix
    }
    return cv::Mat(); // Return an empty matrix to indicate failure
}

/*

// Assume 'matches', 'targetKeypoints', and 'frameKeypoints' are provided from 'feature_matching.cpp'
std::vector<cv::DMatch> matches; // This should be filled with the matches found in the current frame
std::vector<cv::KeyPoint> targetKeypoints, frameKeypoints
*/