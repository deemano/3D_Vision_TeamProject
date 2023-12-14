@echo off

:: Change directory four levels up and then to the 'projection' directory
cd ..\..\..\..\projection

:: Check if Conda is installed
where conda >nul 2>&1
if %errorlevel% neq 0 (
    echo Conda is not installed or not in PATH.
    echo Please install Anaconda or Miniconda and add it to your PATH.
    exit /b 1
)

:: Check if environment 'projector2' already exists
call conda info --envs | findstr "projector2"
if %errorlevel% equ 0 (
    echo Environment 'projector2' already exists.
    exit /b 0
)

:: Function to create Conda environment
:CreateEnv
echo Attempting to create environment 'projector2'...
call conda env create -f projector.yml
if %errorlevel% neq 0 (
    echo Failed to create Conda environment. Retry in 5 seconds...
    timeout /t 5 /nobreak
    goto :CreateEnv
)

echo Environment 'projector2' created successfully.
exit /b 0
