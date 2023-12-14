// This header file is dormant now
// Standby for GUI or others
// #ifndef COMMON_H
#define COMMON_H

// For Qt:
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QApplication>
#include <QMainWindow>
#include <QThread>
#include <QDebug>
//#include <QMediaPlayer>
//#include <QVideoWidget>
#include <QtConcurrent/QtConcurrent>
#include <QTimer>
#include <QPushButton>
#include <QIcon>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <QLabel>

//#include <QCamera>
//#include <QMediaDevices>
#include <QComboBox>
//#include <QVideoSink>
#include <QImage>
#include <QPixmap>
//#include <QMediaCaptureSession>
#include <QWidget>
#include <QGroupBox>
#include <QRadioButton>
#include <QString>
#include <QFileDialog>
#include <QObject>
#include <QMetaType>

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
#include "stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GL/glew.h> // For OpenGL types and functions
#include <string>

// Global Variables
float lastX = 400, lastY = 300; // Initial mouse position, assuming a window size of 800x600
float yaw = -90.0f, pitch = 0.0f; // Initial angles
bool firstMouse = true;

// Camera settings
glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);


// Forward definitions
bool loadCameraCalibration(const std::string& filename, cv::Mat& cameraMatrix, cv::Mat& distCoeffs);

#endif // COMMON_H