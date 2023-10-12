#include "serialcomunication.h"

serialComunication::serialComunication(QObject *parent)
    : QObject{parent}
{
    serial = new QSerialPort() ;
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
    serial ->open           (QIODevice::ReadWrite);
}
