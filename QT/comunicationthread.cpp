#include "comunicationthread.h"
#include <QDebug>
#include <QString>
comunicationThread::comunicationThread()
{
   // connect (_mainwindow, SIGNAL(digitalOutputChange), this, SLOT(digitalOutputChange()));

    qRegisterMetaType<rxBuffer_t>("rxBuffer_t");
    /*Su propósito es registrar la estructura creada para que pueda ser utilizado
      con el sistema de señales y slots de Qt y otros mecanismos de metatipos.
      Esto permite que objetos de ese tipo de dato sean transmitidos correctamente
      a través de señales y slots de Qt.*/
    rxBuffer.header = 0x1c;

    headerArray.append(rxBuffer.header);

}
comunicationThread::~comunicationThread()
{
    if (_serial.serial->isOpen())
    {
        _serial.serial->close();
    }
}


void comunicationThread::run()
{
    //Operaciones que se van a ejecutar en paralelo.
    rxBuffer_t  rxBuffer;
    unionRx_t   unionBuffer;


    dataBuffer.clear();
    bytesReceived = 0;


    while (!isInterruptionRequested())
    {
        if(_serial.serial->waitForReadyRead(100))
        {
            //if (serialTx())
            ///{
            qDebug()<<"Leyendo";
                data = _serial.serial->read(1);

                if (data == headerArray )
                {
                    qDebug()<<"header Encontrado";
                    do
                    {
                         qDebug()<<"Leyendo data Buena";
                        bytesReceived++;
                        dataBuffer.append(data);
                        data = _serial.serial->read(1);

                    }while (bytesReceived < sizeof(rxBuffer_t));
                }
                else
                {
                    data.clear();
                }

                if(bytesReceived >= sizeof(rxBuffer_t))
                {
                    if(dataBuffer.size() == sizeof(rxBuffer_t))
                    {
                        memcpy(unionBuffer.txBuffer_c, dataBuffer.constData(), sizeof(rxBuffer_t));
                    }
                    emit dataReceived(unionBuffer); // Emite la trama recibida
                    qDebug() << "\n Trama recibida: " << QByteArray(unionBuffer.txBuffer_c, sizeof(rxBuffer_t));
                    dataBuffer.clear();
                    bytesReceived = 0;
                }



          //  }
       }
    }
    //}*/
}
       /* if(_serial.serial->waitForReadyRead(200))
        {qDebug()<<"asd";
            QByteArray requestData = _serial.serial->readAll();
            qDebug()<< requestData;
            //qDebug()<< sizeof(requestData);

            for (int i=0; i<24; i++)
            {
                qDebug()<< requestData[i];
                //memcpy(&analog_input[i], &requestData[i*2], 2 );
                //qDebug()<< analog_input[i];
            }
            while (_serial.serial->waitForReadyRead(100))
            {
                qDebug()<< requestData;
                requestData += _serial.serial->readAll();
            }
            //const QString request = QString::fromUtf8(requestData);
           // emit this->request(request);*/


/*
        if(_serial.serial->waitForReadyRead(100))
        {
            if (_serial.serial->read(buffer, 24))
            {
                for (int i=0; i<8; i++)
                {
                    analog_input[i]= ((uint8_t)(buffer[i*2]) << 8) | (uint8_t)(buffer [(i*2)+1]);
                    qDebug() << analog_input[i];
                }

                qDebug() << "Trama";
            }
            else
            {
                qDebug()<<"no se recibio nada";
            }
        }
*/
bool comunicationThread::serialTx(void)
{
    char    txBuffer[3];


    txBuffer[0]= pwmDuty1;
    txBuffer[1]= pwmDuty2;
    txBuffer[3]= digitalOutputs;

     QByteArray byteArray(reinterpret_cast<const char*>(&txBuffer), sizeof(txBuffer));

    if (_serial.serial->isWritable())
    {
        if(_serial.serial->write(byteArray,3) == sizeof (txBuffer))
        {
           while (_serial.serial->waitForBytesWritten(10)){}
           qDebug() << "Enviando trama: " << byteArray;
           return 1;
        }
    }
    else
    {
       qDebug() << "No se envia nada";
        return 0;
    }
}

void comunicationThread::digitalOutputChange(uint8_t dChange)
{
    digitalOutputs = digitalOutputs ^ dChange;
    QString text = QString::number(digitalOutputs, 2);
    qDebug()<<"digital Output transformado"<< text;
    emit changeText(text);
}

void comunicationThread::analogOutput1Change(uint8_t aChange)
{
    pwmDuty1=aChange;
    qDebug()<<"cuetnas del duty 1: "<< pwmDuty1;
}

void comunicationThread::analogOutput2Change(uint8_t aChange)
{
    pwmDuty2=aChange;
    qDebug()<<"cuetnas del duty 2: "<< pwmDuty2;
}

