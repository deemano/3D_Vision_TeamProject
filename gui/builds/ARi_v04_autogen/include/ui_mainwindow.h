/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox_2;
    QComboBox *comboBox_camerasDropdown;
    QGroupBox *groupBox_3;
    QWidget *videoPlaceholder;
    QWidget *tab_2;
    QGroupBox *groupBox_Type_section;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_Checkerboard;
    QRadioButton *radioButton_Charuco;
    QRadioButton *radioButton_symDots;
    QRadioButton *radioButton_assymDots;
    QGroupBox *groupBox_InnersChecker;
    QLabel *label;
    QSpinBox *spinBox_checkerInners_1;
    QSpinBox *spinBox_checkerInners_2;
    QGroupBox *groupBox_InnersCharuco;
    QLabel *label_5;
    QSpinBox *spinBox_charucorInners_1;
    QSpinBox *spinBox_charucorInners_2;
    QGroupBox *groupBox_InputData_leftPanel;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_forDefault_inData;
    QCheckBox *checkBox;
    QGroupBox *groupBox_Save_calibResults;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton_DefaultLoc_SaveCalibResults;
    QGroupBox *groupBox_PathSaveCalibResults;
    QToolButton *toolButton_Path_SaveCalibResults;
    QGroupBox *groupBox_InputData_rightPanel;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox_ForSetPath;
    QToolButton *toolButton_Path_setFolder;
    QGroupBox *groupBox__forTakePics_inData;
    QPushButton *pushButton_CameraWindow;
    QLabel *label_6;
    QGroupBox *groupBox_ViewResults;
    QLabel *label_7;
    QCheckBox *checkBox_ShowResults;
    QPushButton *pushButton_SAVE_Calib;
    QPushButton *pushButton_RESET_Calib;
    QWidget *tab_3;
    QGroupBox *groupBox_ExtractData;
    QGroupBox *groupBox_SetToken;
    QComboBox *comboBox_SelectToken_dropdown;
    QLabel *label_12;
    QLabel *label_13;
    QFrame *line_2;
    QToolButton *toolButton_ChooseURtoken;
    QGroupBox *groupBox_TargetVideo;
    QCheckBox *checkBox_Default_targetVideo;
    QGroupBox *groupBox_RecordVid_targetVid;
    QCheckBox *checkBox_recVid_targetVid;
    QPushButton *pushButton_targetVid_window;
    QGroupBox *groupBox_SetURown_targetVid;
    QCheckBox *checkBox_setURown_targetVid;
    QToolButton *toolButton_defineUR_targetVid;
    QPushButton *pushButton__RESET_Feature;
    QPushButton *pushButton_pushButton_SAVE_Feature;
    QGroupBox *groupBox_ExtractMatch;
    QGroupBox *groupBox_Extr_Match;
    QComboBox *comboBox_AlgoSelect_dropdown;
    QLabel *label_16;
    QLabel *label_18;
    QSpinBox *spinBox_SetNumFeature__dropdown;
    QLabel *label_17;
    QLabel *label_25;
    QLabel *label_26;
    QSpinBox *spinBox_InliersThreshold__dropdown;
    QGroupBox *groupBox_VidParamOthers;
    QSpinBox *spinBox_FrameSize_width;
    QLabel *label_21;
    QSpinBox *spinBox__FrameSize_heigth;
    QLabel *label_23;
    QLabel *label_22;
    QLabel *label_24;
    QLabel *label_10;
    QSpinBox *spinBox_skipFrame;
    QSpinBox *spinBox_FPS;
    QLabel *label_19;
    QLabel *label_20;
    QWidget *tab_5;
    QGroupBox *groupBox_13;
    QMdiArea *mdiArea_PlayVideoResult;
    QPushButton *pushButton_GenerateAR;
    QPushButton *pushButton_OpenVideoResult;
    QFrame *line;
    QProgressBar *progressBar;
    QLabel *label_27;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(1207, 630);
        MainWindow->setDocumentMode(false);
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 0, 1191, 571));
        tabWidget = new QTabWidget(groupBox);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 30, 1171, 531));
        tab = new QWidget();
        tab->setObjectName("tab");
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(20, 10, 191, 491));
        comboBox_camerasDropdown = new QComboBox(groupBox_2);
        comboBox_camerasDropdown->addItem(QString());
        comboBox_camerasDropdown->setObjectName("comboBox_camerasDropdown");
        comboBox_camerasDropdown->setGeometry(QRect(10, 30, 171, 24));
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(250, 10, 881, 491));
        videoPlaceholder = new QWidget(groupBox_3);
        videoPlaceholder->setObjectName("videoPlaceholder");
        videoPlaceholder->setEnabled(false);
        videoPlaceholder->setGeometry(QRect(19, 39, 771, 431));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        groupBox_Type_section = new QGroupBox(tab_2);
        groupBox_Type_section->setObjectName("groupBox_Type_section");
        groupBox_Type_section->setGeometry(QRect(10, 10, 1141, 101));
        horizontalLayoutWidget = new QWidget(groupBox_Type_section);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(9, 19, 1121, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_Checkerboard = new QRadioButton(horizontalLayoutWidget);
        radioButton_Checkerboard->setObjectName("radioButton_Checkerboard");

        horizontalLayout->addWidget(radioButton_Checkerboard);

        radioButton_Charuco = new QRadioButton(horizontalLayoutWidget);
        radioButton_Charuco->setObjectName("radioButton_Charuco");

        horizontalLayout->addWidget(radioButton_Charuco);

        radioButton_symDots = new QRadioButton(horizontalLayoutWidget);
        radioButton_symDots->setObjectName("radioButton_symDots");

        horizontalLayout->addWidget(radioButton_symDots);

        radioButton_assymDots = new QRadioButton(horizontalLayoutWidget);
        radioButton_assymDots->setObjectName("radioButton_assymDots");

        horizontalLayout->addWidget(radioButton_assymDots);

        radioButton_symDots->raise();
        radioButton_Checkerboard->raise();
        radioButton_assymDots->raise();
        radioButton_Charuco->raise();
        groupBox_InnersChecker = new QGroupBox(groupBox_Type_section);
        groupBox_InnersChecker->setObjectName("groupBox_InnersChecker");
        groupBox_InnersChecker->setEnabled(true);
        groupBox_InnersChecker->setGeometry(QRect(19, 50, 141, 51));
        QFont font;
        font.setPointSize(7);
        groupBox_InnersChecker->setFont(font);
        groupBox_InnersChecker->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        groupBox_InnersChecker->setFlat(false);
        groupBox_InnersChecker->setCheckable(false);
        label = new QLabel(groupBox_InnersChecker);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 23, 16, 16));
        QFont font1;
        font1.setPointSize(8);
        font1.setBold(true);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        spinBox_checkerInners_1 = new QSpinBox(groupBox_InnersChecker);
        spinBox_checkerInners_1->setObjectName("spinBox_checkerInners_1");
        spinBox_checkerInners_1->setGeometry(QRect(10, 20, 36, 23));
        spinBox_checkerInners_1->setWrapping(false);
        spinBox_checkerInners_1->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        spinBox_checkerInners_2 = new QSpinBox(groupBox_InnersChecker);
        spinBox_checkerInners_2->setObjectName("spinBox_checkerInners_2");
        spinBox_checkerInners_2->setGeometry(QRect(90, 20, 36, 23));
        spinBox_checkerInners_2->setWrapping(false);
        spinBox_checkerInners_2->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        groupBox_InnersCharuco = new QGroupBox(groupBox_Type_section);
        groupBox_InnersCharuco->setObjectName("groupBox_InnersCharuco");
        groupBox_InnersCharuco->setEnabled(true);
        groupBox_InnersCharuco->setGeometry(QRect(310, 50, 141, 51));
        groupBox_InnersCharuco->setFont(font);
        groupBox_InnersCharuco->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        groupBox_InnersCharuco->setFlat(false);
        groupBox_InnersCharuco->setCheckable(false);
        label_5 = new QLabel(groupBox_InnersCharuco);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(60, 23, 16, 16));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);
        spinBox_charucorInners_1 = new QSpinBox(groupBox_InnersCharuco);
        spinBox_charucorInners_1->setObjectName("spinBox_charucorInners_1");
        spinBox_charucorInners_1->setGeometry(QRect(10, 20, 36, 23));
        spinBox_charucorInners_1->setWrapping(false);
        spinBox_charucorInners_1->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        spinBox_charucorInners_2 = new QSpinBox(groupBox_InnersCharuco);
        spinBox_charucorInners_2->setObjectName("spinBox_charucorInners_2");
        spinBox_charucorInners_2->setGeometry(QRect(90, 20, 36, 23));
        spinBox_charucorInners_2->setWrapping(false);
        spinBox_charucorInners_2->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        groupBox_InputData_leftPanel = new QGroupBox(tab_2);
        groupBox_InputData_leftPanel->setObjectName("groupBox_InputData_leftPanel");
        groupBox_InputData_leftPanel->setEnabled(true);
        groupBox_InputData_leftPanel->setGeometry(QRect(10, 120, 531, 131));
        horizontalLayoutWidget_2 = new QWidget(groupBox_InputData_leftPanel);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(10, 30, 411, 71));
        horizontalLayout_forDefault_inData = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_forDefault_inData->setObjectName("horizontalLayout_forDefault_inData");
        horizontalLayout_forDefault_inData->setContentsMargins(0, 0, 0, 0);
        checkBox = new QCheckBox(horizontalLayoutWidget_2);
        checkBox->setObjectName("checkBox");

        horizontalLayout_forDefault_inData->addWidget(checkBox);

        groupBox_Save_calibResults = new QGroupBox(tab_2);
        groupBox_Save_calibResults->setObjectName("groupBox_Save_calibResults");
        groupBox_Save_calibResults->setGeometry(QRect(10, 270, 1141, 101));
        horizontalLayoutWidget_3 = new QWidget(groupBox_Save_calibResults);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(10, 20, 1121, 71));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        radioButton_DefaultLoc_SaveCalibResults = new QRadioButton(horizontalLayoutWidget_3);
        radioButton_DefaultLoc_SaveCalibResults->setObjectName("radioButton_DefaultLoc_SaveCalibResults");

        horizontalLayout_3->addWidget(radioButton_DefaultLoc_SaveCalibResults);

        groupBox_PathSaveCalibResults = new QGroupBox(horizontalLayoutWidget_3);
        groupBox_PathSaveCalibResults->setObjectName("groupBox_PathSaveCalibResults");
        toolButton_Path_SaveCalibResults = new QToolButton(groupBox_PathSaveCalibResults);
        toolButton_Path_SaveCalibResults->setObjectName("toolButton_Path_SaveCalibResults");
        toolButton_Path_SaveCalibResults->setGeometry(QRect(10, 30, 61, 23));

        horizontalLayout_3->addWidget(groupBox_PathSaveCalibResults);

        groupBox_InputData_rightPanel = new QGroupBox(tab_2);
        groupBox_InputData_rightPanel->setObjectName("groupBox_InputData_rightPanel");
        groupBox_InputData_rightPanel->setEnabled(true);
        groupBox_InputData_rightPanel->setGeometry(QRect(540, 120, 611, 131));
        groupBox_InputData_rightPanel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        horizontalLayoutWidget_5 = new QWidget(groupBox_InputData_rightPanel);
        horizontalLayoutWidget_5->setObjectName("horizontalLayoutWidget_5");
        horizontalLayoutWidget_5->setGeometry(QRect(10, 30, 591, 81));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        groupBox_ForSetPath = new QGroupBox(horizontalLayoutWidget_5);
        groupBox_ForSetPath->setObjectName("groupBox_ForSetPath");
        toolButton_Path_setFolder = new QToolButton(groupBox_ForSetPath);
        toolButton_Path_setFolder->setObjectName("toolButton_Path_setFolder");
        toolButton_Path_setFolder->setGeometry(QRect(10, 30, 61, 23));

        horizontalLayout_6->addWidget(groupBox_ForSetPath);

        groupBox__forTakePics_inData = new QGroupBox(horizontalLayoutWidget_5);
        groupBox__forTakePics_inData->setObjectName("groupBox__forTakePics_inData");
        groupBox__forTakePics_inData->setEnabled(true);
        pushButton_CameraWindow = new QPushButton(groupBox__forTakePics_inData);
        pushButton_CameraWindow->setObjectName("pushButton_CameraWindow");
        pushButton_CameraWindow->setGeometry(QRect(10, 30, 80, 24));

        horizontalLayout_6->addWidget(groupBox__forTakePics_inData);

        label_6 = new QLabel(tab_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 340, 291, 16));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(false);
        font2.setItalic(true);
        label_6->setFont(font2);
        label_6->setAlignment(Qt::AlignCenter);
        groupBox_ViewResults = new QGroupBox(tab_2);
        groupBox_ViewResults->setObjectName("groupBox_ViewResults");
        groupBox_ViewResults->setGeometry(QRect(10, 410, 581, 81));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 410, 431, 16));
        label_7->setFont(font2);
        label_7->setAlignment(Qt::AlignCenter);
        checkBox_ShowResults = new QCheckBox(tab_2);
        checkBox_ShowResults->setObjectName("checkBox_ShowResults");
        checkBox_ShowResults->setGeometry(QRect(10, 390, 409, 22));
        pushButton_SAVE_Calib = new QPushButton(tab_2);
        pushButton_SAVE_Calib->setObjectName("pushButton_SAVE_Calib");
        pushButton_SAVE_Calib->setGeometry(QRect(900, 430, 161, 51));
        QFont font3;
        font3.setPointSize(12);
        pushButton_SAVE_Calib->setFont(font3);
        pushButton_RESET_Calib = new QPushButton(tab_2);
        pushButton_RESET_Calib->setObjectName("pushButton_RESET_Calib");
        pushButton_RESET_Calib->setGeometry(QRect(710, 430, 161, 51));
        pushButton_RESET_Calib->setFont(font3);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        groupBox_ExtractData = new QGroupBox(tab_3);
        groupBox_ExtractData->setObjectName("groupBox_ExtractData");
        groupBox_ExtractData->setGeometry(QRect(10, 10, 1141, 211));
        groupBox_SetToken = new QGroupBox(groupBox_ExtractData);
        groupBox_SetToken->setObjectName("groupBox_SetToken");
        groupBox_SetToken->setGeometry(QRect(20, 30, 391, 161));
        comboBox_SelectToken_dropdown = new QComboBox(groupBox_SetToken);
        comboBox_SelectToken_dropdown->addItem(QString());
        comboBox_SelectToken_dropdown->addItem(QString());
        comboBox_SelectToken_dropdown->addItem(QString());
        comboBox_SelectToken_dropdown->addItem(QString());
        comboBox_SelectToken_dropdown->addItem(QString());
        comboBox_SelectToken_dropdown->setObjectName("comboBox_SelectToken_dropdown");
        comboBox_SelectToken_dropdown->setGeometry(QRect(30, 50, 331, 24));
        label_12 = new QLabel(groupBox_SetToken);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(30, 20, 331, 20));
        label_12->setAlignment(Qt::AlignCenter);
        label_13 = new QLabel(groupBox_SetToken);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(30, 100, 331, 20));
        label_13->setAlignment(Qt::AlignCenter);
        line_2 = new QFrame(groupBox_SetToken);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(40, 80, 311, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        toolButton_ChooseURtoken = new QToolButton(groupBox_SetToken);
        toolButton_ChooseURtoken->setObjectName("toolButton_ChooseURtoken");
        toolButton_ChooseURtoken->setGeometry(QRect(160, 130, 71, 23));
        groupBox_TargetVideo = new QGroupBox(groupBox_ExtractData);
        groupBox_TargetVideo->setObjectName("groupBox_TargetVideo");
        groupBox_TargetVideo->setGeometry(QRect(470, 30, 651, 161));
        checkBox_Default_targetVideo = new QCheckBox(groupBox_TargetVideo);
        checkBox_Default_targetVideo->setObjectName("checkBox_Default_targetVideo");
        checkBox_Default_targetVideo->setGeometry(QRect(30, 80, 100, 22));
        groupBox_RecordVid_targetVid = new QGroupBox(groupBox_TargetVideo);
        groupBox_RecordVid_targetVid->setObjectName("groupBox_RecordVid_targetVid");
        groupBox_RecordVid_targetVid->setGeometry(QRect(450, 20, 171, 131));
        checkBox_recVid_targetVid = new QCheckBox(groupBox_RecordVid_targetVid);
        checkBox_recVid_targetVid->setObjectName("checkBox_recVid_targetVid");
        checkBox_recVid_targetVid->setGeometry(QRect(20, 30, 131, 22));
        checkBox_recVid_targetVid->setLayoutDirection(Qt::LeftToRight);
        pushButton_targetVid_window = new QPushButton(groupBox_RecordVid_targetVid);
        pushButton_targetVid_window->setObjectName("pushButton_targetVid_window");
        pushButton_targetVid_window->setGeometry(QRect(20, 70, 131, 31));
        groupBox_SetURown_targetVid = new QGroupBox(groupBox_TargetVideo);
        groupBox_SetURown_targetVid->setObjectName("groupBox_SetURown_targetVid");
        groupBox_SetURown_targetVid->setGeometry(QRect(210, 20, 171, 131));
        checkBox_setURown_targetVid = new QCheckBox(groupBox_SetURown_targetVid);
        checkBox_setURown_targetVid->setObjectName("checkBox_setURown_targetVid");
        checkBox_setURown_targetVid->setGeometry(QRect(20, 30, 131, 22));
        checkBox_setURown_targetVid->setLayoutDirection(Qt::LeftToRight);
        toolButton_defineUR_targetVid = new QToolButton(groupBox_SetURown_targetVid);
        toolButton_defineUR_targetVid->setObjectName("toolButton_defineUR_targetVid");
        toolButton_defineUR_targetVid->setGeometry(QRect(20, 70, 131, 31));
        pushButton__RESET_Feature = new QPushButton(tab_3);
        pushButton__RESET_Feature->setObjectName("pushButton__RESET_Feature");
        pushButton__RESET_Feature->setGeometry(QRect(670, 430, 161, 51));
        pushButton__RESET_Feature->setFont(font3);
        pushButton_pushButton_SAVE_Feature = new QPushButton(tab_3);
        pushButton_pushButton_SAVE_Feature->setObjectName("pushButton_pushButton_SAVE_Feature");
        pushButton_pushButton_SAVE_Feature->setGeometry(QRect(860, 430, 161, 51));
        pushButton_pushButton_SAVE_Feature->setFont(font3);
        groupBox_ExtractMatch = new QGroupBox(tab_3);
        groupBox_ExtractMatch->setObjectName("groupBox_ExtractMatch");
        groupBox_ExtractMatch->setGeometry(QRect(10, 230, 1141, 181));
        groupBox_Extr_Match = new QGroupBox(groupBox_ExtractMatch);
        groupBox_Extr_Match->setObjectName("groupBox_Extr_Match");
        groupBox_Extr_Match->setGeometry(QRect(10, 30, 511, 141));
        comboBox_AlgoSelect_dropdown = new QComboBox(groupBox_Extr_Match);
        comboBox_AlgoSelect_dropdown->addItem(QString());
        comboBox_AlgoSelect_dropdown->addItem(QString());
        comboBox_AlgoSelect_dropdown->addItem(QString());
        comboBox_AlgoSelect_dropdown->addItem(QString());
        comboBox_AlgoSelect_dropdown->addItem(QString());
        comboBox_AlgoSelect_dropdown->setObjectName("comboBox_AlgoSelect_dropdown");
        comboBox_AlgoSelect_dropdown->setGeometry(QRect(20, 70, 121, 41));
        QFont font4;
        font4.setPointSize(11);
        comboBox_AlgoSelect_dropdown->setFont(font4);
        label_16 = new QLabel(groupBox_Extr_Match);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(20, 40, 121, 20));
        label_16->setAlignment(Qt::AlignCenter);
        label_18 = new QLabel(groupBox_Extr_Match);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(180, 40, 131, 20));
        label_18->setAlignment(Qt::AlignCenter);
        spinBox_SetNumFeature__dropdown = new QSpinBox(groupBox_Extr_Match);
        spinBox_SetNumFeature__dropdown->setObjectName("spinBox_SetNumFeature__dropdown");
        spinBox_SetNumFeature__dropdown->setGeometry(QRect(180, 70, 131, 41));
        spinBox_SetNumFeature__dropdown->setFont(font4);
        spinBox_SetNumFeature__dropdown->setMaximum(10000);
        spinBox_SetNumFeature__dropdown->setSingleStep(5);
        spinBox_SetNumFeature__dropdown->setValue(2600);
        label_17 = new QLabel(groupBox_Extr_Match);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(180, 110, 131, 20));
        QFont font5;
        font5.setPointSize(7);
        font5.setBold(false);
        font5.setItalic(true);
        label_17->setFont(font5);
        label_17->setAlignment(Qt::AlignCenter);
        label_25 = new QLabel(groupBox_Extr_Match);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(350, 40, 141, 20));
        label_25->setAlignment(Qt::AlignCenter);
        label_26 = new QLabel(groupBox_Extr_Match);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(350, 110, 141, 20));
        label_26->setFont(font5);
        label_26->setAlignment(Qt::AlignCenter);
        spinBox_InliersThreshold__dropdown = new QSpinBox(groupBox_Extr_Match);
        spinBox_InliersThreshold__dropdown->setObjectName("spinBox_InliersThreshold__dropdown");
        spinBox_InliersThreshold__dropdown->setGeometry(QRect(350, 70, 141, 41));
        groupBox_VidParamOthers = new QGroupBox(groupBox_ExtractMatch);
        groupBox_VidParamOthers->setObjectName("groupBox_VidParamOthers");
        groupBox_VidParamOthers->setGeometry(QRect(550, 30, 571, 141));
        spinBox_FrameSize_width = new QSpinBox(groupBox_VidParamOthers);
        spinBox_FrameSize_width->setObjectName("spinBox_FrameSize_width");
        spinBox_FrameSize_width->setGeometry(QRect(210, 70, 61, 41));
        spinBox_FrameSize_width->setFont(font4);
        spinBox_FrameSize_width->setMaximum(10000);
        spinBox_FrameSize_width->setSingleStep(1);
        spinBox_FrameSize_width->setValue(1280);
        label_21 = new QLabel(groupBox_VidParamOthers);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(210, 110, 151, 20));
        label_21->setFont(font5);
        label_21->setAlignment(Qt::AlignCenter);
        spinBox__FrameSize_heigth = new QSpinBox(groupBox_VidParamOthers);
        spinBox__FrameSize_heigth->setObjectName("spinBox__FrameSize_heigth");
        spinBox__FrameSize_heigth->setGeometry(QRect(300, 70, 61, 41));
        spinBox__FrameSize_heigth->setFont(font4);
        spinBox__FrameSize_heigth->setMaximum(10000);
        spinBox__FrameSize_heigth->setSingleStep(1);
        spinBox__FrameSize_heigth->setValue(720);
        label_23 = new QLabel(groupBox_VidParamOthers);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(400, 110, 151, 20));
        label_23->setFont(font5);
        label_23->setAlignment(Qt::AlignCenter);
        label_22 = new QLabel(groupBox_VidParamOthers);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(210, 40, 151, 20));
        label_22->setAlignment(Qt::AlignCenter);
        label_24 = new QLabel(groupBox_VidParamOthers);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(400, 40, 151, 20));
        label_24->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(groupBox_VidParamOthers);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(276, 80, 20, 20));
        label_10->setFont(font1);
        label_10->setAlignment(Qt::AlignCenter);
        spinBox_skipFrame = new QSpinBox(groupBox_VidParamOthers);
        spinBox_skipFrame->setObjectName("spinBox_skipFrame");
        spinBox_skipFrame->setGeometry(QRect(20, 70, 151, 41));
        spinBox_skipFrame->setFont(font4);
        spinBox_skipFrame->setMaximum(30);
        spinBox_skipFrame->setSingleStep(1);
        spinBox_skipFrame->setValue(2);
        spinBox_FPS = new QSpinBox(groupBox_VidParamOthers);
        spinBox_FPS->setObjectName("spinBox_FPS");
        spinBox_FPS->setGeometry(QRect(400, 70, 151, 41));
        spinBox_FPS->setFont(font4);
        spinBox_FPS->setMaximum(240);
        spinBox_FPS->setSingleStep(1);
        spinBox_FPS->setValue(30);
        label_19 = new QLabel(groupBox_VidParamOthers);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(20, 40, 151, 20));
        label_19->setAlignment(Qt::AlignCenter);
        label_20 = new QLabel(groupBox_VidParamOthers);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(20, 110, 151, 20));
        label_20->setFont(font5);
        label_20->setAlignment(Qt::AlignCenter);
        tabWidget->addTab(tab_3, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        groupBox_13 = new QGroupBox(tab_5);
        groupBox_13->setObjectName("groupBox_13");
        groupBox_13->setGeometry(QRect(270, 0, 881, 491));
        mdiArea_PlayVideoResult = new QMdiArea(groupBox_13);
        mdiArea_PlayVideoResult->setObjectName("mdiArea_PlayVideoResult");
        mdiArea_PlayVideoResult->setGeometry(QRect(30, 30, 821, 451));
        pushButton_GenerateAR = new QPushButton(tab_5);
        pushButton_GenerateAR->setObjectName("pushButton_GenerateAR");
        pushButton_GenerateAR->setGeometry(QRect(40, 40, 191, 81));
        pushButton_GenerateAR->setFont(font3);
        pushButton_OpenVideoResult = new QPushButton(tab_5);
        pushButton_OpenVideoResult->setObjectName("pushButton_OpenVideoResult");
        pushButton_OpenVideoResult->setGeometry(QRect(40, 420, 191, 51));
        QFont font6;
        font6.setPointSize(10);
        pushButton_OpenVideoResult->setFont(font6);
        line = new QFrame(tab_5);
        line->setObjectName("line");
        line->setGeometry(QRect(40, 120, 191, 301));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        tabWidget->addTab(tab_5, QString());
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(10, 570, 1191, 21));
        progressBar->setValue(25);
        progressBar->setAlignment(Qt::AlignCenter);
        label_27 = new QLabel(centralwidget);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(1100, 570, 71, 20));
        label_27->setFont(font5);
        label_27->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1207, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
#if QT_CONFIG(shortcut)
        label->setBuddy(spinBox_checkerInners_2);
        label_5->setBuddy(spinBox_charucorInners_2);
        label_6->setBuddy(spinBox_charucorInners_2);
        label_7->setBuddy(spinBox_charucorInners_2);
        label_17->setBuddy(spinBox_charucorInners_2);
        label_26->setBuddy(spinBox_charucorInners_2);
        label_21->setBuddy(spinBox_charucorInners_2);
        label_23->setBuddy(spinBox_charucorInners_2);
        label_10->setBuddy(spinBox_checkerInners_2);
        label_20->setBuddy(spinBox_charucorInners_2);
        label_27->setBuddy(spinBox_charucorInners_2);
#endif // QT_CONFIG(shortcut)

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Detected Cameras:", nullptr));
        comboBox_camerasDropdown->setItemText(0, QCoreApplication::translate("MainWindow", "Select Device", nullptr));

        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Live Cam", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Camera", nullptr));
        groupBox_Type_section->setTitle(QCoreApplication::translate("MainWindow", "Select Type", nullptr));
        radioButton_Checkerboard->setText(QCoreApplication::translate("MainWindow", "CheckerBoard Pattern", nullptr));
        radioButton_Charuco->setText(QCoreApplication::translate("MainWindow", "ChArUco Pattern", nullptr));
        radioButton_symDots->setText(QCoreApplication::translate("MainWindow", "Symmetric Dots Pattern", nullptr));
        radioButton_assymDots->setText(QCoreApplication::translate("MainWindow", "Asymmetric Dots Pattern", nullptr));
        groupBox_InnersChecker->setTitle(QCoreApplication::translate("MainWindow", "Inner Corner Dimensions", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        groupBox_InnersCharuco->setTitle(QCoreApplication::translate("MainWindow", "Inner Corner Dimensions", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        groupBox_InputData_leftPanel->setTitle(QCoreApplication::translate("MainWindow", "Set Input Data", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Use Default Dataset", nullptr));
        groupBox_Save_calibResults->setTitle(QCoreApplication::translate("MainWindow", "Save Calibration Results to", nullptr));
        radioButton_DefaultLoc_SaveCalibResults->setText(QCoreApplication::translate("MainWindow", "Default Location", nullptr));
        groupBox_PathSaveCalibResults->setTitle(QCoreApplication::translate("MainWindow", "Choose Path", nullptr));
        toolButton_Path_SaveCalibResults->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        groupBox_InputData_rightPanel->setTitle(QCoreApplication::translate("MainWindow", ".", nullptr));
        groupBox_ForSetPath->setTitle(QCoreApplication::translate("MainWindow", "Choose Path", nullptr));
        toolButton_Path_setFolder->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        groupBox__forTakePics_inData->setTitle(QCoreApplication::translate("MainWindow", "Take Pictures", nullptr));
        pushButton_CameraWindow->setText(QCoreApplication::translate("MainWindow", "Camera", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Saved in the Data folder within the main project folder.", nullptr));
        groupBox_ViewResults->setTitle(QCoreApplication::translate("MainWindow", ".                                                                                                                             ", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "If checked, here you'll be able to see the K matrix and distortion values of your camera.", nullptr));
        checkBox_ShowResults->setText(QCoreApplication::translate("MainWindow", "Show Results", nullptr));
        pushButton_SAVE_Calib->setText(QCoreApplication::translate("MainWindow", "Save Configuration", nullptr));
        pushButton_RESET_Calib->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Calibration", nullptr));
        groupBox_ExtractData->setTitle(QCoreApplication::translate("MainWindow", "Extraction Data", nullptr));
        groupBox_SetToken->setTitle(QCoreApplication::translate("MainWindow", "Set Token", nullptr));
        comboBox_SelectToken_dropdown->setItemText(0, QCoreApplication::translate("MainWindow", "Wolf", nullptr));
        comboBox_SelectToken_dropdown->setItemText(1, QCoreApplication::translate("MainWindow", "Cow", nullptr));
        comboBox_SelectToken_dropdown->setItemText(2, QCoreApplication::translate("MainWindow", "Bee", nullptr));
        comboBox_SelectToken_dropdown->setItemText(3, QCoreApplication::translate("MainWindow", "Earth", nullptr));
        comboBox_SelectToken_dropdown->setItemText(4, QCoreApplication::translate("MainWindow", "Car", nullptr));

        label_12->setText(QCoreApplication::translate("MainWindow", "Default Options", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Choose Your Own", nullptr));
        toolButton_ChooseURtoken->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        groupBox_TargetVideo->setTitle(QCoreApplication::translate("MainWindow", "Target Video", nullptr));
        checkBox_Default_targetVideo->setText(QCoreApplication::translate("MainWindow", "Use Default", nullptr));
        groupBox_RecordVid_targetVid->setTitle(QString());
        checkBox_recVid_targetVid->setText(QCoreApplication::translate("MainWindow", "Record a Video", nullptr));
        pushButton_targetVid_window->setText(QCoreApplication::translate("MainWindow", "Start Recording", nullptr));
        groupBox_SetURown_targetVid->setTitle(QString());
        checkBox_setURown_targetVid->setText(QCoreApplication::translate("MainWindow", "Set Your Own", nullptr));
        toolButton_defineUR_targetVid->setText(QCoreApplication::translate("MainWindow", "Browse ...", nullptr));
        pushButton__RESET_Feature->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        pushButton_pushButton_SAVE_Feature->setText(QCoreApplication::translate("MainWindow", "Save Configuration", nullptr));
        groupBox_ExtractMatch->setTitle(QCoreApplication::translate("MainWindow", "Parameters - Extraction and Matching", nullptr));
        groupBox_Extr_Match->setTitle(QCoreApplication::translate("MainWindow", "Feature Extraction and Description", nullptr));
        comboBox_AlgoSelect_dropdown->setItemText(0, QCoreApplication::translate("MainWindow", "ORB", nullptr));
        comboBox_AlgoSelect_dropdown->setItemText(1, QCoreApplication::translate("MainWindow", "SIFT", nullptr));
        comboBox_AlgoSelect_dropdown->setItemText(2, QCoreApplication::translate("MainWindow", "KAZE", nullptr));
        comboBox_AlgoSelect_dropdown->setItemText(3, QCoreApplication::translate("MainWindow", "AKAZE", nullptr));
        comboBox_AlgoSelect_dropdown->setItemText(4, QCoreApplication::translate("MainWindow", "BRISK", nullptr));

        label_16->setText(QCoreApplication::translate("MainWindow", "Set Algorithm Detector", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Set # of Feature", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "*Low resolution need high value.", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Matching Inliers Threshold", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "*Low Resolution needs lower values.", nullptr));
        groupBox_VidParamOthers->setTitle(QCoreApplication::translate("MainWindow", "Other Video Parameters", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "*High resolution videos need resizing.", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "*Higher than 30 needs higher skip rate..", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Video Frame Size", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Video FPS", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Video Skip Rate", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "*High resolution videos can skip more.", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Features", nullptr));
        groupBox_13->setTitle(QCoreApplication::translate("MainWindow", "Augumented Reality Projection ", nullptr));
        pushButton_GenerateAR->setText(QCoreApplication::translate("MainWindow", "Generate AR Inference", nullptr));
        pushButton_OpenVideoResult->setText(QCoreApplication::translate("MainWindow", "Open Video Location", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "Generate Inference", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "\302\251 LHU, 2024", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
