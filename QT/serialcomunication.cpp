#include "serialcomunication.h"
#include <QDebug>
#include <QSerialPortInfo>
serialComunication::serialComunication(QObject *parent)
    : QObject{parent}
{
    serial = new QSerialPort() ;
    foreach(const QSerialPortInfo &serialInfo, QSerialPortInfo::availablePorts())
    {
        //qDebug()<<"Puerto Disponible: "<<serialInfo.portName();
        portName = serialInfo.portName();
    }
    portInit();
}

void serialComunication::portInit()
{
    serial ->setPortName    (portName);
    serial ->setBaudRate    (QSerialPort::Baud115200);
    serial ->setDataBits    (QSerialPort::Data8);
    serial ->setParity      (QSerialPort::NoParity);
    serial ->setStopBits    (QSerialPort::OneStop);
    serial ->setFlowControl (QSerialPort::NoFlowControl);
    if (serial ->open           (QIODevice::ReadWrite))
    {
        qDebug() << "Conectado al puerto serie" << serial->portName();
    }
    else
    {
        qDebug()<<"Error en la conexion con la PC";
    }

}
