@echo off
:: Check for administrative privileges
net session >nul 2>&1
if %errorlevel% neq 0 (
    echo Requesting administrative privileges...
    goto UACPrompt
) else (
    goto gotAdmin
)

:UACPrompt
    echo Set UAC = CreateObject^("Shell.Application"^) > "%temp%\getadmin.vbs"
    echo UAC.ShellExecute "%~s0", "", "", "runas", 1 >> "%temp%\getadmin.vbs"
    "%temp%\getadmin.vbs"
    exit /B

:gotAdmin
    if exist "%temp%\getadmin.vbs" ( del "%temp%\getadmin.vbs" )
    pushd "%CD%"
    CD /D "%~dp0"

:: Check if Conda is installed
where conda >nul 2>&1
if %errorlevel% neq 0 (
    echo Conda is not installed or not in PATH.
    echo Please install Anaconda or Miniconda and add it to your PATH.
    exit /b 1
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

:: Attempt to activate the environment
echo Attempting to activate the Conda environment 'projector2'...
call conda activate projector2
if %errorlevel% neq 0 (
    echo Environment 'projector2' does not exist. Creating it now...
    call :CreateEnv
    echo Environment created successfully.
    echo Activating the newly created environment...
    call conda activate projector2
    if %errorlevel% neq 0 (
        echo Failed to activate Conda environment.
        exit /b %errorlevel%
    )
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
