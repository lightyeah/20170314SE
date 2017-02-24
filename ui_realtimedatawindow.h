/********************************************************************************
** Form generated from reading UI file 'realtimedatawindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REALTIMEDATAWINDOW_H
#define UI_REALTIMEDATAWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RealTimeDataWindow
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QSlider *horizontalSlider;
    QRadioButton *vRadioBtn;
    QRadioButton *iRadioBtn;
    QRadioButton *epRadioBtn;
    QRadioButton *fpRadioBtn;
    QRadioButton *apRadioBtn;
    QRadioButton *pfRadioBtn;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *playLayout;
    QPushButton *returnBtn;

    void setupUi(QWidget *RealTimeDataWindow)
    {
        if (RealTimeDataWindow->objectName().isEmpty())
            RealTimeDataWindow->setObjectName(QStringLiteral("RealTimeDataWindow"));
        RealTimeDataWindow->resize(1000, 600);
        label = new QLabel(RealTimeDataWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(21, 190, 51, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font.setPointSize(14);
        label->setFont(font);
        label_2 = new QLabel(RealTimeDataWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(61, 150, 51, 21));
        label_2->setFont(font);
        label_3 = new QLabel(RealTimeDataWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(131, 150, 61, 21));
        label_3->setFont(font);
        label_4 = new QLabel(RealTimeDataWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(221, 150, 51, 21));
        label_4->setFont(font);
        horizontalSlider = new QSlider(RealTimeDataWindow);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(70, 190, 191, 21));
        horizontalSlider->setMaximum(2);
        horizontalSlider->setOrientation(Qt::Horizontal);
        vRadioBtn = new QRadioButton(RealTimeDataWindow);
        vRadioBtn->setObjectName(QStringLiteral("vRadioBtn"));
        vRadioBtn->setEnabled(true);
        vRadioBtn->setGeometry(QRect(70, 260, 141, 41));
        vRadioBtn->setFont(font);
        vRadioBtn->setIconSize(QSize(32, 32));
        iRadioBtn = new QRadioButton(RealTimeDataWindow);
        iRadioBtn->setObjectName(QStringLiteral("iRadioBtn"));
        iRadioBtn->setEnabled(true);
        iRadioBtn->setGeometry(QRect(70, 310, 141, 41));
        iRadioBtn->setFont(font);
        iRadioBtn->setIconSize(QSize(32, 32));
        epRadioBtn = new QRadioButton(RealTimeDataWindow);
        epRadioBtn->setObjectName(QStringLiteral("epRadioBtn"));
        epRadioBtn->setEnabled(true);
        epRadioBtn->setGeometry(QRect(70, 360, 141, 41));
        epRadioBtn->setFont(font);
        epRadioBtn->setIconSize(QSize(32, 32));
        fpRadioBtn = new QRadioButton(RealTimeDataWindow);
        fpRadioBtn->setObjectName(QStringLiteral("fpRadioBtn"));
        fpRadioBtn->setEnabled(true);
        fpRadioBtn->setGeometry(QRect(70, 410, 141, 41));
        fpRadioBtn->setFont(font);
        fpRadioBtn->setIconSize(QSize(32, 32));
        apRadioBtn = new QRadioButton(RealTimeDataWindow);
        apRadioBtn->setObjectName(QStringLiteral("apRadioBtn"));
        apRadioBtn->setEnabled(true);
        apRadioBtn->setGeometry(QRect(70, 460, 141, 41));
        apRadioBtn->setFont(font);
        apRadioBtn->setIconSize(QSize(32, 32));
        pfRadioBtn = new QRadioButton(RealTimeDataWindow);
        pfRadioBtn->setObjectName(QStringLiteral("pfRadioBtn"));
        pfRadioBtn->setEnabled(true);
        pfRadioBtn->setGeometry(QRect(70, 510, 141, 41));
        pfRadioBtn->setFont(font);
        pfRadioBtn->setIconSize(QSize(32, 32));
        verticalLayoutWidget = new QWidget(RealTimeDataWindow);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(320, 39, 641, 531));
        playLayout = new QVBoxLayout(verticalLayoutWidget);
        playLayout->setObjectName(QStringLiteral("playLayout"));
        playLayout->setContentsMargins(0, 0, 0, 0);
        returnBtn = new QPushButton(RealTimeDataWindow);
        returnBtn->setObjectName(QStringLiteral("returnBtn"));
        returnBtn->setGeometry(QRect(70, 40, 121, 51));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/return.ico"), QSize(), QIcon::Normal, QIcon::Off);
        returnBtn->setIcon(icon);
        returnBtn->setIconSize(QSize(32, 32));
        returnBtn->setFlat(false);

        retranslateUi(RealTimeDataWindow);

        QMetaObject::connectSlotsByName(RealTimeDataWindow);
    } // setupUi

    void retranslateUi(QWidget *RealTimeDataWindow)
    {
        RealTimeDataWindow->setWindowTitle(QApplication::translate("RealTimeDataWindow", "Form", 0));
        label->setText(QApplication::translate("RealTimeDataWindow", "\351\207\217\347\250\213", 0));
        label_2->setText(QApplication::translate("RealTimeDataWindow", "1\345\210\206\351\222\237", 0));
        label_3->setText(QApplication::translate("RealTimeDataWindow", "10\345\210\206\351\222\237", 0));
        label_4->setText(QApplication::translate("RealTimeDataWindow", "1\345\260\217\346\227\266", 0));
        vRadioBtn->setText(QApplication::translate("RealTimeDataWindow", "\347\224\265\345\216\213\346\225\260\346\215\256", 0));
        iRadioBtn->setText(QApplication::translate("RealTimeDataWindow", "\347\224\265\346\265\201", 0));
        epRadioBtn->setText(QApplication::translate("RealTimeDataWindow", "\346\234\211\345\212\237\345\212\237\347\216\207", 0));
        fpRadioBtn->setText(QApplication::translate("RealTimeDataWindow", "\346\227\240\345\212\237\345\212\237\347\216\207", 0));
        apRadioBtn->setText(QApplication::translate("RealTimeDataWindow", "\350\247\206\345\234\250\345\212\237\347\216\207", 0));
        pfRadioBtn->setText(QApplication::translate("RealTimeDataWindow", "\345\212\237\347\216\207\345\233\240\347\264\240", 0));
        returnBtn->setText(QApplication::translate("RealTimeDataWindow", "\350\277\224\345\233\236", 0));
    } // retranslateUi

};

namespace Ui {
    class RealTimeDataWindow: public Ui_RealTimeDataWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REALTIMEDATAWINDOW_H
