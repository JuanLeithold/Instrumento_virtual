#include "comunicationthread.h"
#include <QDebug>
#include <QString>
comunicationThread::comunicationThread()
{
    connect (_serial.serial, SIGNAL(readyRead()), this, SLOT(serialRead()));
}



void comunicationThread::run()
{
    //Operaciones que se van a ejecutar en paralelo.


}
comunicationThread::serialRead()
{
    char buffer[24];
    uint16_t analog_input [8];

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
