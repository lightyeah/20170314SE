#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <realtimedatawindow.h>
#include <historydatawindow.h>
#include <configwindow.h>
#include <testwindow.h>
#include <datapoint.h>
#include <dataprocessor.h>

QT_BEGIN_NAMESPACE
class QComboBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QTcpSocket;
class QNetworkSession;
QT_END_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_realtimeButton_clicked();
    void on_testButton_clicked();
    void on_historyButton_clicked();
    void ammeterError();
    void regulatorError();
    void connectButtonClicked();
    void connectSuccess();//连接成功
    void refreshportClicked();//刷新端口
    void Initall();

private:
    Ui::MainWindow *ui;
    RealTimeDataWindow* realTimeWin;
    HistoryDataWindow* historyWin;
    ConfigWindow* configWin;
    TestWindow* testWin;
    DataProcessor dataPro;
    //连接初始化
    QComboBox *ammeterBox;
    QComboBox *regulatorBox;

    bool Error;

public slots:
    void disableTestWindow();
    void endableTestWindow();
    void setSystemMode(unsigned int systemmode);//系统参数设置
    void setWorkMode(unsigned int workmode);//工作模式参数设置
    void setMonitorTimeInterval(unsigned int tt);//设置监控时间
    bool isError();

signals:
    void sregulatorError();
    void sammeterError();




};

#endif // MAINWINDOW_H
