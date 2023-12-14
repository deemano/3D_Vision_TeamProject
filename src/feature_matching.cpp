#include "feature_matching.hpp"
#include "feature_extraction.hpp" // For FeatureType enum
#include "planar_pose_estimation.hpp"

// Extent vector for local use
extern PoseData poseData;

// Initialize a matcher based on the feature type
cv::Ptr<cv::DescriptorMatcher> createMatcher(FeatureType type) {
    switch (type) {
    case FeatureType::ORB:
        return cv::DescriptorMatcher::create(cv::DescriptorMatcher::BRUTEFORCE_HAMMING);
    case FeatureType::SIFT:
    case FeatureType::KAZE:
    case FeatureType::AKAZE:
        return cv::DescriptorMatcher::create(cv::DescriptorMatcher::FLANNBASED);
    default:
        throw std::runtime_error(" Unsupported feature type for matcher creation");
    }
}
// Function to match features between two sets of descriptors using specific feature types like ORB, SIFT, etc.
std::vector<cv::DMatch> matchFeatures(const cv::Mat& descriptors1, const cv::Mat& descriptors2, FeatureType type) {
    std::vector<cv::DMatch> goodMatches;
    auto matcher = createMatcher(type); // Create a matcher based on the feature type

    // Matching process varies based on feature type
    if (type == FeatureType::ORB) { // Convert descriptors to float type if they are not already
        matcher->match(descriptors1, descriptors2, goodMatches);
    }
    else { // SIFT, KAZE, AKAZE
        cv::Mat descriptors1Float = descriptors1.type() != CV_32F ? descriptors1.clone() : descriptors1;
        cv::Mat descriptors2Float = descriptors2.type() != CV_32F ? descriptors2.clone() : descriptors2;

        std::vector<std::vector<cv::DMatch>> knnMatches;
        // Perform knn matching with k=2 (finds the two nearest neighbors)
        matcher->knnMatch(descriptors1Float, descriptors2Float, knnMatches, 2);

        const float ratioThresh = 0.75f;  // Ratio threshold for filtering matches
        for (const auto& m : knnMatches) {
            // Apply Lowe's ratio test to filter out weak matches
            if (m[0].distance < ratioThresh * m[1].distance) {
                goodMatches.push_back(m[0]);
            }
        }
    }
    // Return the filtered, good matches
    return goodMatches;
}
// Function to compute and validate homography based on matched keypoints
cv::Mat computeAndValidateHomography(const std::vector<cv::KeyPoint>& keypoints1,
    const std::vector<cv::KeyPoint>& keypoints2,
    const std::vector<cv::DMatch>& goodMatches,
    int minGoodMatches,
    double ransacReprojThreshold) {
    // Check if the number of good matches is sufficient
    if (goodMatches.size() < minGoodMatches) {
        std::cout << " Insufficient matches: " << goodMatches.size() << std::endl;
        return cv::Mat(); // Return an empty matrix if not enough matches
    }
    // Extract the matched points from the keypoints
    std::vector<cv::Point2f> points1, points2;
    for (const auto& match : goodMatches) {
        points1.push_back(keypoints1[match.queryIdx].pt);
        points2.push_back(keypoints2[match.trainIdx].pt);
    }
    // Compute homography using RANSAC
    std::vector<char> inliersMask; // Mask to store inliers after RANSAC
    cv::Mat H = cv::findHomography(points1, points2, cv::RANSAC, ransacReprojThreshold, inliersMask);
    int inliersCount = cv::countNonZero(inliersMask);
    bool isGood = !H.empty() && inliersCount >= minGoodMatches;
    // Output the status of the homography computation
    std::cout << " Homography " << (isGood ? "valid" : "invalid") << " with " << inliersCount << " inliers." << std::endl;
    return isGood ? H : cv::Mat(); // Return the homography if valid, otherwise return an empty matrix
}

// Processes a single frame for feature matching, homography computation, and pose estimation.
cv::Mat processMatching(const std::vector<cv::KeyPoint>& targetKeypoints,
    const cv::Mat& targetDescriptors,
    const std::vector<cv::KeyPoint>& frameKeypoints,
    const cv::Mat& frameDescriptors,
    FeatureType currentFeatureType,
    int minGoodMatches, double ransacReprojThreshold) {
    //PoseData poseData;
    // Log the start of the feature matching process
    std::cout << " Matching features between target image and video frame..." << std::endl;

    // Perform feature matching between the target descriptors and frame descriptors
    auto matches = matchFeatures(targetDescriptors, frameDescriptors, currentFeatureType);
    std::cout << " Number of raw matches found: " << matches.size() << std::endl;

    // Compute and validate the homography matrix based on the matches
    cv::Mat H = computeAndValidateHomography(targetKeypoints, frameKeypoints, matches, minGoodMatches, ransacReprojThreshold);

    if (!H.empty()) {
        // Initialize a PoseData structure to hold the results of pose estimation


        // Attempt to estimate the pose based on the homography matrix
        if (estimatePose(H, poseData)) {
            // Process the poseData or store it for later use
            // ...
        }
        else {
            std::cerr << " Pose estimation failed." << std::endl;
        } // Log the successful computation of a significant match
        std::cout << " Significant match found using " << featureTypeToString(currentFeatureType)
            << " with " << matches.size() << " good matches." << std::endl;
        return H;
    }
    else { // Log a failure to find a significant match
        std::cout << " Failed to find a significant match using " << featureTypeToString(currentFeatureType) << std::endl;
    } 
    // Return the computed homography matrix, or an empty matrix if no valid homography was found
    return H; //cv::Mat();
}