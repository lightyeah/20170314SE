#ifndef CONFIGWINDOW_H
#define CONFIGWINDOW_H

#include <QWidget>
#include <dataprocessor.h>
#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QGridLayout>
#include <QSlider>
#include <QSpinBox>
/*
 * 配置页面
 * 启动后第一步进行配置设定
 * 配置参数:
 * 系统配置  systemmode  参数 LINUX  WINDOWS
 * 工作模式  workmode  参数 normal  test
 * 监控计时  monitortimeinterval  单位 min  参数  1  5 10 30 100
 *
*/

namespace Ui {
class ConfigWindow;
}

class ConfigWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ConfigWindow(QWidget *parent = 0, DataProcessor *proceessor = 0);
    ~ConfigWindow();

private:
    Ui::ConfigWindow *ui;
    DataProcessor *dataPro;

    //通用函数
    void UIsetting();//界面设置
    void connectsetting();//信号与槽连接设置
    //界面参数
    QPushButton *done;//完成设置按钮
    QComboBox *systemModeBox;//设置系统模式
    QComboBox *workModeBox;//设置工作模式
    QComboBox *moniterTimeIntervalBox;//监控间隔
    QSlider *coeffientSlider;//设置互感系数滑条
    QSpinBox *coeffientSpinbox;//设置互感系数
    //参数
    unsigned int systemMode;
    unsigned int workMode;
    unsigned int monitorTimeInterval;
    unsigned int coeffient;

private slots:
    void doneButtonClicked();//完成设置
    void systemModeBoxChanged(QString systemtext);//设置系统模式参数
    void workModeBoxChanged(QString worktext);//设置工作模式参数
    void moniterTimeIntervalBoxChanged(QString tt);//读取时间间隔
    void coeffientChanged(int coef);//设置互感系数

signals:
    void systemModeSet(unsigned int systemmode);//设置系统模式
    void workModeSet(unsigned int workmode);//设置工作模式
    void moniterTimeIntervalSet(unsigned int tt);//设置监控计时
    void coeffientSet(unsigned int coef);//设置互感参数
    void setDone();//配置完成
};

#endif // CONFIGWINDOW_H
