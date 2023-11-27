#ifndef PLANAR_POSE_ESTIMATION_HPP
#define PLANAR_POSE_ESTIMATION_HPP

#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp> // For access to feature detectors and descript
#include <vector>
#include <string>
#include <iostream>
#include "feature_matching.hpp"

void estimatePlanarPose(const cv::Mat& cameraMatrix,
    const std::vector<cv::KeyPoint>& targetKeypoints,
    const cv::Mat& targetDescriptors,
    const std::vector<cv::KeyPoint>& frameKeypoints,
    const cv::Mat& frameDescriptors,
    FeatureType currentFeatureType,
    int minGoodMatches); // Function declaration
bool loadCalibrationParameters(const std::string& filename, cv::Mat& cameraMatrix, cv::Mat& distCoeffs);
bool computePoseFromHomography(const cv::Mat& H, const cv::Mat& cameraMatrix, cv::Mat& pose);

#endif // PLANAR_POSE_ESTIMATION_HPP