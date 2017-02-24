/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QPushButton *realtimeButton;
    QPushButton *historyButton;
    QPushButton *testButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;

    void setupUi(QDialog *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 600);
        realtimeButton = new QPushButton(MainWindow);
        realtimeButton->setObjectName(QStringLiteral("realtimeButton"));
        realtimeButton->setGeometry(QRect(90, 80, 250, 200));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(14);
        realtimeButton->setFont(font);
        realtimeButton->setAutoFillBackground(false);
        realtimeButton->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/realtime.ico"), QSize(), QIcon::Normal, QIcon::Off);
        realtimeButton->setIcon(icon);
        realtimeButton->setIconSize(QSize(128, 128));
        realtimeButton->setFlat(false);
        historyButton = new QPushButton(MainWindow);
        historyButton->setObjectName(QStringLiteral("historyButton"));
        historyButton->setGeometry(QRect(490, 80, 250, 200));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icon/history.ico"), QSize(), QIcon::Normal, QIcon::Off);
        historyButton->setIcon(icon1);
        historyButton->setIconSize(QSize(72, 72));
        testButton = new QPushButton(MainWindow);
        testButton->setObjectName(QStringLiteral("testButton"));
        testButton->setGeometry(QRect(90, 300, 250, 200));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icon/test.ico"), QSize(), QIcon::Normal, QIcon::Off);
        testButton->setIcon(icon2);
        testButton->setIconSize(QSize(128, 128));
        pushButton_4 = new QPushButton(MainWindow);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(490, 300, 250, 200));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icon/config.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon3);
        pushButton_4->setIconSize(QSize(72, 72));
        pushButton_4->setFlat(false);
        pushButton_5 = new QPushButton(MainWindow);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(850, 480, 91, 71));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icon/exit.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon4);
        pushButton_5->setIconSize(QSize(48, 48));
        pushButton_5->setAutoRepeat(false);
        pushButton_5->setAutoExclusive(false);
        pushButton_5->setDefault(false);
        pushButton_5->setFlat(true);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QDialog *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\350\212\202\347\224\265\347\263\273\347\273\237", 0));
        realtimeButton->setText(QApplication::translate("MainWindow", "\345\256\236\346\227\266\346\225\260\346\215\256\347\273\230\345\210\266", 0));
        historyButton->setText(QApplication::translate("MainWindow", "\345\216\206\345\217\262\346\225\260\346\215\256\347\273\230\345\210\266", 0));
        testButton->setText(QApplication::translate("MainWindow", "\350\212\202\347\224\265\346\265\213\350\257\225", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\350\256\276\347\275\256", 0));
        pushButton_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
