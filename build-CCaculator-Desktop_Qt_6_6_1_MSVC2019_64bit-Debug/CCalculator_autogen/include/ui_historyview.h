/********************************************************************************
** Form generated from reading UI file 'historyview.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYVIEW_H
#define UI_HISTORYVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HistoryView
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer_3;
    QTableWidget *tableWidget;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *spinBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;

    void setupUi(QWidget *HistoryView)
    {
        if (HistoryView->objectName().isEmpty())
            HistoryView->setObjectName("HistoryView");
        HistoryView->resize(280, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HistoryView->sizePolicy().hasHeightForWidth());
        HistoryView->setSizePolicy(sizePolicy);
        HistoryView->setMinimumSize(QSize(280, 600));
        HistoryView->setMaximumSize(QSize(280, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rcs/history.png"), QSize(), QIcon::Normal, QIcon::Off);
        HistoryView->setWindowIcon(icon);
        HistoryView->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        horizontalLayout = new QHBoxLayout(HistoryView);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(HistoryView);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8(""));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        tableWidget = new QTableWidget(HistoryView);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(tableWidget);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton = new QPushButton(HistoryView);
        pushButton->setObjectName("pushButton");
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(0, 36));
        pushButton->setMaximumSize(QSize(36, 16777215));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/rcs/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        spinBox = new QSpinBox(HistoryView);
        spinBox->setObjectName("spinBox");
        spinBox->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(spinBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(HistoryView);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(0, 36));
        pushButton_2->setMaximumSize(QSize(36, 16777215));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/rcs/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon2);

        horizontalLayout_2->addWidget(pushButton_2);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 10);
        horizontalLayout_2->setStretch(3, 1);
        horizontalLayout_2->setStretch(4, 2);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(2, 10);
        verticalLayout->setStretch(3, 1);
        verticalLayout->setStretch(4, 2);

        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(HistoryView);

        QMetaObject::connectSlotsByName(HistoryView);
    } // setupUi

    void retranslateUi(QWidget *HistoryView)
    {
        HistoryView->setWindowTitle(QCoreApplication::translate("HistoryView", "Form", nullptr));
        label->setText(QString());
        pushButton->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HistoryView: public Ui_HistoryView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYVIEW_H
