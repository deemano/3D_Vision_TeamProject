#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    countdown = new Countdown(); // Initialize the Countdown object

    // Set up connections between UI elements and the countdown object
    connect(ui->startButton, &QPushButton::clicked, countdown, &Countdown::startCountdown);
    connect(ui->stopButton, &QPushButton::clicked, countdown, &Countdown::stopCountdown);
    connect(countdown, &Countdown::updateCountdown, this, [this](int value) {
        ui->countdownLabel->setText(QString::number(value));
        });
}

MainWindow::~MainWindow() {
    delete countdown;  // Clean up the countdown object
    delete ui;         // Clean up the UI
}



//#include "mainwindow.h"
//
///*
//This could include:
//Setting up signal-slot connections for the UI elements.
//Initializing member variables.
//Loading data into widgets (like filling a table or list).
//Configuring widget properties that were not set in Qt Designer.
//Anything else needed to initialize the state of your main window.
//*/
//
//MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
//    ui->setupUi(this);
//
//    // Connect the save configuration button click signal to the appropriate slot
//    connect(ui->pushButton_SAVE_Calib, &QPushButton::clicked, this, &MainWindow::on_saveConfigurationButton_clicked);
//    // Ensure that 'saveConfigurationButton' matches the object name of your button in Qt Designer
//}
//
//MainWindow::~MainWindow() {
//    delete ui;
//}
//
//// Slot implementation
//void MainWindow::on_saveConfigurationButton_clicked() {
//    CalibrationConfig config;
//
//    // Update patternType based on the selected radio button
//    if (ui->radioButton_Checkerboard->isChecked()) {
//        config.patternType = CalibrationConfig::CHECKERBOARD;
//        config.boardSize = cv::Size(ui->spinBox_checkerInners_1->value(), ui->spinBox_checkerInners_2->value());
//    }
//    else if (ui->radioButton_Charuco->isChecked()) {
//        config.patternType = CalibrationConfig::CHARUCO;
//        // Set Charuco specific sizes here...
//    } // Repeat for other patterns
//
//    // Set whether to use the default dataset
//    config.useDefaultDataset = ui->checkBox->isChecked();
//
//    // Update the save path based on the user's choice
//    if (ui->radioButton_DefaultLoc_SaveCalibResults->isChecked()) {
//        config.useDefaultSaveLocation = true;
//    }
//    else {
//        // Use a QFileDialog to let the user choose a save directory
//        QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
//            "/home",
//            QFileDialog::ShowDirsOnly
//            | QFileDialog::DontResolveSymlinks);
//        config.customSavePath = dir;
//        config.useDefaultSaveLocation = false;
//    }
//
//    // Set whether to show results
//    config.showResults = ui->checkBox_ShowResults->isChecked();
//
//    // Now pass this config to the calibration function
//    camCalibration(config);
//}



// ... Other MainWindow member function implementations ...

