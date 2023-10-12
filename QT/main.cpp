#include "mainwindow.h"
#include "serialcomunication.h"
#include "threads.h"
#include <QThread>
#include <QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QThread::currentThread()->setObjectName("Main Thread");
    w.show();

      qInfo()<<"Start"<< QThread::currentThread();
      qInfo()<<"Doing Stuff"<< QThread::currentThread();

      threads *threadComunication= new threads();
      QThread   thread;

      thread.setObjectName("Comunication thread");
      threadComunication->moveToThread(&thread);

      QObject::connect(&thread, &QThread::started, threadComunication,&threads::run);

      thread.start();
      for  (int i=0; i<10; i++)
      {
          qInfo()<<"Working"<<QString::number(i)<< QThread::currentThread();
          QThread::currentThread()->msleep(500);
      }
      qInfo()<<"Finish"<< QThread::currentThread();
    return a.exec();
}
