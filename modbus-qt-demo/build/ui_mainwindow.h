/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *tempreatureLabal;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *humidityLabel;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton_3;
    QLabel *addrLabel;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *pushButton_5;
    QLabel *baundRateLabel;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *pushButton_7;
    QLabel *correctValueLabel;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *addrEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_4;
    QPushButton *boundRateEdit;
    QPushButton *correctValueEdit;
    QFrame *line;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QComboBox *serialportNameCombobox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QComboBox *baundRateComboBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QComboBox *correctBitCombobox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QComboBox *stopBitComboBox;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_9;
    QComboBox *dataBitsComboBox;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *connectPushButton;
    QPushButton *refreashPushButton;
    QPushButton *disconnectPushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(579, 492);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font.setPointSize(10);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        tempreatureLabal = new QLabel(centralwidget);
        tempreatureLabal->setObjectName(QString::fromUtf8("tempreatureLabal"));

        horizontalLayout->addWidget(tempreatureLabal);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        humidityLabel = new QLabel(centralwidget);
        humidityLabel->setObjectName(QString::fromUtf8("humidityLabel"));

        horizontalLayout_2->addWidget(humidityLabel);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_5->addLayout(verticalLayout);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_3);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_9->addWidget(pushButton_3);

        addrLabel = new QLabel(centralwidget);
        addrLabel->setObjectName(QString::fromUtf8("addrLabel"));

        horizontalLayout_9->addWidget(addrLabel);


        verticalLayout_5->addLayout(horizontalLayout_9);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout_11->addWidget(pushButton_5);

        baundRateLabel = new QLabel(centralwidget);
        baundRateLabel->setObjectName(QString::fromUtf8("baundRateLabel"));

        horizontalLayout_11->addWidget(baundRateLabel);


        verticalLayout_5->addLayout(horizontalLayout_11);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        horizontalLayout_13->addWidget(pushButton_7);

        correctValueLabel = new QLabel(centralwidget);
        correctValueLabel->setObjectName(QString::fromUtf8("correctValueLabel"));

        horizontalLayout_13->addWidget(correctValueLabel);


        verticalLayout_5->addLayout(horizontalLayout_13);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_2);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        addrEdit = new QLineEdit(centralwidget);
        addrEdit->setObjectName(QString::fromUtf8("addrEdit"));

        verticalLayout_4->addWidget(addrEdit);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout_4->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        verticalLayout_4->addWidget(lineEdit_3);


        horizontalLayout_10->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout_3->addWidget(pushButton_4);

        boundRateEdit = new QPushButton(centralwidget);
        boundRateEdit->setObjectName(QString::fromUtf8("boundRateEdit"));

        verticalLayout_3->addWidget(boundRateEdit);

        correctValueEdit = new QPushButton(centralwidget);
        correctValueEdit->setObjectName(QString::fromUtf8("correctValueEdit"));

        verticalLayout_3->addWidget(correctValueEdit);


        horizontalLayout_10->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(horizontalLayout_10);


        gridLayout->addLayout(verticalLayout_5, 0, 0, 1, 1);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        serialportNameCombobox = new QComboBox(centralwidget);
        serialportNameCombobox->setObjectName(QString::fromUtf8("serialportNameCombobox"));

        horizontalLayout_3->addWidget(serialportNameCombobox);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_4->addWidget(label_6);

        baundRateComboBox = new QComboBox(centralwidget);
        baundRateComboBox->setObjectName(QString::fromUtf8("baundRateComboBox"));

        horizontalLayout_4->addWidget(baundRateComboBox);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_5->addWidget(label_7);

        correctBitCombobox = new QComboBox(centralwidget);
        correctBitCombobox->setObjectName(QString::fromUtf8("correctBitCombobox"));

        horizontalLayout_5->addWidget(correctBitCombobox);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_6->addWidget(label_8);

        stopBitComboBox = new QComboBox(centralwidget);
        stopBitComboBox->setObjectName(QString::fromUtf8("stopBitComboBox"));

        horizontalLayout_6->addWidget(stopBitComboBox);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_7->addWidget(label_9);

        dataBitsComboBox = new QComboBox(centralwidget);
        dataBitsComboBox->setObjectName(QString::fromUtf8("dataBitsComboBox"));

        horizontalLayout_7->addWidget(dataBitsComboBox);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        connectPushButton = new QPushButton(centralwidget);
        connectPushButton->setObjectName(QString::fromUtf8("connectPushButton"));

        horizontalLayout_8->addWidget(connectPushButton);

        refreashPushButton = new QPushButton(centralwidget);
        refreashPushButton->setObjectName(QString::fromUtf8("refreashPushButton"));

        horizontalLayout_8->addWidget(refreashPushButton);

        disconnectPushButton = new QPushButton(centralwidget);
        disconnectPushButton->setObjectName(QString::fromUtf8("disconnectPushButton"));

        horizontalLayout_8->addWidget(disconnectPushButton);


        verticalLayout_2->addLayout(horizontalLayout_8);


        gridLayout->addLayout(verticalLayout_2, 0, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 579, 36));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\270\251\345\272\246\357\274\232", nullptr));
        tempreatureLabal->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\271\277\345\272\246\357\274\232", nullptr));
        humidityLabel->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\217\226\350\256\276\345\244\207\345\234\260\345\235\200", nullptr));
        addrLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\217\226\346\263\242\347\211\271\347\216\207", nullptr));
        baundRateLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\217\226\347\237\253\346\255\243\345\200\274", nullptr));
        correctValueLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\350\256\276\345\244\207\345\234\260\345\235\200", nullptr));
        boundRateEdit->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\346\263\242\347\211\271\347\216\207", nullptr));
        correctValueEdit->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\346\240\241\346\255\243\345\200\274", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\267\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\345\245\207\345\201\266\346\240\241\351\252\214\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", nullptr));
        connectPushButton->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        refreashPushButton->setText(QCoreApplication::translate("MainWindow", "\345\210\267\346\226\260", nullptr));
        disconnectPushButton->setText(QCoreApplication::translate("MainWindow", "\346\226\255\345\274\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
