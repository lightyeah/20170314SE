/********************************************************************************
** Form generated from reading UI file 'historydatawindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYDATAWINDOW_H
#define UI_HISTORYDATAWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HistoryDataWindow
{
public:
    QRadioButton *vRadioBtn;
    QRadioButton *pfRadioBtn;
    QRadioButton *fpRadioBtn;
    QRadioButton *apRadioBtn;
    QRadioButton *iRadioBtn;
    QRadioButton *epRadioBtn;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *plotLayout;
    QLabel *label;
    QDateTimeEdit *beginDate;
    QDateTimeEdit *endDate;
    QLabel *label_2;
    QSpinBox *beginHour;
    QSpinBox *endHour;
    QPushButton *setRangeBtn;
    QPushButton *returnBtn;
    QPushButton *eincBtn;
    QPushButton *edecBtn;
    QPushButton *sdecBtn_2;
    QPushButton *sincBtn_2;

    void setupUi(QWidget *HistoryDataWindow)
    {
        if (HistoryDataWindow->objectName().isEmpty())
            HistoryDataWindow->setObjectName(QStringLiteral("HistoryDataWindow"));
        HistoryDataWindow->resize(1000, 600);
        vRadioBtn = new QRadioButton(HistoryDataWindow);
        vRadioBtn->setObjectName(QStringLiteral("vRadioBtn"));
        vRadioBtn->setEnabled(true);
        vRadioBtn->setGeometry(QRect(40, 270, 141, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font.setPointSize(14);
        vRadioBtn->setFont(font);
        vRadioBtn->setIconSize(QSize(32, 32));
        vRadioBtn->setChecked(true);
        pfRadioBtn = new QRadioButton(HistoryDataWindow);
        pfRadioBtn->setObjectName(QStringLiteral("pfRadioBtn"));
        pfRadioBtn->setEnabled(true);
        pfRadioBtn->setGeometry(QRect(40, 520, 141, 41));
        pfRadioBtn->setFont(font);
        pfRadioBtn->setIconSize(QSize(32, 32));
        fpRadioBtn = new QRadioButton(HistoryDataWindow);
        fpRadioBtn->setObjectName(QStringLiteral("fpRadioBtn"));
        fpRadioBtn->setEnabled(true);
        fpRadioBtn->setGeometry(QRect(40, 420, 141, 41));
        fpRadioBtn->setFont(font);
        fpRadioBtn->setIconSize(QSize(32, 32));
        apRadioBtn = new QRadioButton(HistoryDataWindow);
        apRadioBtn->setObjectName(QStringLiteral("apRadioBtn"));
        apRadioBtn->setEnabled(true);
        apRadioBtn->setGeometry(QRect(40, 470, 141, 41));
        apRadioBtn->setFont(font);
        apRadioBtn->setIconSize(QSize(32, 32));
        iRadioBtn = new QRadioButton(HistoryDataWindow);
        iRadioBtn->setObjectName(QStringLiteral("iRadioBtn"));
        iRadioBtn->setEnabled(true);
        iRadioBtn->setGeometry(QRect(40, 320, 141, 41));
        iRadioBtn->setFont(font);
        iRadioBtn->setIconSize(QSize(32, 32));
        epRadioBtn = new QRadioButton(HistoryDataWindow);
        epRadioBtn->setObjectName(QStringLiteral("epRadioBtn"));
        epRadioBtn->setEnabled(true);
        epRadioBtn->setGeometry(QRect(40, 370, 141, 41));
        epRadioBtn->setFont(font);
        epRadioBtn->setIconSize(QSize(32, 32));
        verticalLayoutWidget = new QWidget(HistoryDataWindow);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(270, 40, 711, 511));
        plotLayout = new QVBoxLayout(verticalLayoutWidget);
        plotLayout->setObjectName(QStringLiteral("plotLayout"));
        plotLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(HistoryDataWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 70, 101, 21));
        label->setFont(font);
        beginDate = new QDateTimeEdit(HistoryDataWindow);
        beginDate->setObjectName(QStringLiteral("beginDate"));
        beginDate->setGeometry(QRect(30, 100, 91, 22));
        beginDate->setProperty("showGroupSeparator", QVariant(false));
        beginDate->setCalendarPopup(true);
        endDate = new QDateTimeEdit(HistoryDataWindow);
        endDate->setObjectName(QStringLiteral("endDate"));
        endDate->setGeometry(QRect(30, 170, 91, 22));
        endDate->setCalendarPopup(true);
        label_2 = new QLabel(HistoryDataWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 140, 101, 21));
        label_2->setFont(font);
        beginHour = new QSpinBox(HistoryDataWindow);
        beginHour->setObjectName(QStringLiteral("beginHour"));
        beginHour->setGeometry(QRect(150, 100, 41, 21));
        beginHour->setWrapping(false);
        beginHour->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        beginHour->setMaximum(23);
        endHour = new QSpinBox(HistoryDataWindow);
        endHour->setObjectName(QStringLiteral("endHour"));
        endHour->setGeometry(QRect(150, 170, 41, 21));
        endHour->setWrapping(false);
        endHour->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        endHour->setMaximum(23);
        setRangeBtn = new QPushButton(HistoryDataWindow);
        setRangeBtn->setObjectName(QStringLiteral("setRangeBtn"));
        setRangeBtn->setGeometry(QRect(30, 210, 161, 51));
        returnBtn = new QPushButton(HistoryDataWindow);
        returnBtn->setObjectName(QStringLiteral("returnBtn"));
        returnBtn->setGeometry(QRect(10, 10, 121, 51));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/return.ico"), QSize(), QIcon::Normal, QIcon::Off);
        returnBtn->setIcon(icon);
        returnBtn->setIconSize(QSize(32, 32));
        returnBtn->setFlat(false);
        eincBtn = new QPushButton(HistoryDataWindow);
        eincBtn->setObjectName(QStringLiteral("eincBtn"));
        eincBtn->setGeometry(QRect(200, 140, 31, 31));
        edecBtn = new QPushButton(HistoryDataWindow);
        edecBtn->setObjectName(QStringLiteral("edecBtn"));
        edecBtn->setGeometry(QRect(200, 180, 31, 31));
        sdecBtn_2 = new QPushButton(HistoryDataWindow);
        sdecBtn_2->setObjectName(QStringLiteral("sdecBtn_2"));
        sdecBtn_2->setGeometry(QRect(200, 100, 31, 31));
        sincBtn_2 = new QPushButton(HistoryDataWindow);
        sincBtn_2->setObjectName(QStringLiteral("sincBtn_2"));
        sincBtn_2->setGeometry(QRect(200, 60, 31, 31));

        retranslateUi(HistoryDataWindow);

        QMetaObject::connectSlotsByName(HistoryDataWindow);
    } // setupUi

    void retranslateUi(QWidget *HistoryDataWindow)
    {
        HistoryDataWindow->setWindowTitle(QApplication::translate("HistoryDataWindow", "Form", 0));
        vRadioBtn->setText(QApplication::translate("HistoryDataWindow", "\347\224\265\345\216\213\346\225\260\346\215\256", 0));
        pfRadioBtn->setText(QApplication::translate("HistoryDataWindow", "\345\212\237\347\216\207\345\233\240\347\264\240", 0));
        fpRadioBtn->setText(QApplication::translate("HistoryDataWindow", "\346\227\240\345\212\237\345\212\237\347\216\207", 0));
        apRadioBtn->setText(QApplication::translate("HistoryDataWindow", "\350\247\206\345\234\250\345\212\237\347\216\207", 0));
        iRadioBtn->setText(QApplication::translate("HistoryDataWindow", "\347\224\265\346\265\201", 0));
        epRadioBtn->setText(QApplication::translate("HistoryDataWindow", "\346\234\211\345\212\237\345\212\237\347\216\207", 0));
        label->setText(QApplication::translate("HistoryDataWindow", "\345\274\200\345\247\213\346\227\266\351\227\264", 0));
        beginDate->setDisplayFormat(QApplication::translate("HistoryDataWindow", "yyyy/M/d", 0));
        endDate->setDisplayFormat(QApplication::translate("HistoryDataWindow", "yyyy/M/d", 0));
        label_2->setText(QApplication::translate("HistoryDataWindow", "\347\273\223\346\235\237\346\227\266\351\227\264", 0));
        setRangeBtn->setText(QApplication::translate("HistoryDataWindow", "\346\233\264\346\226\260\346\225\260\346\215\256\350\214\203\345\233\264", 0));
        returnBtn->setText(QApplication::translate("HistoryDataWindow", "\350\277\224\345\233\236", 0));
        eincBtn->setText(QApplication::translate("HistoryDataWindow", "+", 0));
        edecBtn->setText(QApplication::translate("HistoryDataWindow", "-", 0));
        sdecBtn_2->setText(QApplication::translate("HistoryDataWindow", "-", 0));
        sincBtn_2->setText(QApplication::translate("HistoryDataWindow", "+", 0));
    } // retranslateUi

};

namespace Ui {
    class HistoryDataWindow: public Ui_HistoryDataWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYDATAWINDOW_H
