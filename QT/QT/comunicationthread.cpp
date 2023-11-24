/*********************************************************************/
/*****Clase para manejar la comunicacion serial con hilos*************/
/*********************************************************************/


#include "comunicationthread.h"
#include <QDebug>
#include <QString>
comunicationThread::comunicationThread() //Constructor. Estado inicial de variables, conexiones y configuraciones.
{


    qRegisterMetaType <rxBuffer_t>("rxBuffer_t");   /*Su propósito es registrar la estructura creada para que pueda ser utilizado */
    qRegisterMetaType <unionTx_t >("unionTx_t");    /*con el sistema de señales y slots de Qt y otros mecanismos de metatipos.    */
    qRegisterMetaType <txBuffer_t>("txBuffer_t");   /*Esto permite que objetos de ese tipo de dato sean transmitidos correctamente*/
                                                    /*a través de señales y slots de Qt.                                          */

    rxBuffer.header = 0x1c;                 //header para identificar datos validos que vienen por puerto serial
    unionTx.txBuffer.header         = 0x1c;
    headerArray.append(rxBuffer.header);    //header array es tipo byte array. Se le da el valor del header declarado. Es la variable que se usa para chequear el header obtenido de la comunicacion
    unionTx.txBuffer.analogOutput1  = 0;
    unionTx.txBuffer.analogOutput2  = 0;

    connect(this, SIGNAL(serialSend()),this,SLOT(serialTx()));
}
comunicationThread::~comunicationThread() // Destructor.
{
    if (_serial.serial->isOpen())
    {
        _serial.serial->close();
    }
}


void comunicationThread::run() //Operaciones que se van a ejecutar en el hilo en paralelo.
{
    unionRx_t   unionBuffer; // Variable de la union de recepcion donde se almacenaran los datos recibidos

    dataBuffer.clear();
    bytesReceived = 0;


    while (!isInterruptionRequested())
    {
        if(_serial.serial->waitForReadyRead(100))
        {
            data = _serial.serial->read(1);

            if (data == headerArray )
            {
                dataBuffer.append(data);
                data = _serial.serial->read(18);
                dataBuffer.append(data);

                if(dataBuffer.size() >=19)
                {
                    memcpy(unionBuffer.rxBuffer_c, dataBuffer.constData(),19);
                }
                emit dataReceived(unionBuffer); // Emite la trama recibida
                dataBuffer.clear();
                data.clear();
            }
            dataBuffer.clear();
            data.clear();
            _serial.serial->clear();
        }
    }
}

bool comunicationThread::serialTx(void)
{
     QByteArray byteArray(reinterpret_cast<const char*>(&unionTx), sizeof(unionTx)); // Se convierte arreglo char en BytesArray

    if (_serial.serial->isWritable())
    {
        if(_serial.serial->write(byteArray) == sizeof (unionTx))
        {
           while (_serial.serial->waitForBytesWritten(10)){}
           return 1;
        }
        else
        {
           return 0;
        }
    }
    else
    {
       //qDebug() << "No se envia nada";
        return 0;
    }
    return 0;
}

void comunicationThread::printDataInHex(){
    // Print the received data in hexadecimal
    QString hexData = "Received data in hex: ";

    for (uint16_t i = 0; i < dataBuffer.size(); i++)
    {
        hexData += QString::number(static_cast<unsigned char>(dataBuffer.at(i)), 16).rightJustified(2, '0').toUpper() + " ";
    }

    qDebug().noquote() << hexData;

}



void comunicationThread::digitalOutputChange(uint8_t dChange)               //Cambia las salidas digitales segun lo que se requiera en la interfaz
{
    unionTx.txBuffer.digitalOutputs =  dChange;
    emit serialSend();
}

void comunicationThread::analogOutput1Change(uint8_t aChange)               //Cambia las cuentas del PWM1 segun lo que se requiera en la interfaz
{
    unionTx.txBuffer.analogOutput1=aChange;
    emit serialSend();
}

void comunicationThread::analogOutput2Change(uint8_t aChange)               //Cambia las cuentas del PWM1 segun lo que se requiera en la interfaz
{
    unionTx.txBuffer.analogOutput2=aChange;
    qDebug()<<"cuentas del duty 2: "<< unionTx.txBuffer.analogOutput2;
    emit serialSend();
}

