@echo off
echo Starting augmentedReality.exe...

:: Change the directory to where the executable is located
cd out\build_backup\x64-Debug\Debug

:: Check if the executable exists
if not exist "augmentedReality.exe" (
    echo augmentedReality.exe not found.
    exit /b 1
)

:: Run the executable
augmentedReality.exe

echo augmentedReality.exe has been started.
pause