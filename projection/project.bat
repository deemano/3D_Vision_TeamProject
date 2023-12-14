@echo off

:: Check if Conda is installed
where conda >nul 2>&1
if %errorlevel% neq 0 (
    echo Conda is not installed or not in PATH.
    echo Please install Anaconda or Miniconda and add it to your PATH.
    exit /b 1
)

:: Attempt to activate the environment
echo Attempting to activate the Conda environment 'projector2'...
call conda activate projector2
if %errorlevel% neq 0 (
    echo Failed to activate Conda environment.
    exit /b %errorlevel%
)

:: Change directory four levels up and then to the 'projection' directory
cd ..\..\..\..\projection

:: Check if directory change was successful
if %errorlevel% neq 0 (
    echo Failed to change directory.
    exit /b %errorlevel%
)

echo Running Python script...
call python ar_main.py
if %errorlevel% neq 0 (
    echo Script encountered an error.
    exit /b %errorlevel%
)

echo Script finished.
pause
