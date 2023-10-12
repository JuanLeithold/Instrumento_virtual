#include "threads.h"

threads::threads(QObject *parent)
    : QObject{parent}
{
    qInfo()<<this<<"Constructed"<< QThread::currentThread();
}

threads::~threads()
{
    qInfo()<<this<<"Deconstructed"<< QThread::currentThread();
}


void threads::run()
{
    for(int i=0; i<10; i++)
    {
        qInfo()<<this<<"Working"<<QString::number(i)<< QThread::currentThread();
        QThread::currentThread()->msleep(500);
    }
    this -> deleteLater();
}
