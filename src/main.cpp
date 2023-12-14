#include <chrono>
#include <thread>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <assimp/Importer.hpp>
#include <assimp/version.h>
#include <cstdlib>

// Inner Imports from Source
#include "feature_extraction.hpp"
#include "camCalibration.hpp"
#include "planar_pose_estimation.hpp"

// Forward Declarations
void qtGui(int argc, char* argv[]); // GUI function

// Instance definition - Pose vector carrier
PoseData poseData;

int main(int argc, char* argv[]) {
    // silentlly create conda env
    int condaenv = system("..\\..\\..\\..\\projection\\setup_env.bat");
    if (condaenv != 0) {
        std::cerr << " Failed to create env." << std::endl;
        return condaenv; // or handle the error as needed
    }

    // Load GUI
    std::cout << " ARi - Augmented Reality Inference GUI started\n" << std::endl;
    int guiPath = system("..\\..\\..\\..\\gui\\builds\\ARi_gui.bat");
    if (guiPath != 0) {
        std::cerr << " Failed to execute batch script." << std::endl;
        return guiPath; // or handle the error as needed
    } // small GUI pause
    std::this_thread::sleep_for(std::chrono::seconds(5));

    // Initiate defaults
    CalibrationConfig config;
    
    // Call the camera calibration function
    camCalibration(config); 

    // Load Calibration Data
    if (!loadCalibrationParameters("../../../../resources/calibration_params.csv")) {
        std::cerr << " Error loading calibration parameters." << std::endl;
        return 0;
    }

    // Call the feature extraction process with default parameters
    processImageAndVideo(
        defaultImagePath,
        defaultVideoPath,
        FeatureType::ORB,
        FeatureExtractor::defaultMaxFeatures,
        FeatureExtractor::defaultSkipRate,
        defaultProcessingFunction);

    // Call the projection script which uses the valid PoseData and calibration data (K, distortion)
    std::cout << " Executing Projection of the 3D Object" << std::endl;
    int result = system("..\\..\\..\\..\\projection\\project.bat");
    if (result != 0) {
        std::cerr << " Failed to execute batch script." << std::endl;
        return result; // or handle the error as needed
    }
    // Countdown before closing
    std::cout << "\n Auto-closing console in 10 seconds\n";
    for (int i = 10; i > 0; --i) {
        std::cout << i << "...\n ";
        std::fflush(stdout);  // Ensure the output is printed immediately
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "\n";

    exit(0);  // Exit the program
}

// Standby GUI function for future dev
// This was planned to run the whole Qt GUI
void qtGui(int argc, char* argv[]) {
    /*// GUI implementation
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    app.exec(); */
}