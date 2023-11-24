#ifndef SERIALCOMUNICATION_H
#define SERIALCOMUNICATION_H

#include <QObject>
#include <QSerialPort>
class serialComunication : public QObject
{
    Q_OBJECT
public:
    explicit serialComunication(QObject *parent = nullptr);

    void portInit(void);

    QSerialPort *serial;
    QString portName="COM";

signals:

};



#endif // SERIALCOMUNICATION_H
