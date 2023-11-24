/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
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
    QPushButton *d1Button;
    QPushButton *d2Button;
    QPushButton *d4Button;
    QPushButton *d3Button;
    QPushButton *d6Button;
    QPushButton *d8Button;
    QPushButton *d5Button;
    QPushButton *d7Button;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLCDNumber *AN5;
    QLCDNumber *AN6;
    QLCDNumber *AN7;
    QLCDNumber *AN8;
    QLabel *AO1;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLCDNumber *AN1;
    QLCDNumber *AN2;
    QLCDNumber *AN3;
    QLCDNumber *AN4;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QDial *PWM1dial;
    QDial *PWM2dial;
    QLabel *AO2;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout;
    QLabel *LED1;
    QLabel *LED2;
    QLabel *LED3;
    QLabel *LED4;
    QLabel *LED5;
    QLabel *LED6;
    QLabel *LED7;
    QLabel *LED8;
    QPushButton *startButton;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1041, 431);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        d1Button = new QPushButton(centralwidget);
        d1Button->setObjectName("d1Button");
        d1Button->setGeometry(QRect(60, 250, 31, 31));
        d2Button = new QPushButton(centralwidget);
        d2Button->setObjectName("d2Button");
        d2Button->setGeometry(QRect(120, 250, 31, 31));
        d4Button = new QPushButton(centralwidget);
        d4Button->setObjectName("d4Button");
        d4Button->setGeometry(QRect(240, 250, 31, 31));
        d3Button = new QPushButton(centralwidget);
        d3Button->setObjectName("d3Button");
        d3Button->setGeometry(QRect(180, 250, 31, 31));
        d6Button = new QPushButton(centralwidget);
        d6Button->setObjectName("d6Button");
        d6Button->setGeometry(QRect(360, 250, 31, 31));
        d8Button = new QPushButton(centralwidget);
        d8Button->setObjectName("d8Button");
        d8Button->setGeometry(QRect(480, 250, 31, 31));
        d5Button = new QPushButton(centralwidget);
        d5Button->setObjectName("d5Button");
        d5Button->setGeometry(QRect(300, 250, 31, 31));
        d7Button = new QPushButton(centralwidget);
        d7Button->setObjectName("d7Button");
        d7Button->setGeometry(QRect(420, 250, 31, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(740, 60, 181, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(740, 180, 181, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 0, 181, 31));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(170, 0, 181, 31));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(300, 0, 181, 31));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(430, 0, 181, 31));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(40, 100, 181, 31));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(170, 100, 181, 31));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(300, 100, 181, 31));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(430, 100, 181, 31));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(40, 130, 501, 71));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        AN5 = new QLCDNumber(layoutWidget);
        AN5->setObjectName("AN5");

        horizontalLayout_3->addWidget(AN5);

        AN6 = new QLCDNumber(layoutWidget);
        AN6->setObjectName("AN6");

        horizontalLayout_3->addWidget(AN6);

        AN7 = new QLCDNumber(layoutWidget);
        AN7->setObjectName("AN7");

        horizontalLayout_3->addWidget(AN7);

        AN8 = new QLCDNumber(layoutWidget);
        AN8->setObjectName("AN8");

        horizontalLayout_3->addWidget(AN8);

        AO1 = new QLabel(centralwidget);
        AO1->setObjectName("AO1");
        AO1->setGeometry(QRect(580, 250, 181, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Yu Gothic UI Light")});
        font.setPointSize(24);
        AO1->setFont(font);
        AO1->setLayoutDirection(Qt::RightToLeft);
        AO1->setAlignment(Qt::AlignCenter);
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(40, 30, 501, 71));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        AN1 = new QLCDNumber(layoutWidget1);
        AN1->setObjectName("AN1");

        horizontalLayout_2->addWidget(AN1);

        AN2 = new QLCDNumber(layoutWidget1);
        AN2->setObjectName("AN2");

        horizontalLayout_2->addWidget(AN2);

        AN3 = new QLCDNumber(layoutWidget1);
        AN3->setObjectName("AN3");

        horizontalLayout_2->addWidget(AN3);

        AN4 = new QLCDNumber(layoutWidget1);
        AN4->setObjectName("AN4");

        horizontalLayout_2->addWidget(AN4);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(580, 20, 181, 221));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        PWM1dial = new QDial(layoutWidget2);
        PWM1dial->setObjectName("PWM1dial");
        PWM1dial->setMinimum(0);
        PWM1dial->setMaximum(49);

        verticalLayout->addWidget(PWM1dial);

        PWM2dial = new QDial(layoutWidget2);
        PWM2dial->setObjectName("PWM2dial");
        PWM2dial->setMinimum(0);
        PWM2dial->setMaximum(49);

        verticalLayout->addWidget(PWM2dial);

        AO2 = new QLabel(centralwidget);
        AO2->setObjectName("AO2");
        AO2->setGeometry(QRect(580, 330, 181, 71));
        AO2->setFont(font);
        AO2->setLayoutDirection(Qt::RightToLeft);
        AO2->setAlignment(Qt::AlignCenter);
        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(40, 310, 524, 62));
        horizontalLayout = new QHBoxLayout(layoutWidget3);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        LED1 = new QLabel(layoutWidget3);
        LED1->setObjectName("LED1");
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LED1->sizePolicy().hasHeightForWidth());
        LED1->setSizePolicy(sizePolicy);
        LED1->setMaximumSize(QSize(60, 60));
        LED1->setPixmap(QPixmap(QString::fromUtf8("ledRojo.png")));
        LED1->setScaledContents(true);

        horizontalLayout->addWidget(LED1);

        LED2 = new QLabel(layoutWidget3);
        LED2->setObjectName("LED2");
        LED2->setMaximumSize(QSize(60, 60));
        LED2->setPixmap(QPixmap(QString::fromUtf8("ledRojo.png")));
        LED2->setScaledContents(true);

        horizontalLayout->addWidget(LED2);

        LED3 = new QLabel(layoutWidget3);
        LED3->setObjectName("LED3");
        LED3->setMaximumSize(QSize(60, 60));
        LED3->setPixmap(QPixmap(QString::fromUtf8("ledRojo.png")));
        LED3->setScaledContents(true);

        horizontalLayout->addWidget(LED3);

        LED4 = new QLabel(layoutWidget3);
        LED4->setObjectName("LED4");
        LED4->setMaximumSize(QSize(60, 60));
        LED4->setPixmap(QPixmap(QString::fromUtf8("ledRojo.png")));
        LED4->setScaledContents(true);

        horizontalLayout->addWidget(LED4);

        LED5 = new QLabel(layoutWidget3);
        LED5->setObjectName("LED5");
        LED5->setMaximumSize(QSize(60, 60));
        LED5->setPixmap(QPixmap(QString::fromUtf8("ledRojo.png")));
        LED5->setScaledContents(true);

        horizontalLayout->addWidget(LED5);

        LED6 = new QLabel(layoutWidget3);
        LED6->setObjectName("LED6");
        LED6->setMaximumSize(QSize(60, 60));
        LED6->setPixmap(QPixmap(QString::fromUtf8("ledRojo.png")));
        LED6->setScaledContents(true);

        horizontalLayout->addWidget(LED6);

        LED7 = new QLabel(layoutWidget3);
        LED7->setObjectName("LED7");
        LED7->setMaximumSize(QSize(60, 60));
        LED7->setPixmap(QPixmap(QString::fromUtf8("ledRojo.png")));
        LED7->setScaledContents(true);

        horizontalLayout->addWidget(LED7);

        LED8 = new QLabel(layoutWidget3);
        LED8->setObjectName("LED8");
        LED8->setMaximumSize(QSize(60, 60));
        LED8->setPixmap(QPixmap(QString::fromUtf8("ledRojo.png")));
        LED8->setScaledContents(true);

        horizontalLayout->addWidget(LED8);

        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(820, 40, 141, 111));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(820, 170, 141, 111));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1041, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        d1Button->setText(QCoreApplication::translate("MainWindow", "D1", nullptr));
        d2Button->setText(QCoreApplication::translate("MainWindow", "D2", nullptr));
        d4Button->setText(QCoreApplication::translate("MainWindow", "D4", nullptr));
        d3Button->setText(QCoreApplication::translate("MainWindow", "D3", nullptr));
        d6Button->setText(QCoreApplication::translate("MainWindow", "D6", nullptr));
        d8Button->setText(QCoreApplication::translate("MainWindow", "D8", nullptr));
        d5Button->setText(QCoreApplication::translate("MainWindow", "D5", nullptr));
        d7Button->setText(QCoreApplication::translate("MainWindow", "D7", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Output1", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Output2", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Analog Input 1", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Analog Input 2", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Analog Input 3", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Analog Input 4", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Analog Input 5", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Analog Input 6", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Analog Input 7", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Analog Input 8", nullptr));
        AO1->setText(QString());
        AO2->setText(QString());
        LED1->setText(QString());
        LED2->setText(QString());
        LED3->setText(QString());
        LED4->setText(QString());
        LED5->setText(QString());
        LED6->setText(QString());
        LED7->setText(QString());
        LED8->setText(QString());
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
