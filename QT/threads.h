#ifndef THREADS_H
#define THREADS_H

#include <QObject>
#include <QThread>
#include <QDebug>
class threads : public QObject
{
    Q_OBJECT
public:
    explicit threads(QObject *parent = nullptr);
    ~threads();

public slots:
    void run();
signals:

};

#endif // THREADS_H
