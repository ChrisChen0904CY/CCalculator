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
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionScientific;
    QAction *actionComplex;
    QAction *actionPractice;
    QAction *actionCurrent_History;
    QAction *actionAll_History;
    QAction *actionHelp;
    QAction *actionContact_us;
    QAction *actionLight;
    QAction *actionDark;
    QAction *actionAbout;
    QAction *actionBlue;
    QAction *actionStyle_DIY;
    QAction *actionSystem_Settings;
    QAction *actionDeg;
    QAction *actionRad;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_33;
    QPushButton *pushButton_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_5;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_6;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *pushButton_7;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *pushButton_8;
    QSpacerItem *horizontalSpacer_29;
    QPushButton *pushButton_30;
    QSpacerItem *horizontalSpacer_25;
    QPushButton *pushButton_34;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *pushButton_9;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton_10;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_11;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_12;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *pushButton_13;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *pushButton_14;
    QSpacerItem *horizontalSpacer_26;
    QPushButton *pushButton_31;
    QSpacerItem *horizontalSpacer_30;
    QPushButton *pushButton_35;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *pushButton_15;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *pushButton_16;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_17;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_18;
    QSpacerItem *horizontalSpacer_20;
    QPushButton *pushButton_19;
    QSpacerItem *horizontalSpacer_19;
    QPushButton *pushButton_20;
    QSpacerItem *horizontalSpacer_27;
    QPushButton *pushButton_32;
    QSpacerItem *horizontalSpacer_31;
    QPushButton *pushButton_36;
    QSpacerItem *horizontalSpacer_18;
    QPushButton *pushButton_21;
    QSpacerItem *horizontalSpacer_17;
    QPushButton *pushButton_22;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_23;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_24;
    QSpacerItem *horizontalSpacer_21;
    QPushButton *pushButton_25;
    QSpacerItem *horizontalSpacer_24;
    QPushButton *pushButton_26;
    QSpacerItem *horizontalSpacer_28;
    QPushButton *pushButton_33;
    QSpacerItem *horizontalSpacer_32;
    QPushButton *pushButton_37;
    QSpacerItem *horizontalSpacer_23;
    QPushButton *pushButton_27;
    QSpacerItem *horizontalSpacer_22;
    QPushButton *pushButton_28;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_29;
    QSpacerItem *verticalSpacer_2;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuAdvanced;
    QMenu *menuHistory;
    QMenu *menuStyle;
    QMenu *menuHekp;
    QMenu *menuSettings;
    QMenu *menuAngle_Mode;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(400, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rcs/my_ico.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"	background-color: rgb(255, 255, 255);\n"
"};"));
        actionScientific = new QAction(MainWindow);
        actionScientific->setObjectName("actionScientific");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/rcs/sci.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionScientific->setIcon(icon1);
        actionComplex = new QAction(MainWindow);
        actionComplex->setObjectName("actionComplex");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/rcs/complex.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionComplex->setIcon(icon2);
        actionPractice = new QAction(MainWindow);
        actionPractice->setObjectName("actionPractice");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/rcs/practice.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPractice->setIcon(icon3);
        actionCurrent_History = new QAction(MainWindow);
        actionCurrent_History->setObjectName("actionCurrent_History");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/rcs/history.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCurrent_History->setIcon(icon4);
        actionAll_History = new QAction(MainWindow);
        actionAll_History->setObjectName("actionAll_History");
        actionAll_History->setIcon(icon4);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName("actionHelp");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/rcs/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon5);
        actionContact_us = new QAction(MainWindow);
        actionContact_us->setObjectName("actionContact_us");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/rcs/email_black.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionContact_us->setIcon(icon6);
        actionLight = new QAction(MainWindow);
        actionLight->setObjectName("actionLight");
        actionLight->setCheckable(true);
        actionLight->setChecked(true);
        actionDark = new QAction(MainWindow);
        actionDark->setObjectName("actionDark");
        actionDark->setCheckable(true);
        actionDark->setEnabled(true);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/rcs/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon7);
        actionBlue = new QAction(MainWindow);
        actionBlue->setObjectName("actionBlue");
        actionBlue->setCheckable(true);
        actionStyle_DIY = new QAction(MainWindow);
        actionStyle_DIY->setObjectName("actionStyle_DIY");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/rcs/color_setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStyle_DIY->setIcon(icon8);
        actionSystem_Settings = new QAction(MainWindow);
        actionSystem_Settings->setObjectName("actionSystem_Settings");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/rcs/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSystem_Settings->setIcon(icon9);
        actionDeg = new QAction(MainWindow);
        actionDeg->setObjectName("actionDeg");
        actionDeg->setCheckable(true);
        actionRad = new QAction(MainWindow);
        actionRad->setObjectName("actionRad");
        actionRad->setCheckable(true);
        actionRad->setChecked(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 40));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: white;\n"
"    border-top-left-radius: 5px;\n"
"    border-top-right-radius: 5px;\n"
"    border-width: 1px;\n"
"    border-style: solid;\n"
"    border-color: black;\n"
"	border-bottom-width: -1px;\n"
"    padding: 5px;\n"
"	font: 16pt \"Microsoft YaHei UI\";\n"
"}"));
        label->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        verticalLayout_3->addWidget(label);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(0, 40));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: white;\n"
"    border-bottom-left-radius: 5px;\n"
"    border-bottom-right-radius: 5px;\n"
"    border-width: 1px;\n"
"    border-style: solid;\n"
"    border-color: black;\n"
"	border-top-width: -1px;\n"
"    padding: 5px;\n"
"	font: 16pt \"Microsoft YaHei UI\";\n"
"}"));
        label_2->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        verticalLayout_3->addWidget(label_2);


        verticalLayout->addLayout(verticalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(60, 60));
        pushButton->setMaximumSize(QSize(60, 60));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setMouseTracking(true);
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 700 14pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(255, 26, 106);\n"
"    color: rgb(255, 255, 255);\n"
"	border-color: rgb(168, 5, 50);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(205, 15, 80); /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(60, 60));
        pushButton_2->setMaximumSize(QSize(60, 60));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setFocusPolicy(Qt::NoFocus);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 700 14pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(255, 157, 87);\n"
"    color: rgb(255, 255, 255);\n"
"	border-color: rgb(168, 100, 45);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color:rgb(205, 100, 50); /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(60, 60));
        pushButton_3->setMaximumSize(QSize(60, 60));
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_3->setFocusPolicy(Qt::NoFocus);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 700 14pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(255, 157, 87);\n"
"    color: rgb(255, 255, 255);\n"
"	border-color: rgb(168, 100, 45);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color:rgb(205, 100, 50); /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout->addWidget(pushButton_3);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(160, 60));
        label_3->setBaseSize(QSize(160, 60));
        label_3->setCursor(QCursor(Qt::PointingHandCursor));
        label_3->setMouseTracking(false);
        label_3->setStyleSheet(QString::fromUtf8("background-image: url(:/rcs/my_logo.png);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"border-color: rgb(168, 25, 5);\n"
"border-width: 1px;\n"
"border-style: solid;\n"
"border-radius: 5px;"));

        horizontalLayout->addWidget(label_3);

        horizontalSpacer_33 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_33);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setMinimumSize(QSize(160, 60));
        pushButton_4->setMaximumSize(QSize(160, 60));
        pushButton_4->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_4->setFocusPolicy(Qt::NoFocus);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 700 20pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(255, 68, 6);\n"
"    color: rgb(255, 255, 255);\n"
"	border-color: rgb(168, 25, 5);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(204, 54, 5);  /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout->addWidget(pushButton_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setMinimumSize(QSize(60, 60));
        pushButton_5->setMaximumSize(QSize(60, 60));
        pushButton_5->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_5->setFocusPolicy(Qt::NoFocus);
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 700 14pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(255, 68, 6);\n"
"    color: rgb(255, 255, 255);\n"
"	border-color: rgb(168, 25, 5);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(204, 54, 5);  /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout->addWidget(pushButton_5);

        horizontalLayout->setStretch(0, 5);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 5);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 5);
        horizontalLayout->setStretch(5, 1);
        horizontalLayout->setStretch(6, 11);
        horizontalLayout->setStretch(7, 1);
        horizontalLayout->setStretch(8, 11);
        horizontalLayout->setStretch(9, 1);
        horizontalLayout->setStretch(10, 5);

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setMinimumSize(QSize(60, 60));
        pushButton_6->setMaximumSize(QSize(60, 60));
        pushButton_6->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_6->setFocusPolicy(Qt::NoFocus);
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 12pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(255, 255, 255);\n"
"    color: rgb(0, 0, 0);\n"
"	border-color: rgb(168, 168, 168);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(210, 210, 210);  /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_3->addWidget(pushButton_6);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_12);

        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(40);
        sizePolicy2.setVerticalStretch(40);
        sizePolicy2.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy2);
        pushButton_7->setMinimumSize(QSize(60, 60));
        pushButton_7->setMaximumSize(QSize(60, 60));
        pushButton_7->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_7->setFocusPolicy(Qt::NoFocus);
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 12pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(255, 255, 255);\n"
"    color: rgb(0, 0, 0);\n"
"	border-color: rgb(168, 168, 168);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(210, 210, 210);  /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_3->addWidget(pushButton_7);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_11);

        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setMinimumSize(QSize(60, 60));
        pushButton_8->setMaximumSize(QSize(60, 60));
        pushButton_8->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_8->setFocusPolicy(Qt::NoFocus);
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 12pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(255, 255, 255);\n"
"    color: rgb(0, 0, 0);\n"
"	border-color: rgb(168, 168, 168);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(210, 210, 210);  /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_3->addWidget(pushButton_8);

        horizontalSpacer_29 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_29);

        pushButton_30 = new QPushButton(centralwidget);
        pushButton_30->setObjectName("pushButton_30");
        pushButton_30->setMinimumSize(QSize(60, 60));
        pushButton_30->setMaximumSize(QSize(60, 60));
        pushButton_30->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_30->setFocusPolicy(Qt::NoFocus);
        pushButton_30->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 700 10pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(255, 85, 255);\n"
"    color: rgb(255, 255, 255);\n"
"	border-color: rgb(168, 25, 168);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(205, 50, 205);  /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_3->addWidget(pushButton_30);

        horizontalSpacer_25 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_25);

        pushButton_34 = new QPushButton(centralwidget);
        pushButton_34->setObjectName("pushButton_34");
        pushButton_34->setMinimumSize(QSize(60, 60));
        pushButton_34->setMaximumSize(QSize(60, 60));
        pushButton_34->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_34->setFocusPolicy(Qt::NoFocus);
        pushButton_34->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 700 10pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(255, 85, 255);\n"
"    color: rgb(255, 255, 255);\n"
"	border-color: rgb(168, 25, 168);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(205, 50, 205);  /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_3->addWidget(pushButton_34);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_10);

        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setMinimumSize(QSize(60, 60));
        pushButton_9->setMaximumSize(QSize(60, 60));
        pushButton_9->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_9->setFocusPolicy(Qt::NoFocus);
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 700 18pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(14, 183, 255);\n"
"    color: rgb(255, 255, 255);\n"
"	border-color: rgb(5, 120, 168);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(14, 133, 255);  /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_3->addWidget(pushButton_9);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        pushButton_10 = new QPushButton(centralwidget);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setMinimumSize(QSize(60, 60));
        pushButton_10->setMaximumSize(QSize(60, 60));
        pushButton_10->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_10->setFocusPolicy(Qt::NoFocus);
        pushButton_10->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 700 18pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(132, 225, 0);\n"
"    color: rgb(255, 255, 255);\n"
"	border-color: rgb(100, 168, 0);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(82, 205, 0);  /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_3->addWidget(pushButton_10);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pushButton_11 = new QPushButton(centralwidget);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setMinimumSize(QSize(60, 60));
        pushButton_11->setMaximumSize(QSize(60, 60));
        pushButton_11->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_11->setFocusPolicy(Qt::NoFocus);
        pushButton_11->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 700 14pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(255, 85, 255);\n"
"    color: rgb(255, 255, 255);\n"
"	border-color: rgb(168, 25, 168);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(205, 50, 205);  /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_3->addWidget(pushButton_11);

        horizontalLayout_3->setStretch(0, 5);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 5);
        horizontalLayout_3->setStretch(3, 1);
        horizontalLayout_3->setStretch(4, 5);
        horizontalLayout_3->setStretch(5, 1);
        horizontalLayout_3->setStretch(6, 5);
        horizontalLayout_3->setStretch(7, 1);
        horizontalLayout_3->setStretch(8, 5);
        horizontalLayout_3->setStretch(9, 1);
        horizontalLayout_3->setStretch(10, 5);
        horizontalLayout_3->setStretch(11, 1);
        horizontalLayout_3->setStretch(12, 5);
        horizontalLayout_3->setStretch(13, 1);
        horizontalLayout_3->setStretch(14, 5);

        verticalLayout_4->addLayout(horizontalLayout_3);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        pushButton_12 = new QPushButton(centralwidget);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setMinimumSize(QSize(60, 60));
        pushButton_12->setMaximumSize(QSize(60, 60));
        pushButton_12->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_12->setFocusPolicy(Qt::NoFocus);
        pushButton_12->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 12pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(255, 255, 255);\n"
"    color: rgb(0, 0, 0);\n"
"	border-color: rgb(168, 168, 168);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(210, 210, 210);  /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_4->addWidget(pushButton_12);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_16);

        pushButton_13 = new QPushButton(centralwidget);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setMinimumSize(QSize(60, 60));
        pushButton_13->setMaximumSize(QSize(60, 60));
        pushButton_13->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_13->setFocusPolicy(Qt::NoFocus);
        pushButton_13->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 12pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(255, 255, 255);\n"
"    color: rgb(0, 0, 0);\n"
"	border-color: rgb(168, 168, 168);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(210, 210, 210);  /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_4->addWidget(pushButton_13);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_15);

        pushButton_14 = new QPushButton(centralwidget);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setMinimumSize(QSize(60, 60));
        pushButton_14->setMaximumSize(QSize(60, 60));
        pushButton_14->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_14->setFocusPolicy(Qt::NoFocus);
        pushButton_14->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 12pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(255, 255, 255);\n"
"    color: rgb(0, 0, 0);\n"
"	border-color: rgb(168, 168, 168);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(210, 210, 210);  /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_4->addWidget(pushButton_14);

        horizontalSpacer_26 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_26);

        pushButton_31 = new QPushButton(centralwidget);
        pushButton_31->setObjectName("pushButton_31");
        sizePolicy.setHeightForWidth(pushButton_31->sizePolicy().hasHeightForWidth());
        pushButton_31->setSizePolicy(sizePolicy);
        pushButton_31->setMinimumSize(QSize(60, 60));
        pushButton_31->setMaximumSize(QSize(60, 60));
        pushButton_31->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_31->setFocusPolicy(Qt::NoFocus);
        pushButton_31->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 700 10pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(255, 85, 255);\n"
"    color: rgb(255, 255, 255);\n"
"	border-color: rgb(168, 25, 168);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(205, 50, 205);  /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_4->addWidget(pushButton_31);

        horizontalSpacer_30 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_30);

        pushButton_35 = new QPushButton(centralwidget);
        pushButton_35->setObjectName("pushButton_35");
        pushButton_35->setMinimumSize(QSize(60, 60));
        pushButton_35->setMaximumSize(QSize(60, 60));
        pushButton_35->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_35->setFocusPolicy(Qt::NoFocus);
        pushButton_35->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 700 10pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(255, 85, 255);\n"
"    color: rgb(255, 255, 255);\n"
"	border-color: rgb(168, 25, 168);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(205, 50, 205);  /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_4->addWidget(pushButton_35);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_14);

        pushButton_15 = new QPushButton(centralwidget);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setMinimumSize(QSize(60, 60));
        pushButton_15->setMaximumSize(QSize(60, 60));
        pushButton_15->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_15->setFocusPolicy(Qt::NoFocus);
        pushButton_15->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 700 14pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(18, 183, 255);\n"
"    color: rgb(255, 255, 255);\n"
"	border-color: rgb(5, 120, 168);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(14, 133, 255);  /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_4->addWidget(pushButton_15);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_13);

        pushButton_16 = new QPushButton(centralwidget);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setMinimumSize(QSize(60, 60));
        pushButton_16->setMaximumSize(QSize(60, 60));
        pushButton_16->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_16->setFocusPolicy(Qt::NoFocus);
        pushButton_16->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 700 18pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(132, 225, 0);\n"
"    color: rgb(255, 255, 255);\n"
"	border-color: rgb(100, 168, 0);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(82, 205, 0);  /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_4->addWidget(pushButton_16);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        pushButton_17 = new QPushButton(centralwidget);
        pushButton_17->setObjectName("pushButton_17");
        pushButton_17->setMinimumSize(QSize(60, 60));
        pushButton_17->setMaximumSize(QSize(60, 60));
        pushButton_17->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_17->setFocusPolicy(Qt::NoFocus);
        pushButton_17->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 700 9pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(255, 85, 255);\n"
"    color: rgb(255, 255, 255);\n"
"	border-color: rgb(168, 25, 168);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(205, 50, 205);  /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_4->addWidget(pushButton_17);

        horizontalLayout_4->setStretch(0, 5);
        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 5);
        horizontalLayout_4->setStretch(3, 1);
        horizontalLayout_4->setStretch(4, 5);
        horizontalLayout_4->setStretch(5, 1);
        horizontalLayout_4->setStretch(6, 5);
        horizontalLayout_4->setStretch(7, 1);
        horizontalLayout_4->setStretch(8, 5);
        horizontalLayout_4->setStretch(9, 1);
        horizontalLayout_4->setStretch(10, 5);
        horizontalLayout_4->setStretch(11, 1);
        horizontalLayout_4->setStretch(12, 5);
        horizontalLayout_4->setStretch(13, 1);
        horizontalLayout_4->setStretch(14, 5);

        verticalLayout_4->addLayout(horizontalLayout_4);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        pushButton_18 = new QPushButton(centralwidget);
        pushButton_18->setObjectName("pushButton_18");
        pushButton_18->setMinimumSize(QSize(60, 60));
        pushButton_18->setMaximumSize(QSize(60, 60));
        pushButton_18->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_18->setFocusPolicy(Qt::NoFocus);
        pushButton_18->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 12pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(255, 255, 255);\n"
"    color: rgb(0, 0, 0);\n"
"	border-color: rgb(168, 168, 168);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(210, 210, 210);  /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_5->addWidget(pushButton_18);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_20);

        pushButton_19 = new QPushButton(centralwidget);
        pushButton_19->setObjectName("pushButton_19");
        pushButton_19->setMinimumSize(QSize(60, 60));
        pushButton_19->setMaximumSize(QSize(40, 16777215));
        pushButton_19->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_19->setFocusPolicy(Qt::NoFocus);
        pushButton_19->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 12pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(255, 255, 255);\n"
"    color: rgb(0, 0, 0);\n"
"	border-color: rgb(168, 168, 168);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(210, 210, 210);  /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_5->addWidget(pushButton_19);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_19);

        pushButton_20 = new QPushButton(centralwidget);
        pushButton_20->setObjectName("pushButton_20");
        pushButton_20->setMinimumSize(QSize(60, 60));
        pushButton_20->setMaximumSize(QSize(60, 60));
        pushButton_20->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_20->setFocusPolicy(Qt::NoFocus);
        pushButton_20->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 12pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(255, 255, 255);\n"
"    color: rgb(0, 0, 0);\n"
"	border-color: rgb(168, 168, 168);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(210, 210, 210);  /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_5->addWidget(pushButton_20);

        horizontalSpacer_27 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_27);

        pushButton_32 = new QPushButton(centralwidget);
        pushButton_32->setObjectName("pushButton_32");
        pushButton_32->setMinimumSize(QSize(60, 60));
        pushButton_32->setMaximumSize(QSize(60, 60));
        pushButton_32->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_32->setFocusPolicy(Qt::NoFocus);
        pushButton_32->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 700 10pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(255, 85, 255);\n"
"    color: rgb(255, 255, 255);\n"
"	border-color: rgb(168, 25, 168);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(205, 50, 205);  /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_5->addWidget(pushButton_32);

        horizontalSpacer_31 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_31);

        pushButton_36 = new QPushButton(centralwidget);
        pushButton_36->setObjectName("pushButton_36");
        pushButton_36->setMinimumSize(QSize(60, 60));
        pushButton_36->setMaximumSize(QSize(60, 60));
        pushButton_36->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_36->setFocusPolicy(Qt::NoFocus);
        pushButton_36->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 700 10pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(255, 85, 255);\n"
"    color: rgb(255, 255, 255);\n"
"	border-color: rgb(168, 25, 168);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(205, 50, 205);  /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_5->addWidget(pushButton_36);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_18);

        pushButton_21 = new QPushButton(centralwidget);
        pushButton_21->setObjectName("pushButton_21");
        pushButton_21->setMinimumSize(QSize(60, 60));
        pushButton_21->setMaximumSize(QSize(60, 60));
        pushButton_21->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_21->setFocusPolicy(Qt::NoFocus);
        pushButton_21->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 700 14pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(14, 183, 255);\n"
"    color: rgb(255, 255, 255);\n"
"	border-color: rgb(5, 120, 168);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(14, 133, 255);  /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_5->addWidget(pushButton_21);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_17);

        pushButton_22 = new QPushButton(centralwidget);
        pushButton_22->setObjectName("pushButton_22");
        pushButton_22->setMinimumSize(QSize(60, 60));
        pushButton_22->setMaximumSize(QSize(60, 60));
        pushButton_22->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_22->setFocusPolicy(Qt::NoFocus);
        pushButton_22->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 700 14pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(132, 225, 0);\n"
"    color: rgb(255, 255, 255);\n"
"	border-color: rgb(100, 168, 0);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(82, 205, 0);  /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_5->addWidget(pushButton_22);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        pushButton_23 = new QPushButton(centralwidget);
        pushButton_23->setObjectName("pushButton_23");
        pushButton_23->setMinimumSize(QSize(60, 60));
        pushButton_23->setMaximumSize(QSize(60, 60));
        pushButton_23->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_23->setFocusPolicy(Qt::NoFocus);
        pushButton_23->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 700 14pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(255, 85, 255);\n"
"    color: rgb(255, 255, 255);\n"
"	border-color: rgb(168, 25, 168);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(205, 50, 205);  /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_5->addWidget(pushButton_23);

        horizontalLayout_5->setStretch(0, 5);
        horizontalLayout_5->setStretch(1, 1);
        horizontalLayout_5->setStretch(2, 5);
        horizontalLayout_5->setStretch(3, 1);
        horizontalLayout_5->setStretch(4, 5);
        horizontalLayout_5->setStretch(5, 1);
        horizontalLayout_5->setStretch(6, 5);
        horizontalLayout_5->setStretch(7, 1);
        horizontalLayout_5->setStretch(8, 5);
        horizontalLayout_5->setStretch(9, 1);
        horizontalLayout_5->setStretch(10, 5);
        horizontalLayout_5->setStretch(11, 1);
        horizontalLayout_5->setStretch(12, 5);
        horizontalLayout_5->setStretch(13, 1);
        horizontalLayout_5->setStretch(14, 5);

        verticalLayout_4->addLayout(horizontalLayout_5);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        pushButton_24 = new QPushButton(centralwidget);
        pushButton_24->setObjectName("pushButton_24");
        pushButton_24->setMinimumSize(QSize(60, 60));
        pushButton_24->setMaximumSize(QSize(60, 60));
        pushButton_24->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_24->setFocusPolicy(Qt::NoFocus);
        pushButton_24->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 700 14pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(255, 255, 255);\n"
"    color: rgb(0, 0, 0);\n"
"	border-color: rgb(168, 168, 168);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(210, 210, 210);  /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_6->addWidget(pushButton_24);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_21);

        pushButton_25 = new QPushButton(centralwidget);
        pushButton_25->setObjectName("pushButton_25");
        pushButton_25->setMinimumSize(QSize(60, 60));
        pushButton_25->setMaximumSize(QSize(60, 60));
        pushButton_25->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_25->setFocusPolicy(Qt::NoFocus);
        pushButton_25->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 12pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(255, 255, 255);\n"
"    color: rgb(0, 0, 0);\n"
"	border-color: rgb(168, 168, 168);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(210, 210, 210);  /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_6->addWidget(pushButton_25);

        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_24);

        pushButton_26 = new QPushButton(centralwidget);
        pushButton_26->setObjectName("pushButton_26");
        pushButton_26->setMinimumSize(QSize(60, 60));
        pushButton_26->setMaximumSize(QSize(60, 60));
        pushButton_26->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_26->setFocusPolicy(Qt::NoFocus);
        pushButton_26->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 700 9pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(255, 255, 255);\n"
"    color: rgb(0, 0, 0);\n"
"	border-color: rgb(168, 168, 168);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(210, 210, 210);  /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_6->addWidget(pushButton_26);

        horizontalSpacer_28 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_28);

        pushButton_33 = new QPushButton(centralwidget);
        pushButton_33->setObjectName("pushButton_33");
        pushButton_33->setMinimumSize(QSize(60, 60));
        pushButton_33->setMaximumSize(QSize(60, 60));
        pushButton_33->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_33->setFocusPolicy(Qt::NoFocus);
        pushButton_33->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 700 10pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(255, 85, 255);\n"
"    color: rgb(255, 255, 255);\n"
"	border-color: rgb(168, 25, 168);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(205, 50, 205);  /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_6->addWidget(pushButton_33);

        horizontalSpacer_32 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_32);

        pushButton_37 = new QPushButton(centralwidget);
        pushButton_37->setObjectName("pushButton_37");
        pushButton_37->setMinimumSize(QSize(60, 60));
        pushButton_37->setMaximumSize(QSize(60, 60));
        pushButton_37->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_37->setFocusPolicy(Qt::NoFocus);
        pushButton_37->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 700 10pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(255, 85, 255);\n"
"    color: rgb(255, 255, 255);\n"
"	border-color: rgb(168, 25, 168);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(205, 50, 205);  /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_6->addWidget(pushButton_37);

        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_23);

        pushButton_27 = new QPushButton(centralwidget);
        pushButton_27->setObjectName("pushButton_27");
        pushButton_27->setMinimumSize(QSize(60, 60));
        pushButton_27->setMaximumSize(QSize(60, 60));
        pushButton_27->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_27->setFocusPolicy(Qt::NoFocus);
        pushButton_27->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 700 14pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(255, 157, 87);\n"
"    color: rgb(255, 255, 255);\n"
"	border-color: rgb(168, 100, 45);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color:rgb(205, 100, 50); /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_6->addWidget(pushButton_27);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_22);

        pushButton_28 = new QPushButton(centralwidget);
        pushButton_28->setObjectName("pushButton_28");
        pushButton_28->setMinimumSize(QSize(60, 60));
        pushButton_28->setMaximumSize(QSize(60, 60));
        pushButton_28->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_28->setFocusPolicy(Qt::NoFocus);
        pushButton_28->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 700 14pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(255, 157, 87);\n"
"    color: rgb(255, 255, 255);\n"
"	border-color: rgb(168, 100, 45);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color:rgb(205, 100, 50); /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_6->addWidget(pushButton_28);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        pushButton_29 = new QPushButton(centralwidget);
        pushButton_29->setObjectName("pushButton_29");
        pushButton_29->setMinimumSize(QSize(60, 60));
        pushButton_29->setMaximumSize(QSize(60, 60));
        pushButton_29->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_29->setFocusPolicy(Qt::NoFocus);
        pushButton_29->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 700 14pt \"Microsoft YaHei UI\";\n"
"    background-color: rgb(255, 26, 106);\n"
"    color: rgb(255, 255, 255);\n"
"	border-color: rgb(168, 5, 50);\n"
"	border-width: 1px;\n"
"    border-style: solid;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(205, 15, 80); /* \350\260\203\346\267\261\347\232\204\351\242\234\350\211\262 */\n"
"}\n"
""));

        horizontalLayout_6->addWidget(pushButton_29);

        horizontalLayout_6->setStretch(0, 5);
        horizontalLayout_6->setStretch(1, 1);
        horizontalLayout_6->setStretch(2, 5);
        horizontalLayout_6->setStretch(3, 1);
        horizontalLayout_6->setStretch(4, 5);
        horizontalLayout_6->setStretch(5, 1);
        horizontalLayout_6->setStretch(6, 5);
        horizontalLayout_6->setStretch(7, 1);
        horizontalLayout_6->setStretch(8, 5);
        horizontalLayout_6->setStretch(9, 1);
        horizontalLayout_6->setStretch(10, 5);
        horizontalLayout_6->setStretch(11, 1);
        horizontalLayout_6->setStretch(12, 5);
        horizontalLayout_6->setStretch(13, 1);
        horizontalLayout_6->setStretch(14, 5);

        verticalLayout_4->addLayout(horizontalLayout_6);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 5);
        verticalLayout_4->setStretch(2, 1);
        verticalLayout_4->setStretch(3, 5);
        verticalLayout_4->setStretch(4, 1);
        verticalLayout_4->setStretch(5, 5);
        verticalLayout_4->setStretch(6, 1);
        verticalLayout_4->setStretch(7, 5);

        verticalLayout->addLayout(verticalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        verticalLayout->setStretch(0, 20);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 2);
        verticalLayout->setStretch(3, 40);
        verticalLayout->setStretch(4, 1);

        horizontalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        menuAdvanced = new QMenu(menubar);
        menuAdvanced->setObjectName("menuAdvanced");
        menuHistory = new QMenu(menubar);
        menuHistory->setObjectName("menuHistory");
        menuStyle = new QMenu(menubar);
        menuStyle->setObjectName("menuStyle");
        menuHekp = new QMenu(menubar);
        menuHekp->setObjectName("menuHekp");
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName("menuSettings");
        menuAngle_Mode = new QMenu(menuSettings);
        menuAngle_Mode->setObjectName("menuAngle_Mode");
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/rcs/angle_set.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuAngle_Mode->setIcon(icon10);
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuAdvanced->menuAction());
        menubar->addAction(menuStyle->menuAction());
        menubar->addAction(menuHistory->menuAction());
        menubar->addAction(menuSettings->menuAction());
        menubar->addAction(menuHekp->menuAction());
        menuAdvanced->addAction(actionScientific);
        menuAdvanced->addAction(actionComplex);
        menuAdvanced->addSeparator();
        menuAdvanced->addAction(actionPractice);
        menuHistory->addSeparator();
        menuHistory->addSeparator();
        menuHistory->addAction(actionCurrent_History);
        menuHistory->addAction(actionAll_History);
        menuStyle->addAction(actionLight);
        menuStyle->addAction(actionDark);
        menuStyle->addAction(actionBlue);
        menuHekp->addAction(actionAbout);
        menuHekp->addAction(actionHelp);
        menuHekp->addSeparator();
        menuHekp->addAction(actionContact_us);
        menuSettings->addAction(menuAngle_Mode->menuAction());
        menuSettings->addAction(actionStyle_DIY);
        menuSettings->addSeparator();
        menuSettings->addAction(actionSystem_Settings);
        menuAngle_Mode->addAction(actionDeg);
        menuAngle_Mode->addAction(actionRad);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "CCalculator", nullptr));
        actionScientific->setText(QCoreApplication::translate("MainWindow", "Scientific", nullptr));
#if QT_CONFIG(shortcut)
        actionScientific->setShortcut(QCoreApplication::translate("MainWindow", "Alt+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionComplex->setText(QCoreApplication::translate("MainWindow", "Complex", nullptr));
        actionPractice->setText(QCoreApplication::translate("MainWindow", "Practice", nullptr));
        actionCurrent_History->setText(QCoreApplication::translate("MainWindow", "Current History", nullptr));
#if QT_CONFIG(shortcut)
        actionCurrent_History->setShortcut(QCoreApplication::translate("MainWindow", "H", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAll_History->setText(QCoreApplication::translate("MainWindow", "All History", nullptr));
#if QT_CONFIG(shortcut)
        actionAll_History->setShortcut(QCoreApplication::translate("MainWindow", "Alt+H", nullptr));
#endif // QT_CONFIG(shortcut)
        actionHelp->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
#if QT_CONFIG(shortcut)
        actionHelp->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+H", nullptr));
#endif // QT_CONFIG(shortcut)
        actionContact_us->setText(QCoreApplication::translate("MainWindow", "Contact us", nullptr));
        actionLight->setText(QCoreApplication::translate("MainWindow", "Light", nullptr));
        actionDark->setText(QCoreApplication::translate("MainWindow", "Dark", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionBlue->setText(QCoreApplication::translate("MainWindow", "Blue", nullptr));
        actionStyle_DIY->setText(QCoreApplication::translate("MainWindow", "Style DIY", nullptr));
        actionSystem_Settings->setText(QCoreApplication::translate("MainWindow", "System Settings", nullptr));
        actionDeg->setText(QCoreApplication::translate("MainWindow", "Deg(\302\260)", nullptr));
        actionRad->setText(QCoreApplication::translate("MainWindow", "Rad", nullptr));
        label->setText(QString());
        label_2->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton->setToolTip(QCoreApplication::translate("MainWindow", "\347\256\227\345\274\217\351\224\231\350\257\257\346\243\200\351\252\214", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton->setText(QCoreApplication::translate("MainWindow", "E", nullptr));
#if QT_CONFIG(shortcut)
        pushButton->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_2->setToolTip(QCoreApplication::translate("MainWindow", "\345\267\246\346\213\254\345\217\267", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_2->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_2->setShortcut(QCoreApplication::translate("MainWindow", "(", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_3->setToolTip(QCoreApplication::translate("MainWindow", "\345\217\263\346\213\254\345\217\267", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_3->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_3->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_3->setShortcut(QCoreApplication::translate("MainWindow", ")", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        label_3->setToolTip(QCoreApplication::translate("MainWindow", "\347\202\271\346\210\221\350\216\267\345\276\227\351\232\217\346\234\272\346\225\260", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        label_3->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        label_3->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_4->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\200\346\240\274", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_4->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\342\206\220", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_4->setShortcut(QCoreApplication::translate("MainWindow", "Backspace", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_5->setToolTip(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\346\211\200\346\234\211\350\276\223\345\205\245", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_5->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_5->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_6->setToolTip(QCoreApplication::translate("MainWindow", "\344\270\200\344\270\252\344\270\200\344\270\252\344\270\200\344\270\252", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_6->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_6->setShortcut(QCoreApplication::translate("MainWindow", "1", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_7->setToolTip(QCoreApplication::translate("MainWindow", "2", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_7->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_7->setShortcut(QCoreApplication::translate("MainWindow", "2", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_8->setToolTip(QCoreApplication::translate("MainWindow", "3", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_8->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_8->setShortcut(QCoreApplication::translate("MainWindow", "3", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_30->setToolTip(QCoreApplication::translate("MainWindow", "\346\255\243\345\274\246\345\207\275\346\225\260sin", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_30->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_30->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_30->setShortcut(QCoreApplication::translate("MainWindow", "S", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_34->setToolTip(QCoreApplication::translate("MainWindow", "\346\255\243\345\210\207\345\207\275\346\225\260tan", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_34->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_34->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_34->setShortcut(QCoreApplication::translate("MainWindow", "T", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_9->setToolTip(QCoreApplication::translate("MainWindow", "+", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_9->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_9->setShortcut(QCoreApplication::translate("MainWindow", "+", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_10->setToolTip(QCoreApplication::translate("MainWindow", "\303\227", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_10->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "\303\227", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_10->setShortcut(QCoreApplication::translate("MainWindow", "*", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_11->setToolTip(QCoreApplication::translate("MainWindow", "\347\231\276\345\210\206\345\217\267", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_11->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_11->setShortcut(QCoreApplication::translate("MainWindow", "%", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_12->setToolTip(QCoreApplication::translate("MainWindow", "4444\357\274\201\357\274\201\357\274\201\357\274\201", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_12->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_12->setShortcut(QCoreApplication::translate("MainWindow", "4", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_13->setToolTip(QCoreApplication::translate("MainWindow", "5", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_13->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_13->setShortcut(QCoreApplication::translate("MainWindow", "5", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_14->setToolTip(QCoreApplication::translate("MainWindow", "\345\215\225\350\265\260\344\270\200\345\274\240\345\205\255", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_14->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_14->setShortcut(QCoreApplication::translate("MainWindow", "6", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_31->setToolTip(QCoreApplication::translate("MainWindow", "\345\217\215\346\255\243\345\274\246\345\207\275\346\225\260arcsin", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_31->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_31->setText(QCoreApplication::translate("MainWindow", "arcsin", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_31->setShortcut(QCoreApplication::translate("MainWindow", "Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_35->setToolTip(QCoreApplication::translate("MainWindow", "\345\217\215\346\255\243\345\210\207\345\207\275\346\225\260arctan", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_35->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_35->setText(QCoreApplication::translate("MainWindow", "arctan", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_35->setShortcut(QCoreApplication::translate("MainWindow", "Shift+T", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_15->setToolTip(QCoreApplication::translate("MainWindow", "-", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_15->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_15->setShortcut(QCoreApplication::translate("MainWindow", "-", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_16->setToolTip(QCoreApplication::translate("MainWindow", "\303\267", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_16->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "\303\267", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_16->setShortcut(QCoreApplication::translate("MainWindow", "/", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_17->setToolTip(QCoreApplication::translate("MainWindow", "\345\217\226\344\275\231", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_17->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_17->setText(QCoreApplication::translate("MainWindow", "Mod", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_17->setShortcut(QCoreApplication::translate("MainWindow", "M", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_18->setToolTip(QCoreApplication::translate("MainWindow", "7", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_18->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_18->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_18->setShortcut(QCoreApplication::translate("MainWindow", "7", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_19->setToolTip(QCoreApplication::translate("MainWindow", "8", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_19->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_19->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_19->setShortcut(QCoreApplication::translate("MainWindow", "8", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_20->setToolTip(QCoreApplication::translate("MainWindow", "9", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_20->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_20->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_20->setShortcut(QCoreApplication::translate("MainWindow", "9", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_32->setToolTip(QCoreApplication::translate("MainWindow", "\344\275\231\345\274\246\345\207\275\346\225\260cos", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_32->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_32->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_32->setShortcut(QCoreApplication::translate("MainWindow", "C", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_36->setToolTip(QCoreApplication::translate("MainWindow", "\350\207\252\347\204\266\345\257\271\346\225\260 ln", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_36->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_36->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_36->setShortcut(QCoreApplication::translate("MainWindow", "Shift+L", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_21->setToolTip(QCoreApplication::translate("MainWindow", "\345\271\202\346\214\207", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_21->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_21->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_21->setShortcut(QCoreApplication::translate("MainWindow", "^", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_22->setToolTip(QCoreApplication::translate("MainWindow", "\351\230\266\344\271\230", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_22->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_22->setText(QCoreApplication::translate("MainWindow", "!", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_22->setShortcut(QCoreApplication::translate("MainWindow", "!", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_23->setToolTip(QCoreApplication::translate("MainWindow", "\345\245\207/\345\201\266\351\230\266\344\271\230", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_23->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_23->setText(QCoreApplication::translate("MainWindow", "!!", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_23->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+1", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_24->setToolTip(QCoreApplication::translate("MainWindow", "\345\260\217\346\225\260\347\202\271", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_24->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_24->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_24->setShortcut(QCoreApplication::translate("MainWindow", ".", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_25->setToolTip(QCoreApplication::translate("MainWindow", "\347\203\247\351\233\266\342\231\202", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_25->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_25->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_25->setShortcut(QCoreApplication::translate("MainWindow", "0", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_26->setToolTip(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\200\346\254\241\347\232\204\350\277\220\347\256\227\347\273\223\346\236\234", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_26->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_26->setText(QCoreApplication::translate("MainWindow", "Ans", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_26->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_33->setToolTip(QCoreApplication::translate("MainWindow", "\345\217\215\344\275\231\345\274\246\345\207\275\346\225\260arccos", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_33->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_33->setText(QCoreApplication::translate("MainWindow", "arccos", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_33->setShortcut(QCoreApplication::translate("MainWindow", "Shift+C", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_37->setToolTip(QCoreApplication::translate("MainWindow", "\345\257\271\346\225\260 log", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_37->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_37->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_37->setShortcut(QCoreApplication::translate("MainWindow", "L", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_27->setToolTip(QCoreApplication::translate("MainWindow", "\345\234\206\345\221\250\347\216\207", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_27->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_27->setText(QCoreApplication::translate("MainWindow", "\317\200", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_27->setShortcut(QCoreApplication::translate("MainWindow", "P", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_28->setToolTip(QCoreApplication::translate("MainWindow", "\350\207\252\347\204\266\346\225\260", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_28->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_28->setText(QCoreApplication::translate("MainWindow", "e", nullptr));
#if QT_CONFIG(shortcut)
        pushButton_28->setShortcut(QCoreApplication::translate("MainWindow", "E", nullptr));
#endif // QT_CONFIG(shortcut)
#if QT_CONFIG(tooltip)
        pushButton_29->setToolTip(QCoreApplication::translate("MainWindow", "\350\256\241\347\256\227\346\211\200\350\276\223\345\205\245\347\232\204\347\256\227\345\274\217", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_29->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_29->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        menuAdvanced->setTitle(QCoreApplication::translate("MainWindow", "Mode", nullptr));
        menuHistory->setTitle(QCoreApplication::translate("MainWindow", "History", nullptr));
        menuStyle->setTitle(QCoreApplication::translate("MainWindow", "Style", nullptr));
        menuHekp->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        menuAngle_Mode->setTitle(QCoreApplication::translate("MainWindow", "Angle Mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
