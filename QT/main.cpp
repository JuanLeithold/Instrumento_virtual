#include "mainwindow.h"
#include "serialcomunication.h"
#include <QThread>
#include <QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QThread::currentThread()->setObjectName("Main Thread");
    w.show();
    return a.exec();
}
