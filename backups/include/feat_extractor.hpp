//#ifndef FEAT_EXTRACTOR_HPP
//#define FEAT_EXTRACTOR_HPP
//
//#include <opencv2/opencv.hpp>
//#include <opencv2/features2d.hpp> // For KAZE
//
//// Feature type identifier
//enum class FeatureType { ORB, SIFT, KAZE, BRISK, AKAZE };
//
//// Define a threshold for the minimum number of inliers
//const int someInliersThreshold = 10; // Example value, adjust as needed
//
//// Forward declarations
//std::vector<cv::DMatch> matchFeatures(const cv::Mat& descriptors1, const cv::Mat& descriptors2, FeatureType type);
//bool isGoodMatch(const std::vector<cv::KeyPoint>& keypoints1,
//    const std::vector<cv::KeyPoint>& keypoints2,
//    const std::vector<cv::DMatch>& matches,
//    int someMinimumMatches);
//
//class FeatureExtractor {
//public:
//    FeatureExtractor(FeatureType type = FeatureType::ORB, int maxFeatures = 300) : type(type) {
//        switch (type) {
//        case FeatureType::ORB:
//            detector = cv::ORB::create(maxFeatures);
//            break;
//        case FeatureType::SIFT:
//            detector = cv::SIFT::create(maxFeatures);
//            break;
//        case FeatureType::KAZE:
//            detector = cv::KAZE::create(); // KAZE doesn't have a maxFeatures parameter in its create method
//            break;
//        case FeatureType::BRISK:
//            detector = cv::BRISK::create();
//            break;
//        case FeatureType::AKAZE:
//            detector = cv::AKAZE::create();
//            break;
//        default:
//            throw std::runtime_error("Unsupported feature type");
//        }
//    }
//
//    void detectAndCompute(const cv::Mat& image, std::vector<cv::KeyPoint>& keypoints, cv::Mat& descriptors) {
//        detector->detectAndCompute(image, cv::noArray(), keypoints, descriptors);
//        // Log information about the detection
//        logDetectionInfo(keypoints);
//    }
//
//    FeatureType getType() const {
//        return type;
//    }
//
//private:
//    cv::Ptr<cv::Feature2D> detector;
//    FeatureType type;
//
//    void logDetectionInfo(const std::vector<cv::KeyPoint>& keypoints) const {
//        std::string typeName;
//        switch (type) {
//        case FeatureType::ORB:
//            typeName = "ORB";
//            break;
//        case FeatureType::SIFT:
//            typeName = "SIFT";
//            break;
//        case FeatureType::KAZE:
//            typeName = "KAZE";
//            break;
//        case FeatureType::BRISK:
//            typeName = "BRISK";
//            break;
//        case FeatureType::AKAZE:
//            typeName = "AKAZE";
//            break;
//        }
//        std::cout << typeName << " detected " << keypoints.size() << " keypoints." << std::endl;
//    }
//};
//
//#endif // FEAT_EXTRACTOR_HPP