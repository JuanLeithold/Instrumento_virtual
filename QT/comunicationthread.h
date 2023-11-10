/*********************************************************************/
/*****Clase para manejar la comunicacion serial con hilos*************/
/*********************************************************************/
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

} rxBuffer_t;//Estructura de Recepcion de datos

typedef union
{
    rxBuffer_t rxBuffer;
    char    rxBuffer_c[sizeof(rxBuffer_t)];
} unionRx_t; //Union de Recepcion de datos

typedef struct
{
    // Byte de caebcera.
    uint8_t header;
    // 8 entradas analógicas (12 bits).
    uint8_t analogOutput1;
    uint8_t analogOutput2;
    // 8 entradas digitales.
    uint8_t digitalOutputs;

} txBuffer_t;//Estructura de Recepcion de datos

typedef union
{
    txBuffer_t txBuffer;
    char    txBuffer_c[sizeof(txBuffer_t)];
} unionTx_t; //Union de Recepcion de datos

class comunicationThread : public QThread
{
    Q_OBJECT
public:
    comunicationThread();                           // Constructor.
    ~comunicationThread();                          // Destructor.

    serialComunication _serial;                     //Instancia de la clase de comunicación serial.

    rxBuffer_t rxBuffer;                            // Variable de la estructura creada.
    unionTx_t  unionTx;
    QByteArray headerArray;                         // Variable auxiliar para la comparacion del header recibido por serial.

    uint8_t pwmDuty1=50;                             /*******************************************************/
    uint8_t pwmDuty2=50;                             /**Variables que almacenaranlos datos a enviar a la BP**/
    uint8_t digitalOutputs;              /*******************************************************/

private:
    QByteArray data;                                // Para recibir de a un byte por puerto serie.
    QByteArray dataBuffer;                          // Para acumular los datos recibidos.
    unsigned int bytesReceived;                     //Para llevar un conteo de los bytes recibidos.

public slots:
   // serialRead();
    bool serialTx(void);                            //Manejo de archivos para Tx a BluePill

    void digitalOutputChange  (uint8_t dChange);    //Slots que se ejecutan ante una señal emitida por la interfaz gráfica (botones, dial, etc)
    void analogOutput1Change  (uint8_t aChange);    //Modifican los valores de las vaariables que se enviaran a la bluepill.
    void analogOutput2Change  (uint8_t aChange);    //Estas son las salidas digitales y los valores del duty de ambos pwm

signals:
    void dataReceived(const unionRx_t &data);       //Señal que se emite cuando se obtienen todos los datos de la recepcion. La señal es detectada por MainWindows
    void serialSend(void);

protected:
    void run();
};

#endif // COMUNICATIONTHREAD_H
