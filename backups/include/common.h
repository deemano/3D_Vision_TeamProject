#ifndef COMMON_H
#define COMMON_H

// Include all header structure:
#include "camera_calibration.hpp"
#include "feature_extraction.hpp"
#include "feature_matching.hpp"
#include "ransac.hpp"
#include "object_integration.hpp"
#include "other.hpp"
#include "feat_extractor.hpp"
#include "planar_pose_estimation.hpp"

// Include other dependencies
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/utils/logger.hpp>
#include <Eigen/Core>
#include <vector>
#include <cstdlib> // For system()
#include <chrono>
#include <thread>

#endif // COMMON_H