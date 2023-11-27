#include "feature_extraction.hpp"

// Threshold for the minimum number of inliers
const int someInliersThreshold = 10; // Very important for projection

// Constructor of the FeatureExtractor class
FeatureExtractor::FeatureExtractor(FeatureType type, int maxFeatures) : type(type) {
    switch (type) { 
    // Depending on the FeatureType, initialize the appropriate feature detector
    case FeatureType::ORB:              // Initialize ORB detector with max # of features
        detector = cv::ORB::create(maxFeatures);
        break;
    case FeatureType::SIFT:             // Initialize SIFT detector
        detector = cv::SIFT::create(maxFeatures);
        break;
    case FeatureType::KAZE: 
        detector = cv::KAZE::create();  // KAZE initialization (does not use maxFeatures)
        break;
    case FeatureType::BRISK:            // Initialize BRISK detector
        detector = cv::BRISK::create();
        break;
    case FeatureType::AKAZE:            // Initialize AKAZE detector
        detector = cv::AKAZE::create();
        break;
    default: 
        // Throw error if an unsupported feature type detected
        throw std::runtime_error(" Unsupported feature type");
    }
}

// Method to detect & compute keypoints & descriptors from image
void FeatureExtractor::detectAndCompute(const cv::Mat& image, std::vector<cv::KeyPoint>& keypoints, cv::Mat& descriptors) {
    // Execute feature detection & descriptor extraction
    detector->detectAndCompute(image, cv::noArray(), keypoints, descriptors);
    logDetectionInfo(keypoints); // Log information about the detection process
}

// Getter method to retrieve the feature type of the extractor
FeatureType FeatureExtractor::getType() const {
    return type;
}

// Private method to log information about the detected keypoints
void FeatureExtractor::logDetectionInfo(const std::vector<cv::KeyPoint>& keypoints) const {
    // Determine the name of the feature type for logging
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
    } // Output the number of keypoints detected to the console
    std::cout << " " << typeName << " detected " << keypoints.size() << " keypoints." << std::endl;
}

// Function to process an image and a video for feature extraction
void processImageAndVideo(const std::string& imagePath, 
    const std::string& videoPath, FeatureType featureType, 
    int maxFeatures, int skipRate, 
    std::function<void(const std::vector<cv::KeyPoint>&, 
        const cv::Mat&, const std::vector<cv::KeyPoint>&, 
        const cv::Mat&)> processFunction) {
    // Load the target image
    cv::Mat targetImage = cv::imread(imagePath, cv::IMREAD_GRAYSCALE);
    if (targetImage.empty()) {
        std::cerr << " Could not read the target image." << std::endl;
        return;
    }

    // Resize the target image if its width is greater than 1500 pixels
    /*if (targetImage.cols > 1500) {
        double scale = 3.0 / 4.0;
        cv::resize(targetImage, targetImage, cv::Size(), scale, scale, cv::INTER_AREA);
    } */

    // Initialize feature extractor for both ORB and SIFT
    // Initialize appropriate feature extractor based on featureType
    FeatureExtractor orbExtractor(FeatureType::ORB, maxFeatures);
    FeatureExtractor siftExtractor(FeatureType::SIFT, maxFeatures);
    FeatureExtractor kazeExtractor(FeatureType::KAZE, maxFeatures);
    FeatureExtractor briskExtractor(FeatureType::BRISK, maxFeatures);
    FeatureExtractor akazeExtractor(FeatureType::AKAZE, maxFeatures);

    // Extract features from the target image
    std::vector<cv::KeyPoint> targetKeypoints;
    cv::Mat targetDescriptors;
    switch (featureType) {
    case FeatureType::ORB:
        orbExtractor.detectAndCompute(targetImage, targetKeypoints, targetDescriptors);
        break;
    case FeatureType::SIFT:
        siftExtractor.detectAndCompute(targetImage, targetKeypoints, targetDescriptors);
        break;
    case FeatureType::KAZE:
        kazeExtractor.detectAndCompute(targetImage, targetKeypoints, targetDescriptors);
        break;
    case FeatureType::BRISK:
        briskExtractor.detectAndCompute(targetImage, targetKeypoints, targetDescriptors);
        break;
    case FeatureType::AKAZE:
        akazeExtractor.detectAndCompute(targetImage, targetKeypoints, targetDescriptors);
        break;
    default:
        throw std::runtime_error(" Unsupported feature type");
    }

    // Open video
    cv::VideoCapture video(videoPath);
    if (!video.isOpened()) {
        std::cerr << " Could not open the video." << std::endl;
        return;
    }

    cv::Mat frame;
    int frameCounter = 0;
    while (video.read(frame)) {
        // Skip frames
        if (frameCounter % skipRate != 0) {
            frameCounter++;
            continue;
        }
        frameCounter++;

        // Process frame
        cv::resize(frame, frame, cv::Size(), 0.5, 0.5);
        cv::cvtColor(frame, frame, cv::COLOR_BGR2GRAY);

        // Extract features from the frame
        std::vector<cv::KeyPoint> frameKeypoints;
        cv::Mat frameDescriptors;
        switch (featureType) {
        case FeatureType::ORB:
            orbExtractor.detectAndCompute(frame, frameKeypoints, frameDescriptors);
            break;
        case FeatureType::SIFT:
            siftExtractor.detectAndCompute(frame, frameKeypoints, frameDescriptors);
            break;
        case FeatureType::KAZE:
            kazeExtractor.detectAndCompute(frame, frameKeypoints, frameDescriptors);
            break;
        case FeatureType::BRISK:
            briskExtractor.detectAndCompute(frame, frameKeypoints, frameDescriptors);
            break;
        case FeatureType::AKAZE:
            akazeExtractor.detectAndCompute(frame, frameKeypoints, frameDescriptors);
            break;
        default:
            throw std::runtime_error(" Unsupported feature type");
        }

        // Call the provided processing function
        processFunction(targetKeypoints, targetDescriptors, frameKeypoints, frameDescriptors);
    }
}