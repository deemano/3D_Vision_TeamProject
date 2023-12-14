#include "feature_extraction.hpp"
#include "feature_matching.hpp"
#include "planar_pose_estimation.hpp"

// Extent vector for local use
extern PoseData poseData;

// Constructor of the FeatureExtractor class
FeatureExtractor::FeatureExtractor(FeatureType type, int maxFeatures) : type(type) {
    std::cout << " Initializing Feature Extractor with type: " << featureTypeToString(type) << std::endl;
    switch (type) {
        // Depending on the FeatureType, initialize the appropriate feature detector
    case FeatureType::ORB:
        detector = cv::ORB::create(maxFeatures);
        break;
    case FeatureType::SIFT:
        detector = cv::SIFT::create(maxFeatures);
        break;
    case FeatureType::KAZE:
        detector = cv::KAZE::create();
        break;
    case FeatureType::BRISK:
        detector = cv::BRISK::create();
        break;
    case FeatureType::AKAZE:
        detector = cv::AKAZE::create();
        break;
    default:
        throw std::runtime_error(" Unsupported feature type");
    }
}
// Function to handle basic processing of each frame
void defaultProcessingFunction(cv::Mat& frame,
    const std::vector<cv::KeyPoint>& targetKeypoints,
    const cv::Mat& targetDescriptors,
    const std::vector<cv::KeyPoint>& frameKeypoints,
    const cv::Mat& frameDescriptors,
    FeatureType featureType) {
    // Perform feature matching
    std::cout << " Performing feature matching..." << std::endl;
    auto matches = matchFeatures(targetDescriptors, frameDescriptors, featureType);
    auto homography = processMatching(targetKeypoints,
            targetDescriptors,
            frameKeypoints,
            frameDescriptors,
            featureType,
            FeatureExtractor::defaultInliersThreshold);

    // Now, you can further process the frame based on the homography results
    // For example, draw keypoints, etc.
    if (!homography.empty()) {
        // Draw keypoints, or do further processing here
        std::cout << " Homography found with " << matches.size() << " matches." << std::endl;
    }
}

// Helper function to convert string to FeatureType
std::string featureTypeToString(FeatureType type) {
    switch (type) {
    case FeatureType::ORB:   return "ORB";
    case FeatureType::SIFT:  return "SIFT";
    case FeatureType::KAZE:  return "KAZE";
    case FeatureType::BRISK: return "BRISK";
    case FeatureType::AKAZE: return "AKAZE";
    default:                 return "Unknown";
    }
}

// Method to detect & compute keypoints & descriptors from image
void FeatureExtractor::detectAndCompute(const cv::Mat& image, std::vector<cv::KeyPoint>& keypoints, cv::Mat& descriptors) {
    std::cout << " Detecting and computing features..." << std::endl; 
    detector->detectAndCompute(image, cv::noArray(), keypoints, descriptors);
    logDetectionInfo(keypoints);
}

// Getter method to retrieve the feature type of the extractor
FeatureType FeatureExtractor::getType() const {
    return type;
}

// Private method to log information about the detected keypoints
void FeatureExtractor::logDetectionInfo(const std::vector<cv::KeyPoint>& keypoints) const {
    std::cout << " Detected " << keypoints.size() << " keypoints using " << featureTypeToString(type) << std::endl;
    std::string typeName;
    switch (type) {
    case FeatureType::ORB:
        typeName = "ORB";
        break;
    case FeatureType::SIFT:
        typeName = "SIFT";
        break;
    case FeatureType::KAZE:
        typeName = "KAZE";
        break;
    case FeatureType::BRISK:
        typeName = "BRISK";
        break;
    case FeatureType::AKAZE:
        typeName = "AKAZE";
        break;
    default:
        typeName = "Unknown";
    }
    std::cout << " " << typeName << " detected " << keypoints.size() << " keypoints." << std::endl;
}
// Function to process an image and a video for feature extraction
void processImageAndVideo(
    const std::string& imagePath,  // Path to the target image for feature extraction
    const std::string& videoPath,  // Path to the video for feature extraction
    FeatureType featureType,       // Type of feature extractor to use (e.g., ORB, SIFT)
    int maxFeatures,               // Maximum number of features to detect
    int skipRate,                  // Number of frames to skip in the video processing
    void (*processFunction)(cv::Mat&, const std::vector<cv::KeyPoint>&, const cv::Mat&,
        const std::vector<cv::KeyPoint>&, const cv::Mat&, FeatureType)) {

    std::cout << " Starting feature extraction process..." << std::endl;
    // Function to process each frame of the video, taking both target and frame features
    // Initialize the feature extractor with the specified type and maximum number of features
    FeatureExtractor extractor(featureType, maxFeatures);

    // Load the target image in grayscale for feature detection
    std::cout << " Loading target image..." << std::endl;
    cv::Mat targetImage = cv::imread(imagePath, cv::IMREAD_GRAYSCALE);
    if (targetImage.empty()) {
        std::cerr << " Failed to load a target image." << std::endl;
        return;  // Exit if the target image cannot be loaded
    }

    // Detect keypoints and compute descriptors for the target image
    std::vector<cv::KeyPoint> targetKeypoints;
    cv::Mat targetDescriptors;
    extractor.detectAndCompute(targetImage, targetKeypoints, targetDescriptors);

    // Open the video file for processing
    std::cout << " Opening video file..." << std::endl;
    cv::VideoCapture video(videoPath);
    if (!video.isOpened()) {
        std::cerr << " Failed to open video file." << std::endl;
        return;  // Exit if the video cannot be opened
    }

    // Process each frame of the video
    cv::Mat frame;  // Current frame of the video
    int frameCounter = 0;  // Frame counter to manage skipping frames
    std::cout << " Processing video frames..." << std::endl;
    while (video.read(frame)) {
        // Skip frames according to the specified skip rate
        if (frameCounter % skipRate != 0) {
            frameCounter++;
            continue;  // Skip this frame
        }
        std::cout << " Processing frame " << frameCounter << std::endl;
        frameCounter++;

        // Resize frame to increase speed
        cv::resize(frame, frame, cv::Size(), 0.7, 0.7);

        // Detect keypoints and compute descriptors for the current frame
        std::vector<cv::KeyPoint> frameKeypoints;
        cv::Mat frameDescriptors;

        // Pipeline execution
        extractor.detectAndCompute(frame, frameKeypoints, frameDescriptors);

        // Call the provided processing function for the frame
        processFunction(frame, targetKeypoints, targetDescriptors, frameKeypoints, frameDescriptors, featureType);
    }
    std::cout << " Feature extraction process completed." << std::endl;

    // Once all frames are processed, you can save the pose data
    savePoseMatrixToFile("poseMatrices.csv", poseData.poseMatrices);
}

