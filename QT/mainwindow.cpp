#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serialcomunication.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)//Constructor
{
    ui->setupUi(this);

    /******************Signal Conections**********************/
    connect(ui->dial, SIGNAL(valueChanged(int)), this, SLOT(dialTx(int)));
    connect                 (serialCom.serial, SIGNAL(readyRead()), this, SLOT(serialRead()));
}

MainWindow::~MainWindow() //Destructor
{
    delete ui;
}

void MainWindow::actualizarTexto(const QString &texto)  //Cambia texto de display
{
    ui->rxDisplay->setText(texto);
}

void MainWindow::actualizarLCD(int data)                //Cambia valores del display numerico
{
    ui->lcdNumber->display(data);
}

void MainWindow::dialTx(int indice)                     //Envia las cuentas a la BP del duty
{
    char data_c [sizeof(int)];
    QString tension;
    int duty;

    if (indice >0 && indice < 50)
    {
        const analogOutputStruct& output  = analogOutputData.tabla[indice];
        tension                         = output.value;
        duty                            = output.dutyAccounts;
    }
    actualizarTexto(tension);


    memcpy(data_c, &duty, sizeof(int));

    if (serialCom.serial->isWritable())
    {
        serialCom.serial->write(data_c, 4);
          qDebug()<< "asd";
    }
    else
    {
        qDebug()<< "No se puede";
    }
}

void MainWindow::serialRead()                           //Lee las cuentas que llegan de la BP
{
    char buffer[sizeof(int)];
    int enteroRecibido;
    if (serialCom.serial->read(buffer, sizeof(buffer)) == sizeof(buffer))
    {
        memcpy(&enteroRecibido, &buffer, sizeof(int));

    }
    else
    {
        qDebug()<<"no se recibio nada";
    }

    actualizarLCD(enteroRecibido);
}



