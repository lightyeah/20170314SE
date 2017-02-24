#include "regulator.h"
#include <stdio.h>
#include <QTime>
//#include <QTestEventList>

Regulator::Regulator(QObject *parent) : QObject(parent)
{
    openPort();//打开串口
    timeoutTimer = new QTimer(this);//超时计时器
    endtimeTimer = new QTimer(this);//结束超时计时器
    connect(timeoutTimer,&QTimer::timeout,this,&Regulator::handleTimeout);
    QObject::connect(endtimeTimer,SIGNAL(timeout()),this,SLOT(handleEndTimeout()));
    ReSendCount = 0;
    type=IDLE;
    endtype=IDLE;
    r_state = RIDLE;
}



void Regulator::beginRegulate()
{

}

void Regulator::beginTest()
{

}

//具体的串口产生需要根据实际情况进行调整
void Regulator::openPort()
{
/*/    regulatorPort=new QSerialPort(this);
//    foreach (const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
//    {
//        QString portDescription=info.portName();
//        qDebug()<<portDescription;
//        if(portDescription.contains(QString("ttyUSB1")))
//        //if(portDescription.contains(QString("COM5")))
//        {
//            qDebug()<<"regulator found";
//            RegulatorFound = true;
//            //regulatorPort
//            regulatorPort->setPortName(portDescription);
//            regulatorPort->setBaudRate(QSerialPort::Baud9600);
//            regulatorPort->setDataBits(QSerialPort::Data8);
//            regulatorPort->setParity(QSerialPort::NoParity);
//            regulatorPort->setStopBits(QSerialPort::OneStop);
//            regulatorPort->setFlowControl(QSerialPort::NoFlowControl);
//            regulatorPort->open(QIODevice::ReadWrite);
//            connect(regulatorPort,&QSerialPort::readyRead,this,&Regulator::parseData);
//            return;
//        }
//    }
//    RegulatorFound = false;
//    emit regulatorPortNotFound();
    return;
/*/
}

void Regulator::sendData(DataPoint voltage,DataPoint newData)
{
    if(type != IDLE)return;    //指令冲突处理
    //qDebug()<<"data start ssend";
    QByteArray datahead;
    QByteArray data;
    QByteArray datatail;
    datahead = QString("4250").toLocal8Bit();
    datahead = QByteArray::fromHex(datahead);
    data = QString::number((int)voltage.vb*10).toLocal8Bit();//载入数据
    //qDebug()<<"data -- "<<data;
    datatail = QString("0d").toLocal8Bit();
    datatail = QByteArray::fromHex(datatail);
    /*orderClear(DataOrder);
    char checkcode;
    DataOrder.head = QString("2aeb").toLocal8Bit();
    DataOrder.head = QByteArray::fromHex(DataOrder.head);
    DataOrder.address = QString("02").toLocal8Bit();
    DataOrder.address = QByteArray::fromHex(DataOrder.address);
    DataOrder.commandtype = QString("05").toLocal8Bit();
    DataOrder.commandtype = QByteArray::fromHex(DataOrder.commandtype);
    DataOrder.datalength = QString("18").toLocal8Bit();//
    DataOrder.datalength = QByteArray::fromHex(DataOrder.datalength);
    DataOrder.data.clear();
    checkcode = dataIntoString(DataOrder.data,voltage,newData);
    checkcode ^= 0x02^0x05^0x18;
    DataOrder.checkcode.clear();
    DataOrder.checkcode.append(checkcode);
    DataOrder.tail = QString("ad").toLocal8Bit();
    DataOrder.tail = QByteArray::fromHex(DataOrder.tail);
    //发送指令
    sendInstruction(DataOrder);*/
    qDebug()<<"data sended";
    //状态改变 发送消息
    regulatorPort->write(datahead);
    regulatorPort->write(data);
    regulatorPort->write(datatail);
    timeoutTimer->start(3000);//超时3s
    //type = WaitForDataCheckBack;
    /*发送数据后不需要回复*/
    type = IDLE;
}

//节能模拟指令
void Regulator::simulationSaving()
{
    if(type != IDLE)return;
    orderClear(SimulationOrder);
    SimulationOrder.head = QString("2aeb").toLocal8Bit();
    SimulationOrder.head = QByteArray::fromHex(SimulationOrder.head);
    SimulationOrder.address = QString("02").toLocal8Bit();
    SimulationOrder.address = QByteArray::fromHex(SimulationOrder.address);
    SimulationOrder.commandtype = QString("02").toLocal8Bit();
    SimulationOrder.commandtype = QByteArray::fromHex(SimulationOrder.commandtype);
    SimulationOrder.datalength = QString("01").toLocal8Bit();
    SimulationOrder.datalength = QByteArray::fromHex(SimulationOrder.datalength);
    SimulationOrder.data = QString("00").toLocal8Bit();
    SimulationOrder.data = QByteArray::fromHex(SimulationOrder.data);
    SimulationOrder.checkcode = QString("01").toLocal8Bit();
    SimulationOrder.checkcode = QByteArray::fromHex(SimulationOrder.checkcode);
    SimulationOrder.tail = QString("ad").toLocal8Bit();
    SimulationOrder.tail = QByteArray::fromHex(SimulationOrder.tail);
    //发送指令
    sendInstruction(SimulationOrder);
    //状态改变 发送消息
    type = WaitForSimulationBack;

}
/*软关机指令/20170102 节电率测试指令 下位机得到指令后回复 “OK”
 * 间隔5秒后发送 “ETETETET”指令恢复到正常工作状态
*/
void Regulator::shutDownHardware()
{
    if(type != IDLE)return;
/*/    orderClear(ShutDownOrder);
    //endtype = WaitForShutDownEnd;
    ShutDownOrder.head = QString("2aeb").toLocal8Bit();
    ShutDownOrder.head = QByteArray::fromHex(ShutDownOrder.head);
    ShutDownOrder.address = QString("02").toLocal8Bit();
    ShutDownOrder.address = QByteArray::fromHex(ShutDownOrder.address);
    ShutDownOrder.commandtype = QString("04").toLocal8Bit();
    ShutDownOrder.commandtype = QByteArray::fromHex(ShutDownOrder.commandtype);
    ShutDownOrder.datalength = QString("01").toLocal8Bit();
    ShutDownOrder.datalength = QByteArray::fromHex(ShutDownOrder.datalength);
    ShutDownOrder.data = QString("00").toLocal8Bit();
    ShutDownOrder.data = QByteArray::fromHex(ShutDownOrder.data);
    ShutDownOrder.checkcode = QString("07").toLocal8Bit();
    ShutDownOrder.checkcode = QByteArray::fromHex(ShutDownOrder.checkcode);
    ShutDownOrder.tail = QString("ad").toLocal8Bit();
    ShutDownOrder.tail = QByteArray::fromHex(ShutDownOrder.tail);
    //发送指令
    sendInstruction(ShutDownOrder);
    状态改变 发送消息
    20170102/*/
    testSaving = QString("42540d").toLocal8Bit();//"BT<cr>"0x42 0x54 0x0d
    testSaving = QByteArray::fromHex(testSaving);
    regulatorPort->write(testSaving);
    timeoutTimer->start(5000);//超时3s
    type = WaitForShutDownBack;
    qDebug()<<"BT SEND";
    qDebug()<<type<<"after bt";

}
//发送阈值指令
void Regulator::sendThershold(int percentage, DataPoint voltage, DataPoint newData)
{
    if(type != IDLE)return;
    MinVoltageData = voltage;
    NewVoltageData = newData;
/*/    orderClear(ThersholdOrder);
    char checkcode;
    ThersholdOrder.head = QString("2aeb").toLocal8Bit();
    ThersholdOrder.head = QByteArray::fromHex(ThersholdOrder.head);
    ThersholdOrder.address = QString("02").toLocal8Bit();
    ThersholdOrder.address = QByteArray::fromHex(ThersholdOrder.address);
    ThersholdOrder.commandtype = QString("06").toLocal8Bit();
    ThersholdOrder.commandtype = QByteArray::fromHex(ThersholdOrder.commandtype);
    ThersholdOrder.datalength = QString("01").toLocal8Bit();
    ThersholdOrder.datalength = QByteArray::fromHex(ThersholdOrder.datalength);
    ThersholdOrder.data.clear();
    //qDebug()<<ThersholdOrder.data;
    ThersholdOrder.data.append(percentage);
    checkcode=0x02^0x06^0x01^percentage;
    //qDebug()<<"ckeckcode "<<ThersholdOrder.checkcode;
    ThersholdOrder.checkcode.clear();
    ThersholdOrder.checkcode.append(checkcode);
    ThersholdOrder.tail = QString("ad").toLocal8Bit();
    ThersholdOrder.tail = QByteArray::fromHex(ThersholdOrder.tail);
    //发送指令
    sendInstruction(ThersholdOrder);
    //状态改变 发送消息/*/
    SavingAction = QString("42520d").toLocal8Bit();
    SavingAction = QByteArray::fromHex(SavingAction);
    regulatorPort->write(SavingAction);
    timeoutTimer->start(5000);//超时3s
    type = WaitForThersholdBack;
    qDebug()<<"BR send";

}

bool Regulator::isRegulatorFound()
{
    return 1;
}
//软开机指令
void Regulator::startHardware()
{
/*//    if(type != IDLE)return;
    orderClear(StartOrder);
    //endtype = WaitForStartEnd;
    StartOrder.head = QString("2aeb").toLocal8Bit();
    StartOrder.head = QByteArray::fromHex(StartOrder.head);
    StartOrder.address = QString("02").toLocal8Bit();
    StartOrder.address = QByteArray::fromHex(StartOrder.address);
    StartOrder.commandtype = QString("03").toLocal8Bit();
    StartOrder.commandtype = QByteArray::fromHex(StartOrder.commandtype);
    StartOrder.datalength = QString("01").toLocal8Bit();
    StartOrder.datalength = QByteArray::fromHex(StartOrder.datalength);
    StartOrder.data = QString("00").toLocal8Bit();
    StartOrder.data = QByteArray::fromHex(StartOrder.data);
    StartOrder.checkcode = QString("00").toLocal8Bit();
    StartOrder.checkcode = QByteArray::fromHex(StartOrder.checkcode);
    StartOrder.tail = QString("ad").toLocal8Bit();
    StartOrder.tail = QByteArray::fromHex(StartOrder.tail);
    //发送指令
    sendInstruction(StartOrder);
    //状态改变 发送消息
    type = WaitForStartBack;*/
}

/*
 * 解析数据 主要是收到回复的 “OK" "ER"要重发
 * 注意每次readytoread的时候已经接受了完整的数据
*/
void Regulator::parseData()
{
    qDebug()<<"1";
    QByteArray temp = regulatorPort->readAll();
    qDebug()<<"2";
    tempbuffer.append(temp);
    qDebug()<<tempbuffer;
    if(!tempbuffer.contains("\r"))
    {
        return;
    }
    QTime *waittime = new QTime;


    if(tempbuffer.contains("OK"))
    {
       qDebug()<<type<<"before";
       qDebug()<<"read  OK,,";
       ReSendCount = 0;//重发次数清零
       timeoutTimer->stop();//停止发送超时计时
            //waittime->restart();
            r_state = RIDLE;
            switch (type)
            {
            case WaitForStartBack:
                qDebug()<<"type start change";
                type = IDLE;
                //endtimeTimer->start(MAX_ENDTIMEOUT);
                emit startBack();
                break;
            case WaitForShutDownBack:
                qDebug()<<"type shutdown change";
                type = WaitForShutDownEnd;
                endtimeTimer->start(MAX_ENDTIMEOUT);//等待动作结束
                emit shutDownBack();
                //return;
                break;
            case WaitForSimulationBack:
                qDebug()<<"type sim change";
                type = IDLE;
                emit simulationBack();
                break;
            case WaitForDataCheckBack:
                qDebug()<<"data back ok";
                type = WaitForDataCheckEnd;//
                endtimeTimer->start(MAX_ENDTIMEOUT);
                //emit dataSendBack();
                break;
            case WaitForThersholdBack:// BR回复OK
                qDebug()<<"type thershold change";
                //emit thersholdBack();
                type = WaitForThersholdEnd;//
                endtimeTimer->start(MAX_ENDTIMEOUT);//等待动作结束
                //sendData(MinVoltageData,NewVoltageData);
                break;
            default:
                qDebug()<<type<<"de";
                break;
            }
            tempbuffer.clear();
        }
//        break;
//    case RM_E://回复ER
        if(tempbuffer.contains("ER"))
        {
/*            r_state = RIDLE;
 *
            timeoutTimer->stop();//停止延时计时
            ReSendCount += 1;
            if(ReSendCount > MAX_RESEND_COUNT)
            {

                ReSendCount = 0;
                emit regulatorError();
                qDebug()<<"error emit";
                return;
            }
            //qDebug()<<"er coount"<<ReSendCount;
            switch (type)
            {
            case WaitForSimulationBack:
                sendInstruction(SimulationOrder);
                break;
            case WaitForStartBack:
                sendInstruction(StartOrder);
                break;
            case WaitForShutDownBack:
                sendInstruction(ShutDownOrder);
                break;
            case WaitForDataCheckBack:
                sendInstruction(DataOrder);
            case WaitForThersholdBack:
                sendInstruction(ThersholdOrder);
                break;
            default:
                break;
            }*/
            if(type == WaitForThersholdEnd)
            {
                qDebug()<<"ER RECEIVED";
                type = IDLE;
                sendData(MinVoltageData,NewVoltageData);//发送数据
            }
            if(type == WaitForDataCheckEnd)
            {
                type = IDLE;
                qDebug()<<"fuck data";
                emit monitorActionEnd();//调试结束
            }
            tempbuffer.clear();
        }
        //ET 完成节电动作
        if(tempbuffer.contains("ET"))
        {
            qDebug()<<"ET back";
            endtimeTimer->stop();//动作超时计时停止
            switch (type)
            {
            case WaitForStartEnd:
                type = IDLE;
                //简单延时处理
                emit startOver();
                break;
            case WaitForShutDownEnd:
                qDebug()<<"ET DONE";
                type = IDLE;
                waittime->restart();
                while(1)
                {
                    if(waittime->elapsed()>500)break;//等待500ms后读取数据
                }
                emit shutDownOver();
                qDebug()<<type<<"after done";
                break;
            default:
                break;

            }
            tempbuffer.clear();
        }


}


void Regulator::handleTimeout()
{
        timeoutTimer->stop();
        type = IDLE;
        //emit regulatorError();
}

void Regulator::handleEndTimeout()
{
    endtimeTimer->stop();
    //emit regulatorError();
}

void Regulator::orderClear(regulatorinstruction order)
{
    order.head.clear();

    order.address.clear();
    order.commandtype.clear();
    order.datalength.clear();
    order.data.clear();
    //qDebug()<<"data clear 1"<<order.head;
    order.checkcode.clear();
   // qDebug()<<"checkcode clear 1"<<order.head;
    order.tail.clear();
}

void Regulator::connectname(QString name)
{
    regulatorPort=new QSerialPort(this);
    RegulatorFound = true;
    regulatorPort->setPortName(name);

    regulatorPort->setBaudRate(QSerialPort::Baud9600);
    regulatorPort->setDataBits(QSerialPort::Data8);
    regulatorPort->setParity(QSerialPort::NoParity);
    regulatorPort->setStopBits(QSerialPort::OneStop);
    regulatorPort->setFlowControl(QSerialPort::NoFlowControl);
    regulatorPort->open(QIODevice::ReadWrite);
    regulatorPort->clear();
    connect(regulatorPort,&QSerialPort::readyRead,this,&Regulator::parseData);
    return;

}

void Regulator::sendInstruction(regulatorinstruction order)
{
    regulatorPort->write(order.head);
    regulatorPort->write(order.address);
    regulatorPort->write(order.commandtype);
    regulatorPort->write(order.datalength);
    regulatorPort->write(order.data);
    regulatorPort->write(order.checkcode);
    regulatorPort->write(order.tail);
    timeoutTimer->start(TIMEOUT_INTERVAL);
}
//返回data异或
char Regulator::dataIntoString(QByteArray &data, DataPoint &voltage, DataPoint &newdata)
{
    int tempbuffer;
    char checkcode = 0;
    tempbuffer = int(newdata.va * 10);//
    data.append(((tempbuffer&0xff00)>>8));
    checkcode = data.at(data.size()-1);
    data.append(((tempbuffer&0xff)));
    checkcode ^= data.at(data.size()-1);
    tempbuffer = int(newdata.vb * 10);//
    data.append(((tempbuffer&0xff00)>>8));
    checkcode ^= data.at(data.size()-1);
    data.append(((tempbuffer&0xff)));
    checkcode ^= data.at(data.size()-1);
    tempbuffer = int(newdata.vc * 10);//
    data.append(((tempbuffer&0xff00)>>8));
    checkcode ^= data.at(data.size()-1);
    data.append(((tempbuffer&0xff)));
    checkcode ^= data.at(data.size()-1);
    tempbuffer = int(newdata.ia * 10);//
    data.append(((tempbuffer&0xff00)>>8));
    checkcode ^= data.at(data.size()-1);
    data.append(((tempbuffer&0xff)));
    checkcode ^= data.at(data.size()-1);
    tempbuffer = int(newdata.ib * 10);//
    data.append(((tempbuffer&0xff00)>>8));
    checkcode ^= data.at(data.size()-1);
    data.append(((tempbuffer&0xff)));
    checkcode ^= data.at(data.size()-1);
    tempbuffer = int(newdata.ic * 10);//
    data.append(((tempbuffer&0xff00)>>8));
    checkcode ^= data.at(data.size()-1);
    data.append(((tempbuffer&0xff)));
    checkcode ^= data.at(data.size()-1);
    tempbuffer = int(newdata.epa / POWERRATE);//
    data.append(((tempbuffer&0xff00)>>8));
    checkcode ^= data.at(data.size()-1);
    data.append(((tempbuffer&0xff)));
    checkcode ^= data.at(data.size()-1);
    tempbuffer = int(newdata.epb / POWERRATE);//
    data.append(((tempbuffer&0xff00)>>8));
    checkcode ^= data.at(data.size()-1);
    data.append(((tempbuffer&0xff)));
    checkcode ^= data.at(data.size()-1);
    tempbuffer = int(newdata.epc / POWERRATE);//
    data.append(((tempbuffer&0xff00)>>8));
    checkcode ^= data.at(data.size()-1);
    data.append(((tempbuffer&0xff)));
    checkcode ^= data.at(data.size()-1);
    tempbuffer = int(voltage.va * 10);//
    qDebug()<<"minvoltage va"<<voltage.va;
    data.append(((tempbuffer&0xff00)>>8));
    checkcode ^= data.at(data.size()-1);
    data.append(((tempbuffer&0xff)));
    checkcode ^= data.at(data.size()-1);
    tempbuffer = int(voltage.vb * 10);//
    qDebug()<<"minvoltage vb"<<voltage.vb;
    data.append(((tempbuffer&0xff00)>>8));
    checkcode ^= data.at(data.size()-1);
    data.append(((tempbuffer&0xff)));
    checkcode ^= data.at(data.size()-1);
    tempbuffer = int(voltage.vc * 10);//
    qDebug()<<"minvoltage vc"<<voltage.vc;
    data.append(((tempbuffer&0xff00)>>8));
    checkcode ^= data.at(data.size()-1);
    data.append(((tempbuffer&0xff)));
    checkcode ^= data.at(data.size()-1);

    return checkcode;
    //qDebug<<"data is "<<(unsigned char)data.data();
}





