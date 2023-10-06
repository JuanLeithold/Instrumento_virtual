#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial = new QSerialPort() ;//inicializa la variable serial
    portName = "COM3";

    portInit();


    /******************Signal Conections**********************/
    connect(ui->dial, SIGNAL(valueChanged(int)), this, SLOT(dialTx(int)));
    connect                 (serial, SIGNAL(readyRead()), this, SLOT(serialRead()));

    /******************Datos para la salida analógica**********************/
    tabla = {
        {1 , "360 mV", 10},
        {2 , "484 mV", 20},
        {3 , "600 mV", 30},
        {4 , "700 mV", 40},
        {5 , "775 mV", 50},
        {6 , "862 mV", 60},
        {7 , "935 mV", 70},
        {8 , "1 V"   , 80},
        {9 , "1.07 V", 90},
        {10, "1.13 V", 100},
        {11, "1.18 V", 110},
        {12, "1.24 V", 120},
        {13, "1.3 V", 130},
        {14, "1.34 V", 140},
        {15, "1.39 V", 150},
        {16, "1.43 V", 160},
        {17, "1.47 V", 170},
        {18, "1.52 V", 180},
        {19, "1.57 V", 190},
        {20, "1.6 V", 200},
        {21, "1.65 V", 210},
        {22, "1.68 V", 220},
        {23, "1.72 V", 230},
        {24, "1.75 V", 240},
        {25, "1.78 V", 250},
        {26, "1.81 V", 260},
        {27, "1.85 V", 270},
        {28, "1.87 V", 280},
        {29, "1.90 V", 290},
        {30, "1.93 V", 300},
        {31, "1.96 V", 310},
        {32, "1.98 V", 320},
        {33, "2 V",    330},
        {34, "2.03 V", 340},
        {35, "2.06 V", 350},
        {36, "2.09 V", 360},
        {37, "2.12 V", 370},
        {38, "2.13 V", 380},
        {39, "2.16 V", 390},
        {40, "2.18 V", 400},
        {41, "2.21 V", 410},
        {42, "2.23 V", 420},
        {43, "2.26 V", 430},
        {44, "2.28 V", 440},
        {45, "2.31 V", 450},
        {46, "2.33 V", 460},
        {47, "2.35 V", 470},
        {48, "2.38 V", 480},
        {49, "2.40 V", 490},
        {50, "2.43 V", 500}
    };
}




MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::portInit(void)
{
    serial ->setPortName    (portName);
    serial ->setBaudRate    (QSerialPort::Baud115200);
    serial ->setDataBits    (QSerialPort::Data8);
    serial ->setParity      (QSerialPort::NoParity);
    serial ->setStopBits    (QSerialPort::OneStop);
    serial ->setFlowControl (QSerialPort::NoFlowControl);
    serial ->open           (QIODevice::ReadWrite);
    //connect                 (serial, SIGNAL(readyRead()), this, SLOT(serialRead()));
}

void MainWindow::on_enviarDatos_clicked()
{
    QString texto = "1";

    if (serial->isWritable())
    {
        serial->write("45");
    }
    else
    {
        qDebug()<< "No se puede";
    }
}

void MainWindow::actualizarTexto(const QString &texto)
{
    ui->rxDisplay->setText(texto);
}

void MainWindow::dialTx(int indice)
{
    char data_c [sizeof(int)];
    QString tension;
    int duty;

    if (indice >0 && indice <= 50)
    {
        const analogOutputData& output  = tabla[indice];
        tension                         = output.value;
        duty                            = output.dutyAccounts;
    }
    actualizarTexto(tension);


    memcpy(data_c, &duty, sizeof(int));


    if (serial->isWritable())
    {
        serial->write(data_c, sizeof(int ));
    }
    else
    {
        qDebug()<< "No se puede";
    }
}

void MainWindow::serialRead()
{
    char buffer[sizeof(int)];
    int enteroRecibido;
    if (serial->read(buffer, sizeof(buffer)) == sizeof(buffer))
    {
        memcpy(&enteroRecibido, &buffer, sizeof(int));

    }
    else
    {
        qDebug()<<"no se recibio nada";
    }

    actualizarLCD(enteroRecibido);
}

void MainWindow::actualizarLCD(int data)
{
    ui->lcdNumber->display(data);
}

