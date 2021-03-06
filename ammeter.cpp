#include "ammeter.h"
#include <ctime>
#include <cstdlib>
#define BYTE_NUMBER_VOLTAGE 22
#define BYTE_NUMBER_CURRENT 25
#define BYTE_NUMBER_EFFECTIVE_POWER 28
#define BYTE_NUMBER_REACTIVE_POWER 28
#define BYTE_NUMBER_APPRENT_POWER 28
#define BYTE_NUMBER_POWER_FACTOR 24
#define MAX_FAILURE_COUNT 1
#ifndef TESTMODE
#define QT_NO_DEBUG_OUTPUT

Ammeter::Ammeter(QObject *parent) : QObject(parent)
{
    coefficient=300;//20161106 *currnt bianbi*  orgin coefficient = 6
    timeout=new QTimer(this);
    readTimer=new QTimer(this);
    initPort();
    initInstruction();
    initConnections();
    connect(timeout,&QTimer::timeout,this,&Ammeter::handleTimeOut);
    connect(readTimer,&QTimer::timeout,this,&Ammeter::getVoltage);

}

DataPoint Ammeter::getData()
{
    return latestData;
}

bool Ammeter::isAmmeterFound()
{
    return ammeterfound;
}

void Ammeter::initPort()
{
/*/    portReadAndWrite=new QSerialPort(this);
//    foreach (const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
//    {
//        QString portDescription=info.portName();
//        //if(portDescription.contains(QString("COM11")))
//        if(portDescription.contains(QString("ttyUSB0")))
//        {
//            portReadAndWrite->setPortName(portDescription);
//            ammeterfound = true;
//            //qDebug()<<"ammeter found";
//            portReadAndWrite->setBaudRate(QSerialPort::Baud9600);
//            portReadAndWrite->setDataBits(QSerialPort::Data8);
//            portReadAndWrite->setParity(QSerialPort::EvenParity);
//            portReadAndWrite->setStopBits(QSerialPort::OneStop);
//            portReadAndWrite->setFlowControl(QSerialPort::NoFlowControl);
//            portReadAndWrite->open(QIODevice::ReadWrite);
//            connect(portReadAndWrite,&QSerialPort::readyRead,this,&Ammeter::parseData);
//            connect(portReadAndWrite,&QSerialPort::bytesWritten,this,&Ammeter::startTimeoutTimer);
//            readTimer->start(1000);
//            return;
//        }
//    }
//    //ammeterfound = false;
//    //emit ammeterNotFound();
//    //qDebug()<<"ammeter not found";
    return;/*/


}

void Ammeter::initInstruction()
{
    m_readType=NoneType;
    m_instruction.voltageInstruction=QString("68aaaaaaaaaaaa68110433323435af16").toLocal8Bit();
    m_instruction.currentInstruction=QString("68aaaaaaaaaaaa68110433323535b016").toLocal8Bit();
    m_instruction.effectivePowerInstruction=QString("68aaaaaaaaaaaa68110433323635b116").toLocal8Bit();
    m_instruction.reactivePowerInstruction=QString("68aaaaaaaaaaaa68110433323735b216").toLocal8Bit();
    m_instruction.apparentPowerInstruction=QString("68aaaaaaaaaaaa68110433323835b316").toLocal8Bit();
    m_instruction.powerFactorInstruction=QString("68aaaaaaaaaaaa68110433323935b416").toLocal8Bit();
    m_instruction.voltageInstruction=QByteArray::fromHex(m_instruction.voltageInstruction);
    m_instruction.currentInstruction=QByteArray::fromHex(m_instruction.currentInstruction);
    m_instruction.effectivePowerInstruction=QByteArray::fromHex(m_instruction.effectivePowerInstruction);
    m_instruction.reactivePowerInstruction=QByteArray::fromHex( m_instruction.reactivePowerInstruction);
    m_instruction.apparentPowerInstruction=QByteArray::fromHex(m_instruction.apparentPowerInstruction);
    m_instruction.powerFactorInstruction=QByteArray::fromHex(m_instruction.powerFactorInstruction);
}

void Ammeter::initConnections()
{
    connect(this,&Ammeter::voltageDataGot,this,&Ammeter::getCurrent);
    connect(this,&Ammeter::currentDataGot,this,&Ammeter::getEffectivePower);
    connect(this,&Ammeter::effectivePowerDataGot,this,&Ammeter::getReactivePower);
    connect(this,&Ammeter::reactivePowerDataGot,this,&Ammeter::getApparentPower);
    connect(this,&Ammeter::apparentPowerDataGot,this,&Ammeter::getPowerFactor);
    connect(this,&Ammeter::powerFactorDataGot,this,&Ammeter::startReadTimer);//等待下一次计数
    connect(this,&Ammeter::powerFactorDataGot,this,&Ammeter::getDataOver);//读完发送给dataprocessor
}

void Ammeter::initData()
{
    latestData.va=0;latestData.vb=0;latestData.vc=0;
    latestData.ia=0;latestData.ib=0;latestData.ic=0;
    latestData.epa=0;latestData.epb=0;latestData.epc=0;latestData.eps=0;
    latestData.rpa=0;latestData.rpb=0;latestData.rpc=0;latestData.rps=0;
    latestData.apa=0;latestData.apb=0;latestData.apc=0;latestData.aps=0;
    latestData.pfa=0;latestData.pfb=0;latestData.pfc=0;latestData.pfs=0;
    failureCount=0;
    m_readType=NoneType;
}

datatype Ammeter::minus33(QByteArray data)
{
    datatype result=0;
    QByteArray temp=data.mid(0,1);
    bool ok;
    result+=10.0*(temp.toInt(&ok,16)-3);
    temp=data.mid(1,1);
    result+=1.0*((temp.toInt(&ok,16)-3));
    return result;
}

void Ammeter::parseData()
{
    switch(m_readType)
    {
    case ReadVoltage:
        buffer.append(portReadAndWrite->readAll());
        if(buffer.size()==BYTE_NUMBER_VOLTAGE)
        {
            ////qDebug()<<"read type is "<<m_readType<<endl;
            ////qDebug()<<"the number of bytes that have been read is "<<buffer.size()<<endl;
            timeout->stop();
            failureCount=0;
            QByteArray AL=buffer.mid(14,1);
            QByteArray AH=buffer.mid(15,1);
            datatype A=(minus33(AH.toHex()))*10+(minus33(AL.toHex()))*0.1;
            QByteArray BL=buffer.mid(16,1);
            QByteArray BH=buffer.mid(17,1);
            datatype B=(minus33(BH.toHex()))*10+(minus33(BL.toHex()))*0.1;
            QByteArray CL=buffer.mid(18,1);
            QByteArray CH=buffer.mid(19,1);
            datatype C=(minus33(CH.toHex()))*10+minus33(CL.toHex())*0.1;
            ////qDebug()<<"CL is "<<CL.toHex()<<endl;
            ////qDebug()<<"CH is "<<CH.toHex()<<endl;
            ////qDebug()<<"get voltage data A "<<A<<endl;
            latestData.va=A;
            latestData.vb=B;
            latestData.vc=C;
            buffer.clear();
            emit voltageDataGot();
        }
        else if(buffer.size()>BYTE_NUMBER_VOLTAGE)
        {
            timeout->stop();
            buffer.clear();
            getVoltage();
        }
        break;
    case ReadCurrent:
        buffer.append(portReadAndWrite->readAll());
        if(buffer.size()==BYTE_NUMBER_CURRENT)
        {
            timeout->stop();
            failureCount=0;
            QByteArray AL=buffer.mid(14,1);
            QByteArray AM=buffer.mid(15,1);
            QByteArray AH=buffer.mid(16,1);
            datatype A=(minus33(AH.toHex()))*10+(minus33(AM.toHex()))*0.1+(minus33(AL.toHex()))*0.001;
            QByteArray BL=buffer.mid(17,1);
            QByteArray BM=buffer.mid(18,1);
            QByteArray BH=buffer.mid(19,1);
            datatype B=(minus33(BH.toHex()))*10+(minus33(BM.toHex()))*0.1+(minus33(BL.toHex()))*0.001;
            QByteArray CL=buffer.mid(20,1);
            QByteArray CM=buffer.mid(21,1);
            QByteArray CH=buffer.mid(22,1);
            datatype C=(minus33(CH.toHex()))*10+(minus33(CM.toHex()))*0.1+(minus33(CL.toHex()))*0.001;
            //qDebug()<<"get current data A "<<A<<endl;
            latestData.ia=coefficient*A;
            latestData.ib=coefficient*B;
            latestData.ic=coefficient*C;
            buffer.clear();
            emit currentDataGot();
        }
        else if(buffer.size()>BYTE_NUMBER_CURRENT)
        {
            timeout->stop();
            buffer.clear();
            getCurrent();
        }
        break;
    case ReadEffectivePower:
        buffer.append(portReadAndWrite->readAll());
        if(buffer.size()==BYTE_NUMBER_EFFECTIVE_POWER)
        {
            timeout->stop();
            failureCount=0;
            QByteArray SL=buffer.mid(14,1);
            QByteArray SM=buffer.mid(15,1);
            QByteArray SH=buffer.mid(16,1);
            datatype S=(minus33(SH.toHex()))+(minus33(SM.toHex()))*0.01+(minus33(SL.toHex()))*0.0001;
            QByteArray AL=buffer.mid(17,1);
            QByteArray AM=buffer.mid(18,1);
            QByteArray AH=buffer.mid(19,1);
            datatype A=(minus33(AH.toHex()))+(minus33(AM.toHex()))*0.01+(minus33(AL.toHex()))*0.0001;
            QByteArray BL=buffer.mid(20,1);
            QByteArray BM=buffer.mid(21,1);
            QByteArray BH=buffer.mid(22,1);
            datatype B=(minus33(BH.toHex()))+(minus33(BM.toHex()))*0.01+(minus33(BL.toHex()))*0.0001;
            QByteArray CL=buffer.mid(23,1);
            QByteArray CM=buffer.mid(24,1);
            QByteArray CH=buffer.mid(25,1);
            datatype C=(minus33(CH.toHex()))+(minus33(CM.toHex()))*0.01+(minus33(CL.toHex()))*0.0001;
            ////qDebug()<<"get effectivePower data A "<<A<<endl;
            latestData.eps=coefficient*S;
            latestData.epa=coefficient*A;
            latestData.epb=coefficient*B;
            latestData.epc=coefficient*C;
            buffer.clear();
            emit effectivePowerDataGot();
        }
        else if(buffer.size()>BYTE_NUMBER_EFFECTIVE_POWER)
        {
            timeout->stop();
            buffer.clear();
            getEffectivePower();
        }
        break;
    case ReadReactivePower:
        buffer.append(portReadAndWrite->readAll());
        if(buffer.size()==BYTE_NUMBER_REACTIVE_POWER)
        {
            timeout->stop();
            failureCount=0;
            QByteArray SL=buffer.mid(14,1);
            QByteArray SM=buffer.mid(15,1);
            QByteArray SH=buffer.mid(16,1);
            datatype S=(minus33(SH.toHex()))+(minus33(SM.toHex()))*0.01+(minus33(SL.toHex()))*0.0001;
            QByteArray AL=buffer.mid(17,1);
            QByteArray AM=buffer.mid(18,1);
            QByteArray AH=buffer.mid(19,1);
            datatype A=(minus33(AH.toHex()))+(minus33(AM.toHex()))*0.01+(minus33(AL.toHex()))*0.0001;
            QByteArray BL=buffer.mid(20,1);
            QByteArray BM=buffer.mid(21,1);
            QByteArray BH=buffer.mid(22,1);
            datatype B=(minus33(BH.toHex()))+(minus33(BM.toHex()))*0.01+(minus33(BL.toHex()))*0.0001;
            QByteArray CL=buffer.mid(23,1);
            QByteArray CM=buffer.mid(24,1);
            QByteArray CH=buffer.mid(25,1);
            datatype C=(minus33(CH.toHex()))+(minus33(CM.toHex()))*0.01+(minus33(CL.toHex()))*0.0001;
            ////qDebug()<<"get reactivePower data A "<<A<<endl;
            latestData.rps=coefficient*S;
            latestData.rpa=coefficient*A;
            latestData.rpb=coefficient*B;
            latestData.rpc=coefficient*C;
            buffer.clear();
            emit reactivePowerDataGot();
        }
        else if(buffer.size()>BYTE_NUMBER_REACTIVE_POWER)
        {
            timeout->stop();
            buffer.clear();
            getReactivePower();
        }
        break;
    case ReadApparentPower:
        buffer.append(portReadAndWrite->readAll());
        if(buffer.size()==BYTE_NUMBER_APPRENT_POWER)
        {
            timeout->stop();
            failureCount=0;
            QByteArray SL=buffer.mid(14,1);
            QByteArray SM=buffer.mid(15,1);
            QByteArray SH=buffer.mid(16,1);
            datatype S=(minus33(SH.toHex()))+(minus33(SM.toHex()))*0.01+(minus33(SL.toHex()))*0.0001;
            QByteArray AL=buffer.mid(17,1);
            QByteArray AM=buffer.mid(18,1);
            QByteArray AH=buffer.mid(19,1);
            datatype A=(minus33(AH.toHex()))+(minus33(AM.toHex()))*0.01+(minus33(AL.toHex()))*0.0001;
            QByteArray BL=buffer.mid(20,1);
            QByteArray BM=buffer.mid(21,1);
            QByteArray BH=buffer.mid(22,1);
            datatype B=(minus33(BH.toHex()))+(minus33(BM.toHex()))*0.01+(minus33(BL.toHex()))*0.0001;
            QByteArray CL=buffer.mid(23,1);
            QByteArray CM=buffer.mid(24,1);
            QByteArray CH=buffer.mid(25,1);
            datatype C=(minus33(CH.toHex()))+(minus33(CM.toHex()))*0.01+(minus33(CL.toHex()))*0.0001;
            ////qDebug()<<"get apparentPower data A "<<A<<endl;
            latestData.aps=coefficient*S;
            latestData.apa=coefficient*A;
            latestData.apb=coefficient*B;
            latestData.apc=coefficient*C;
            buffer.clear();
            emit apparentPowerDataGot();
        }
        else if(buffer.size()>BYTE_NUMBER_APPRENT_POWER)
        {
            timeout->stop();
            buffer.clear();
            getApparentPower();
        }
        break;
    case ReadPowerFactor:
        buffer.append(portReadAndWrite->readAll());
        if(buffer.size()==BYTE_NUMBER_POWER_FACTOR)
        {
            timeout->stop();
            failureCount=0;
            QByteArray SL=buffer.mid(14,1);
            QByteArray SH=buffer.mid(15,1);
            datatype S=(minus33(SH.toHex()))*0.1+(minus33(SL.toHex()))*0.001;
            QByteArray AL=buffer.mid(16,1);
            QByteArray AH=buffer.mid(17,1);
            datatype A=(minus33(AH.toHex()))*0.1+(minus33(AL.toHex()))*0.001;
            QByteArray BL=buffer.mid(18,1);
            QByteArray BH=buffer.mid(19,1);
            datatype B=(minus33(BH.toHex()))*0.1+(minus33(BL.toHex()))*0.001;
            QByteArray CL=buffer.mid(20,1);
            QByteArray CH=buffer.mid(21,1);
            datatype C=(minus33(CH.toHex()))*0.1+(minus33(CL.toHex()))*0.001;
            ////qDebug()<<"get powerFactor data A "<<A<<endl;
            latestData.pfs=S;
            latestData.pfa=A;
            latestData.pfb=B;
            latestData.pfc=C;
            buffer.clear();
            emit powerFactorDataGot();
        }
        else if(buffer.size()>BYTE_NUMBER_POWER_FACTOR)
        {
            timeout->stop();
            buffer.clear();
            getPowerFactor();
        }
        break;
    default:
        //qDebug()<<"the default type is "<<m_readType<<endl;
        break;
    }
}

void Ammeter::startTimeoutTimer()
{
    timeout->start(1000);
}

void Ammeter::handleTimeOut()
{
    if(failureCount>MAX_FAILURE_COUNT)
    {
        //emit ammeterError();
        timeout->stop();//停止超时计时
        initData();//返回零值数据
        emit getDataOver();//发送零值数据
    }
    else
    {

        failureCount++;
        if(m_readType==ReadVoltage)
        {
            timeout->stop();
            buffer.clear();
            getVoltage();
            //qDebug()<<"lost voltage"<<endl;
        }
        else if(m_readType==ReadCurrent)
        {
            timeout->stop();
            buffer.clear();
            getCurrent();
            //qDebug()<<"lost current"<<endl;
        }
        else if(m_readType==ReadEffectivePower)
        {
            timeout->stop();
            buffer.clear();
            getEffectivePower();
            //qDebug()<<"lost effectivePower"<<endl;
        }
        else if(m_readType==ReadReactivePower)
        {
            timeout->stop();
            buffer.clear();
            getReactivePower();
            //qDebug()<<"lost reactivePower"<<endl;
        }
        else if(m_readType==ReadApparentPower)
        {
            timeout->stop();
            buffer.clear();
            getApparentPower();
            //qDebug()<<"lost apparentPower"<<endl;
        }
        else if(m_readType==ReadPowerFactor)
        {
            timeout->stop();
            buffer.clear();
            getPowerFactor();
            //qDebug()<<"lost PowerFactor"<<endl;
        }
    }
}

void Ammeter::getVoltage()
{
   // //qDebug()<<"before read voltage"<<endl;
    readTimer->stop();
    m_readType=ReadVoltage;
    portReadAndWrite->write(m_instruction.voltageInstruction);
    ////qDebug()<<"fetch voltage"<<endl;
}

void Ammeter::getCurrent()
{
   // //qDebug()<<"before read current"<<endl;
    m_readType=ReadCurrent;
    portReadAndWrite->write(m_instruction.currentInstruction);
    ////qDebug()<<"fetch current"<<endl;
}

void Ammeter::getEffectivePower()
{
   // //qDebug()<<"before read effectivePower"<<endl;
    m_readType=ReadEffectivePower;
    portReadAndWrite->write(m_instruction.effectivePowerInstruction);
    ////qDebug()<<"fetch effective Power"<<endl;

}

void Ammeter::getReactivePower()
{
    ////qDebug()<<"before read reactivePower"<<endl;
    m_readType=ReadReactivePower;
    portReadAndWrite->write(m_instruction.reactivePowerInstruction);
   // //qDebug()<<"fetch reactive Power"<<endl;

}

void Ammeter::getApparentPower()
{
   // //qDebug()<<"before read apparentPower"<<endl;
    m_readType=ReadApparentPower;
    portReadAndWrite->write(m_instruction.apparentPowerInstruction);
   // //qDebug()<<"fetch Apparent Power"<<endl;

}

void Ammeter::getPowerFactor()
{
   // //qDebug()<<"before read powerFactor"<<endl;
    m_readType=ReadPowerFactor;
    portReadAndWrite->write(m_instruction.powerFactorInstruction);
    ////qDebug()<<"fetch power factor"<<endl;

}

void Ammeter::startReadTimer()
{
    readTimer->start(1000);
}

void Ammeter::connectname(QString name)
{
    portReadAndWrite=new QSerialPort(this);
    portReadAndWrite->setPortName(name);
    ammeterfound = true;
    portReadAndWrite->setBaudRate(QSerialPort::Baud9600);
    portReadAndWrite->setDataBits(QSerialPort::Data8);
    portReadAndWrite->setParity(QSerialPort::EvenParity);
    portReadAndWrite->setStopBits(QSerialPort::OneStop);
    portReadAndWrite->setFlowControl(QSerialPort::NoFlowControl);
    portReadAndWrite->open(QIODevice::ReadWrite);
    connect(portReadAndWrite,&QSerialPort::readyRead,this,&Ammeter::parseData);
    connect(portReadAndWrite,&QSerialPort::bytesWritten,this,&Ammeter::startTimeoutTimer);
    readTimer->start(1000);
    return;

}
/**
 * @brief Ammeter::setCoefficient
 * @param coef
 */
void Ammeter::setCoefficient(float coef)
{
    coefficient = coef;
    //qDebug()<<"coef"<<coef;
}

#else
double random(double start, double end)
{
    return start + (end - start)*rand()/(RAND_MAX);
}
Ammeter::Ammeter(QObject *parent) : QObject(parent)
{
    //qDebug()<<"ammeter constructed"<<endl;
    srand(unsigned(time(0)));
    coefficient=6;
//    initPort();
//    initInstruction();
    // timeout=new QTimer(this);
    initConnections();
    readTimer=new QTimer(this);
    // connect(timeout,&QTimer::timeout,this,&Ammeter::handleTimeOut);
    connect(readTimer,&QTimer::timeout,this,&Ammeter::getVoltage);
    startReadTimer();
}

DataPoint Ammeter::getData()
{
    return latestData;
}

void Ammeter::initPort()
{

}

void Ammeter::initInstruction()
{
    m_readType=NoneType;
    m_instruction.voltageInstruction=QString("68aaaaaaaaaaaa68110433323435af16").toLocal8Bit();
    m_instruction.currentInstruction=QString("68aaaaaaaaaaaa68110433323535b016").toLocal8Bit();
    m_instruction.effectivePowerInstruction=QString("68aaaaaaaaaaaa68110433323635b116").toLocal8Bit();
    m_instruction.reactivePowerInstruction=QString("68aaaaaaaaaaaa68110433323735b216").toLocal8Bit();
    m_instruction.apparentPowerInstruction=QString("68aaaaaaaaaaaa68110433323835b316").toLocal8Bit();
    m_instruction.powerFactorInstruction=QString("68aaaaaaaaaaaa68110433323935b416").toLocal8Bit();
    m_instruction.voltageInstruction=QByteArray::fromHex(m_instruction.voltageInstruction);
    m_instruction.currentInstruction=QByteArray::fromHex(m_instruction.currentInstruction);
    m_instruction.effectivePowerInstruction=QByteArray::fromHex(m_instruction.effectivePowerInstruction);
    m_instruction.reactivePowerInstruction=QByteArray::fromHex( m_instruction.reactivePowerInstruction);
    m_instruction.apparentPowerInstruction=QByteArray::fromHex(m_instruction.apparentPowerInstruction);
    m_instruction.powerFactorInstruction=QByteArray::fromHex(m_instruction.powerFactorInstruction);
}

void Ammeter::initConnections()
{
    connect(this,&Ammeter::voltageDataGot,this,&Ammeter::getCurrent);
    connect(this,&Ammeter::currentDataGot,this,&Ammeter::getEffectivePower);
    connect(this,&Ammeter::effectivePowerDataGot,this,&Ammeter::getReactivePower);
    connect(this,&Ammeter::reactivePowerDataGot,this,&Ammeter::getApparentPower);
    connect(this,&Ammeter::apparentPowerDataGot,this,&Ammeter::getPowerFactor);
    connect(this,&Ammeter::powerFactorDataGot,this,&Ammeter::startReadTimer);
    connect(this,&Ammeter::powerFactorDataGot,this,&Ammeter::getDataOver);
}

void Ammeter::initData()
{
    latestData.va=0;latestData.vb=0;latestData.vc=0;
    latestData.ia=0;latestData.ib=0;latestData.ic=0;
    latestData.epa=0;latestData.epb=0;latestData.epc=0;latestData.eps=0;
    latestData.rpa=0;latestData.rpb=0;latestData.rpc=0;latestData.rps=0;
    latestData.apa=0;latestData.apb=0;latestData.apc=0;latestData.aps=0;
    latestData.pfa=0;latestData.pfb=0;latestData.pfc=0;latestData.pfs=0;
    failureCount=0;
    m_readType=NoneType;
}

datatype Ammeter::minus33(QByteArray data)
{
    datatype result=0;
    QByteArray temp=data.mid(0,1);
    bool ok;
    result+=10.0*(temp.toInt(&ok,16)-3);
    temp=data.mid(1,1);
    result+=1.0*((temp.toInt(&ok,16)-3));
    return result;
}

void Ammeter::parseData()
{

}

void Ammeter::startTimeoutTimer()
{
    timeout->start(1000);
}

void Ammeter::handleTimeOut()
{

}

void Ammeter::getVoltage()
{
    //qDebug()<<"before read voltage"<<endl;
    readTimer->stop();
    m_readType=ReadVoltage;
    latestData.va=random(210,230);
    latestData.vb=random(210,230);
    latestData.vc=random(210,230);
    //qDebug()<<"votage data got"<<endl;
    //qDebug()<<"Phase A is "<<latestData.va<<endl;
    emit voltageDataGot();

}

void Ammeter::getCurrent()
{
    //qDebug()<<"before read current"<<endl;
    m_readType=ReadCurrent;
    latestData.ia=coefficient*random(1,5);
    latestData.ib=coefficient*random(1,5);
    latestData.ic=coefficient*random(1,5);
    emit currentDataGot();
}

void Ammeter::getEffectivePower()
{
    //qDebug()<<"before read effectivePower"<<endl;
    m_readType=ReadEffectivePower;
    latestData.epa=coefficient*random(3,9);
    latestData.epb=coefficient*random(3,9);
    latestData.epc=coefficient*random(3,9);
    latestData.eps=latestData.epa+latestData.epb+latestData.epc;
    emit effectivePowerDataGot();
}

void Ammeter::getReactivePower()
{
    //qDebug()<<"before read reactivePower"<<endl;
    m_readType=ReadReactivePower;
    latestData.rpa=coefficient*random(1,2);
    latestData.rpb=coefficient*random(1,2);
    latestData.rpc=coefficient*random(1,2);
    latestData.rps=latestData.rpa+latestData.rpb+latestData.rpc;
    emit reactivePowerDataGot();
}

void Ammeter::getApparentPower()
{
    //qDebug()<<"before read apparentPower"<<endl;
    m_readType=ReadApparentPower;
    latestData.apa=coefficient*random(12,15);
    latestData.apb=coefficient*random(12,15);
    latestData.apc=coefficient*random(12,15);
    latestData.aps=latestData.apa+latestData.apb+latestData.apc;
    emit apparentPowerDataGot();
}

void Ammeter::getPowerFactor()
{
    //qDebug()<<"before read powerFactor"<<endl;
    m_readType=ReadPowerFactor;
    latestData.pfa=random(0,1);
    latestData.pfb=random(0,1);
    latestData.pfc=random(0,1);
    latestData.pfs=random(0,1);
    emit powerFactorDataGot();
}

void Ammeter::startReadTimer()
{
    readTimer->start(1000);

}

void Ammeter::changeCoeffcient(float value)
{
    coefficient=value;

}

#endif
