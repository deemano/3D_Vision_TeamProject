#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Countdown.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow* ui;
    Countdown* countdown;
};
#endif // MAINWINDOW_H





//#ifndef MAINWINDOW_H
//#define MAINWINDOW_H
//
//#include <QMainWindow>
//#include <QFileDialog>
// #include "ui_mainwindow.h"
//
//#include "camCalibration.hpp"
//
//QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
//QT_END_NAMESPACE
//
//
//
//class MainWindow : public QMainWindow {
//    Q_OBJECT
//
//public:
//    MainWindow(QWidget* parent = nullptr);
//    ~MainWindow();
//
//private slots:
//    void on_saveConfigurationButton_clicked(); // Slot for handling button click
//
//private:
//    Ui::MainWindow* ui;
//
//    // Add other private members if necessary
//};
//
//#endif // MAINWINDOW_H
