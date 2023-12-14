# Project Title: 3D_Vision_TeamProject

## 


### DONE

Project Overview
The 3D Vision Team successfully completed a comprehensive augmented reality (AR) project focusing on integrating 3D objects into a live video stream. This project was divided into several key stages, each contributing to the creation of a dynamic and interactive AR experience.

Completed Tasks:
1. Camera Calibration:
We successfully calibrated the camera using chessboard images and OpenCV's findChessboardCorners and calibrateCamera functions. This process corrected lens distortion and improved the accuracy of our 3D object integration.

2. Feature Extraction and Description:
Our team effectively identified and extracted distinctive features in images, employing algorithms like SIFT, SURF, or ORB. This allowed us to accurately track objects within the video frames.

3. Feature Matching:
We matched features between the video frames and predefined tokens using the BFMatcher and FLANN methods. This was crucial for aligning the 3D objects with the real-world environment in the video stream.

4. RANSAC - Homography Computation:
The RANSAC algorithm was used to estimate the homography matrix, crucial for addressing perspective distortion. We utilized OpenCV's findHomography method with RANSAC, enhancing the realism of the AR experience.

5. Planar Pose Estimation:
The pose of the plane in the scene was computed using the homography matrix. We extracted the rotation and translation vectors, using the solvePnP function, which allowed for precise positioning of 3D objects in the scene.

6. 3D Object Integration:
Our team adeptly rendered 3D objects onto the video stream, transforming the 3D coordinates of virtual objects to align with the pose of the physical tokens. This step was pivotal in creating a seamless AR experience.

7. Display: 
The 3D projection is shown visually at the end of the program

8. Add Extras
   Creation of an app (GUI added just not fully linked).
   Different Feature Extraction Algorithms ORB, SIFT, KAZE, AKAZE are implemented - user can teste tem all.
   


Deadline: 13th December 2023.