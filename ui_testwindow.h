/********************************************************************************
** Form generated from reading UI file 'testwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTWINDOW_H
#define UI_TESTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestWindow
{
public:
    QPushButton *beginTest;
    QPushButton *clearTestRecords;
    QTableView *testTable;
    QPushButton *returnBtn;
    QPushButton *calculateRatioButton;
    QLabel *label;
    QLabel *averageRatioLabel;

    void setupUi(QWidget *TestWindow)
    {
        if (TestWindow->objectName().isEmpty())
            TestWindow->setObjectName(QStringLiteral("TestWindow"));
        TestWindow->resize(1000, 600);
        beginTest = new QPushButton(TestWindow);
        beginTest->setObjectName(QStringLiteral("beginTest"));
        beginTest->setGeometry(QRect(60, 120, 121, 61));
        clearTestRecords = new QPushButton(TestWindow);
        clearTestRecords->setObjectName(QStringLiteral("clearTestRecords"));
        clearTestRecords->setGeometry(QRect(60, 210, 121, 61));
        testTable = new QTableView(TestWindow);
        testTable->setObjectName(QStringLiteral("testTable"));
        testTable->setGeometry(QRect(410, 50, 501, 351));
        returnBtn = new QPushButton(TestWindow);
        returnBtn->setObjectName(QStringLiteral("returnBtn"));
        returnBtn->setGeometry(QRect(60, 370, 121, 51));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/return.ico"), QSize(), QIcon::Normal, QIcon::Off);
        returnBtn->setIcon(icon);
        returnBtn->setIconSize(QSize(32, 32));
        returnBtn->setFlat(false);
        calculateRatioButton = new QPushButton(TestWindow);
        calculateRatioButton->setObjectName(QStringLiteral("calculateRatioButton"));
        calculateRatioButton->setGeometry(QRect(60, 290, 121, 61));
        label = new QLabel(TestWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(430, 430, 111, 31));
        averageRatioLabel = new QLabel(TestWindow);
        averageRatioLabel->setObjectName(QStringLiteral("averageRatioLabel"));
        averageRatioLabel->setGeometry(QRect(570, 430, 111, 31));

        retranslateUi(TestWindow);

        QMetaObject::connectSlotsByName(TestWindow);
    } // setupUi

    void retranslateUi(QWidget *TestWindow)
    {
        TestWindow->setWindowTitle(QApplication::translate("TestWindow", "Form", 0));
        beginTest->setText(QApplication::translate("TestWindow", "\345\274\200\345\247\213\346\265\213\350\257\225", 0));
        clearTestRecords->setText(QApplication::translate("TestWindow", "\346\270\205\347\251\272\346\265\213\350\257\225\346\225\260\346\215\256", 0));
        returnBtn->setText(QApplication::translate("TestWindow", "\350\277\224\345\233\236", 0));
        calculateRatioButton->setText(QApplication::translate("TestWindow", "\350\256\241\347\256\227\345\271\263\345\235\207\350\212\202\347\224\265\347\216\207", 0));
        label->setText(QApplication::translate("TestWindow", "\345\271\263\345\235\207\350\212\202\347\224\265\347\216\207\357\274\232", 0));
        averageRatioLabel->setText(QApplication::translate("TestWindow", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class TestWindow: public Ui_TestWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTWINDOW_H
