#ifndef COMUNICATIONTHREAD_H
#define COMUNICATIONTHREAD_H

#include <QObject>
#include <QThread>
#include "serialcomunication.h"
#include "analogoutput.h"

class comunicationThread : public QThread
{
    Q_OBJECT
public:
    comunicationThread(); // Constructor
    serialComunication _serial;


public slots:
    serialRead();

signals:


    // QThread interface
protected:
    void run();
};

#endif // COMUNICATIONTHREAD_H
