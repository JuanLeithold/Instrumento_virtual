#ifndef COMUNICATIONTHREAD_H
#define COMUNICATIONTHREAD_H

#include <QObject>
#include <QThread>
#include "serialcomunication.h"
#include "analogoutput.h"

typedef struct
{
    // Byte de caebcera.
    uint8_t header;
    // 8 entradas analógicas (12 bits).
    uint16_t analogInput1;
    uint16_t analogInput2;
    uint16_t analogInput3;
    uint16_t analogInput4;
    uint16_t analogInput5;
    uint16_t analogInput6;
    uint16_t analogInput7;
    uint16_t analogInput8;
    // 8 entradas digitales.
    uint8_t digitalInputs;

} rxBuffer_t;

typedef union
{
    rxBuffer_t txBuffer;
    char    txBuffer_c[18];
} unionRx_t; //Fin de union

class comunicationThread : public QThread
{
    Q_OBJECT
public:
    comunicationThread(); // Constructor
    ~comunicationThread();
    serialComunication _serial;
    rxBuffer_t rxBuffer;
    QByteArray headerArray;

    uint8_t pwmDuty1=0;
    uint8_t pwmDuty2=0;
    uint8_t digitalOutputs=0b00000000;

private:
    QByteArray data;        // Para recibir por puerto serie
    QByteArray dataBuffer;
    unsigned int bytesReceived;

public slots:
   // serialRead();
    bool serialTx(void);
    void digitalOutputChange  (uint8_t dChange);
    void analogOutput1Change  (uint8_t aChange);
    void analogOutput2Change  (uint8_t aChange);

signals:
    void dataReceived(const unionRx_t &data);
    void changeText (QString &texto);

protected:
    void run();
};

#endif // COMUNICATIONTHREAD_H
