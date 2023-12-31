#pragma once
#ifndef HEADERS
#define HEADERS

#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>
#include <filesystem>
#include <iostream>
#include <sstream>
#include <vector>

// data types used in code
using dataImageType = std::vector<std::string>;
using smallNumPos = unsigned short;
using string = std::string;
using imageType = cv::Mat;

// data types used in calibration
using twoD = std::vector<std::vector<cv::Point2f>>;
using threeD = std::vector<std::vector<cv::Point3f>>;
using iSize = cv::Size;


// functions for camera
string take_pictures(string folder, smallNumPos camera = 0, smallNumPos numPictures = 1, bool save = false);

// functions for extracting features
cv::Mat feature_detection(std::string capImage);
int find_object(imageType keyPoints);
int feature_detection_main();

#endif // !HEADERS




