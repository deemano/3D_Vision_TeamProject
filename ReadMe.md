# Project Title: 3D_Vision_TeamProject

## ===================================

## Description: Execute camera calibration, feature extraction and description, 
feature matching and filterings, homography, planar pose estimation 
and 3D object projection with results displayed.

### Run
The program can be run by double-click on the augmentedReality.exe (shortcut)
The folder has a Debug executable left for tests. 

### Installation:
1. Download this repo and extract;

2. double-click to run "runMe_toSetup_OpenCV.bat" file. This will automatically download all the dependencies and extract them in their right folders;
   This step includes automatically setting up the OpenCV and Eigen3 libraries.

3. open Visual Studio > File > Open Folder > navigate to the project main folder and click Select Folder button; 		
   This will automatically generate the entire project via CMakeLists.txt, link dependencies and set up paths;

4. In Visual Studio go to Build > Build All. This will build the whole project.
   After this last point, you can run from Solution Explorer tab the main.cpp script and make any modifications neccesary.
   The entire project structure should be accesable via VS Solution Explorer.

5. All .cpp files should be in the /src folder and all hpp files should be in /include folder. 
   GUI folder containes Qt C++ scripts and files.
   Projection folder contains the scripts that generate the 3D object projection. 
These are separate because it embeds python with C++ and Windows .bat file connections.	
   All are connected to main.cpp.


Happy new year!!!

### Usage: Coursework - proof of concept and implementation experimentations.

### Credits: Denis Manolescu, Bryan Mutinda, Harrison Liddell
Contributing: Denis Manolescu, Bryan Mutinda, Harrison Liddell

### *italic*Developed for 3D Vision coursework @Prof Dr Pedro Cavestany

License: LHU 2023-2024