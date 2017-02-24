
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QProcess>

#include <QGridLayout>
//#define WINDOWSMODE
//#define LINUXMODE
MainWindow::MainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);//UI显示
    realTimeWin=new RealTimeDataWindow(0,&dataPro);//实时数据
    historyWin=new HistoryDataWindow(0,&dataPro);//历史数据
    testWin=new TestWindow(0,&dataPro);//测试窗口
    realTimeWin->hide();//隐藏
    historyWin->hide();//隐藏
    testWin->hide();//隐藏
    //初始化disenable
    ui->historyButton->setEnabled(false);
    ui->realtimeButton->setEnabled(false);
    ui->testButton->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    //连接初始化
    QLabel  *ammeterLabel = new QLabel(this);
    ammeterBox = new QComboBox(this);
    ammeterLabel->setText(tr("ammeter:  "));
    ammeterLabel->adjustSize();
    ammeterLabel->setGeometry(QRect(10, 20, 50, 20));
    ammeterBox->setGeometry(QRect(60,20,100,20));
    QLabel  *regulatorLabel = new QLabel(this);
    regulatorBox = new QComboBox(this);
    regulatorLabel->setText(tr("regulator:  "));
    regulatorLabel->adjustSize();
    regulatorLabel->setGeometry(QRect(180,20,80,20));
    regulatorBox->setGeometry(QRect(260,20,100,20));
    QPushButton *connectButton = new QPushButton(this);
    QPushButton *refreshportButton = new QPushButton(this);
    connectButton->setText(tr("连接"));
    refreshportButton->setText(tr("刷新端口"));
    connectButton->adjustSize();
    refreshportButton->adjustSize();
    connectButton->setGeometry(QRect(380,20,50,20));
    refreshportButton->setGeometry(QRect(440,20,100,20));
    configWin = new ConfigWindow(0,&dataPro);//配置窗口
    hide();
    setWindowFlags(Qt::Widget);
    show();
    configWin->hide();
    //设置窗口置顶
    configWin->setWindowFlags(Qt::WindowStaysOnTopHint);
    configWin->show();
    QObject::connect(configWin,SIGNAL(systemModeSet(uint)),this,SLOT(setSystemMode(uint)));
    QObject::connect(configWin,SIGNAL(workModeSet(uint)),this,SLOT(setWorkMode(uint)));
    QObject::connect(configWin,SIGNAL(moniterTimeIntervalSet(uint)),this,SLOT(setMonitorTimeInterval(uint)));
    QObject::connect(configWin,SIGNAL(setDone()),this,SLOT(Initall()));
    connect(testWin,&TestWindow::testButtonClicked,&dataPro,&DataProcessor::testAction);
    connect(&dataPro,&DataProcessor::sendTestResult,testWin,&TestWindow::getResult);
    connect(&dataPro,&DataProcessor::monitorBegun,this,&MainWindow::disableTestWindow);
    connect(&dataPro,&DataProcessor::monitorFinish,this,&MainWindow::endableTestWindow);
    //connect(&dataPro,&DataProcessor::ammeterError,this,&MainWindow::ammeterError);
    //connect(&dataPro,&DataProcessor::regulatorError,this,&MainWindow::regulatorError);
    QObject::connect(connectButton,SIGNAL(clicked(bool)),this,SLOT(connectButtonClicked()));
    QObject::connect(refreshportButton,SIGNAL(clicked(bool)),this,SLOT(refreshportClicked()));
    connect(&dataPro,&DataProcessor::connectSuccess,this,&MainWindow::connectSuccess);
 }
MainWindow::~MainWindow()
{
    delete ui;
    delete realTimeWin;
    delete historyWin;
    delete testWin;
    delete configWin;
}
void MainWindow::on_realtimeButton_clicked()
{
    realTimeWin->show();

//    this->hide();
}
void MainWindow::on_testButton_clicked()
{
    testWin->show();
    dataPro.closeMonitor();
//    emit openTestWindow();
//    this->hide();
}
void MainWindow::on_historyButton_clicked()
{
    historyWin->show();
    //    this->hide();
}

void MainWindow::ammeterError()
{
    qDebug()<<"ammeter error";
    QMessageBox ammetermb;
    ammetermb.information(this,"电表错误","电表错误，请仔细检查电表连接，排除故障后再重启",QMessageBox::Ok);
        ui->historyButton->setEnabled(false);
        ui->realtimeButton->setEnabled(false);
        ui->testButton->setEnabled(false);
        ui->pushButton_4->setEnabled(false);
        close();
        Error = true;
//        qApp->exit(0);
        emit sammeterError();
}

void MainWindow::regulatorError()
{
    qDebug()<<"regulator error";
    QMessageBox ammetermb;
    ammetermb.information(this,"下位机错误","下位机错误，请仔细检查下位机连接，排除故障后再重启",QMessageBox::Ok);
        //ui->historyButton->setEnabled(false);
        //ui->realtimeButton->setEnabled(false);
        //ui->testButton->setEnabled(false);
        //ui->pushButton_4->setEnabled(false);
        //close();
        Error = true;
//        qApp->exit(0);
        //emit sregulatorError();
}
//按照设置的方式连接
void MainWindow::connectButtonClicked()
{
#ifndef TESTMODE
    dataPro.connectammeter(ammeterBox->currentText());//连接电表
#endif
    dataPro.connectregulator(regulatorBox->currentText());//打开下位机
    dataPro.dataStartWork();
    ui->historyButton->setEnabled(true);
    ui->realtimeButton->setEnabled(true);
    ui->testButton->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
}
void MainWindow::connectSuccess()
{
    ui->historyButton->setEnabled(true);
    ui->realtimeButton->setEnabled(true);
    ui->testButton->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
}
void MainWindow::refreshportClicked()
{
    regulatorBox->clear();
    ammeterBox->clear();
    foreach (const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        QString portDescription=info.portName();
        /*Windows测试*/
#ifdef WINDOWSMODE
        if(portDescription.contains("COM"))
#endif
        /*linux*/
#ifdef LINUXMODE
        if(portDescription.contains("tty"))
#endif
        {
            ammeterBox->addItem(portDescription);
            regulatorBox->addItem(portDescription);
        }
    }
}
void MainWindow::Initall()
{
    //*****
    foreach (const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        QString portDescription=info.portName();
        /*Windows测试*/
#ifdef WINDOWSMODE
        if(portDescription.contains("COM"))
#endif
        /*linux*/
#ifdef LINUXMODE
        if(portDescription.contains("tty"))
#endif
        {
            ammeterBox->addItem(portDescription);
            regulatorBox->addItem(portDescription);
        }
    }

}

void MainWindow::disableTestWindow()
{
    ui->testButton->setEnabled(false);

}

void MainWindow::endableTestWindow()
{
    ui->testButton->setEnabled(true);
}
/**
 * @brief MainWindow::setSystemMode
 * @param systemmode
 */
void MainWindow::setSystemMode(unsigned int systemmode)
{
    if(systemmode == 1)
    {
#ifndef WINDOWSMODE
#define WINDOWSMODE
#endif
    }
    else
    {
#ifndef LINUXMODE
#define LINUXMODE
#endif
    }
}
/**
 * @brief MainWindow::setWorkMode
 * @param workmode
 */
void MainWindow::setWorkMode(unsigned int workmode)
{
    if(workmode == 1)
    {
#ifndef NORMALMODE
#define NORMALMODE
#endif
    }
    else
    {
#ifndef TESTMODE
#define TESTMODE
#endif
    }
}
/**
 * @brief MainWindow::setMonitorTimeInterval
 * @param tt
 */
void MainWindow::setMonitorTimeInterval(unsigned int tt)
{
    dataPro.setTimeInterval(3,tt);
}

bool MainWindow::isError()
{
    return Error;
}
