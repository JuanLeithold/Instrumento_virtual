#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serialcomunication.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)//Constructor
{
    ui->setupUi(this);
    _comunicationThread.start();
    /******************Signal Conections**********************/
    connect(ui->PWM1dial, SIGNAL(valueChanged(int)), this, SLOT(PWM1dialChange(int)));
    connect(ui->PWM2dial, SIGNAL(valueChanged(int)), this, SLOT(PWM2dialChange(int)));
    connect(&_comunicationThread, SIGNAL(changeText(QString&)), this, SLOT(cambiarTexto(QString)));
    connect(this,  SIGNAL(digitalOutputChange(uint8_t)), &_comunicationThread, SLOT(digitalOutputChange(uint8_t)));
    connect(this,  SIGNAL(analogOutput1Change(uint8_t)), &_comunicationThread, SLOT(analogOutput1Change(uint8_t)));
    connect(this,  SIGNAL(analogOutput2Change(uint8_t)), &_comunicationThread, SLOT(analogOutput2Change(uint8_t)));
    connect(&_comunicationThread, SIGNAL(dataReceived(unionRx_t)), this, SLOT(displayRxData(unionRx_t)));

    ui->AO1->setText(" ... V");
    ui->AO2->setText(" ... V");

    ui->LED1->setPixmap(QPixmap("C:/Users/Juan Leithold/Instrumento_virtual/QT/ledRojo"));
    ui->LED2->setPixmap(QPixmap("C:/Users/Juan Leithold/Instrumento_virtual/QT/ledRojo"));
    ui->LED3->setPixmap(QPixmap("C:/Users/Juan Leithold/Instrumento_virtual/QT/ledRojo"));
    ui->LED4->setPixmap(QPixmap("C:/Users/Juan Leithold/Instrumento_virtual/QT/ledRojo"));
    ui->LED5->setPixmap(QPixmap("C:/Users/Juan Leithold/Instrumento_virtual/QT/ledRojo"));
    ui->LED6->setPixmap(QPixmap("C:/Users/Juan Leithold/Instrumento_virtual/QT/ledRojo"));
    ui->LED7->setPixmap(QPixmap("C:/Users/Juan Leithold/Instrumento_virtual/QT/ledRojo"));
    ui->LED8->setPixmap(QPixmap("C:/Users/Juan Leithold/Instrumento_virtual/QT/ledRojo"));

    ui->LED1->setFixedSize(60,60);
    ui->LED2->setFixedSize(60,60);
    ui->LED3->setFixedSize(60,60);
    ui->LED4->setFixedSize(60,60);
    ui->LED5->setFixedSize(60,60);
    ui->LED6->setFixedSize(60,60);
    ui->LED7->setFixedSize(60,60);
    ui->LED8->setFixedSize(60,60);


}

MainWindow::~MainWindow() //Destructor
{
    delete ui;
}


void MainWindow::PWM1dialChange(int indice)
{

    QString tension;
    int duty;

    if (indice < 50)
    {
        const analogOutputStruct& output  = _analogOutputData.tabla[indice];
        tension                           = output.value;
        duty                              = output.dutyAccounts;
    }

    ui->AO1->setText(tension);
    emit analogOutput1Change(duty);

}
void MainWindow::PWM2dialChange(int indice)
{

    QString tension;
    int duty;

    if (indice < 50)
    {
        const analogOutputStruct& output  = _analogOutputData.tabla[indice];
        tension                           = output.value;
        duty                              = output.dutyAccounts;
    }

    ui->AO2->setText(tension);
    emit analogOutput2Change(duty);
}

void MainWindow::digitalInputChange(uint8_t digitalInputs)
{
    if ((digitalInputs & 0b10000000)>>7 == 1)
    {   qDebug()<<"cierto";
        ui->LED1->setPixmap(QPixmap("C:/Users/Juan Leithold/Instrumento_virtual/QT/ledVerde"));
        ui->LED1->setFixedSize(60,60);
    }
    else
    {qDebug()<<"cierto";
        ui->LED1->setPixmap(QPixmap("C:/Users/Juan Leithold/Instrumento_virtual/QT/ledRojo"));
        ui->LED1->setFixedSize(60,60);
    }

    if ((digitalInputs & 0b01000000)>>6 == 1)
    {
        ui->LED2->setPixmap(QPixmap("C:/Users/Juan Leithold/Instrumento_virtual/QT/ledVerde"));
        ui->LED2->setFixedSize(60,60);
    }
    else
    {
        ui->LED2->setPixmap(QPixmap("C:/Users/Juan Leithold/Instrumento_virtual/QT/ledRojo"));
        ui->LED2->setFixedSize(60,60);
    }

    if ((digitalInputs & 0b00100000)>>5 == 1)
    {
        ui->LED3->setPixmap(QPixmap("C:/Users/Juan Leithold/Instrumento_virtual/QT/ledVerde"));
        ui->LED3->setFixedSize(60,60);
    }
    else
    {
        ui->LED3->setPixmap(QPixmap("C:/Users/Juan Leithold/Instrumento_virtual/QT/ledRojo"));
        ui->LED3->setFixedSize(60,60);
    }
    if ((digitalInputs & 0b000010000)>>4 == 1)
    {
        ui->LED4->setPixmap(QPixmap("C:/Users/Juan Leithold/Instrumento_virtual/QT/ledVerde"));
        ui->LED4->setFixedSize(60,60);
    }
    else
    {
        ui->LED4->setPixmap(QPixmap("C:/Users/Juan Leithold/Instrumento_virtual/QT/ledRojo"));
        ui->LED4->setFixedSize(60,60);
    }
    if ((digitalInputs & 0b00001000)>>3 == 1)
    {
        ui->LED5->setPixmap(QPixmap("C:/Users/Juan Leithold/Instrumento_virtual/QT/ledVerde"));
        ui->LED5->setFixedSize(60,60);
    }
    else
    {
        ui->LED5->setPixmap(QPixmap("C:/Users/Juan Leithold/Instrumento_virtual/QT/ledRojo"));
        ui->LED5->setFixedSize(60,60);
    }
    if ((digitalInputs & 0b00000100)>>2 == 1)
    {
        ui->LED6->setPixmap(QPixmap("C:/Users/Juan Leithold/Instrumento_virtual/QT/ledVerde"));
        ui->LED6->setFixedSize(60,60);
    }
    else
    {
        ui->LED6->setPixmap(QPixmap("C:/Users/Juan Leithold/Instrumento_virtual/QT/ledRojo"));
        ui->LED6->setFixedSize(60,60);
    }
    if ((digitalInputs & 0b00000010)>>1 == 1)
    {
        ui->LED7->setPixmap(QPixmap("C:/Users/Juan Leithold/Instrumento_virtual/QT/ledVerde"));
        ui->LED7->setFixedSize(60,60);
    }
    else
    {
        ui->LED7->setPixmap(QPixmap("C:/Users/Juan Leithold/Instrumento_virtual/QT/ledRojo"));
        ui->LED7->setFixedSize(60,60);
    }
    if ((digitalInputs & 0b00000001) == 1)
    {
        ui->LED8->setPixmap(QPixmap("C:/Users/Juan Leithold/Instrumento_virtual/QT/ledVerde"));
        ui->LED8->setFixedSize(60,60);
    }
    else
    {
        ui->LED8->setPixmap(QPixmap("C:/Users/Juan Leithold/Instrumento_virtual/QT/ledRojo"));
        ui->LED8->setFixedSize(60,60);
    }


}

void MainWindow::displayRxData(const unionRx_t &data)
{
    uint8_t digitalInputs = data.txBuffer.digitalInputs;
    QString text = QString::number(digitalInputs, 2);
    qDebug()<< "digitalInputs: "<< text;

    ui->AN1->display(data.txBuffer.analogInput1);
    ui->AN2->display(data.txBuffer.analogInput2);
    ui->AN3->display(data.txBuffer.analogInput3);
    ui->AN4->display(data.txBuffer.analogInput4);
    ui->AN5->display(data.txBuffer.analogInput5);
    ui->AN6->display(data.txBuffer.analogInput6);
    ui->AN7->display(data.txBuffer.analogInput7);
    ui->AN8->display(data.txBuffer.analogInput8);

    digitalInputChange(digitalInputs);


}

/*void MainWindow::serialRead()                           //Lee las cuentas que llegan de la BP
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
}*/

void MainWindow::cambiarTexto(QString texto)
{
    qDebug()<<"seteando Texto";
    ui->AO1->setText(texto);
}

void MainWindow::on_d1Button_clicked()
{
    uint8_t digitalOutput=0b00000001;

    emit    digitalOutputChange(digitalOutput);

    ui->LED1->setPixmap(QPixmap("C:/Users/Juan Leithold/Instrumento_virtual/QT/ledVerde"));
    ui->LED1->setFixedSize(60,60);
}

void MainWindow::on_d2Button_clicked()
{
    uint8_t digitalOutput=0b00000010;

    emit    digitalOutputChange(digitalOutput);
}
void MainWindow::on_d3Button_clicked()
{
    uint8_t digitalOutput=0b00000100;

    emit    digitalOutputChange(digitalOutput);
}

void MainWindow::on_d4Button_clicked()
{
    uint8_t digitalOutput=0b00001000;

    emit    digitalOutputChange(digitalOutput);
}

void MainWindow::on_d5Button_clicked()
{
    uint8_t digitalOutput=0b00010000;

    emit    digitalOutputChange(digitalOutput);
}

void MainWindow::on_d6Button_clicked()
{
    uint8_t digitalOutput=0b00100000;

    emit    digitalOutputChange(digitalOutput);
}

void MainWindow::on_d7Button_clicked()
{
    uint8_t digitalOutput=0b01000000;

    emit    digitalOutputChange(digitalOutput);
}

void MainWindow::on_d8Button_clicked()
{
    uint8_t digitalOutput=0b10000000;

    emit    digitalOutputChange(digitalOutput);
}


