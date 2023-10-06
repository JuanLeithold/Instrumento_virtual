#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QFile>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QSerialPort;

struct analogOutputData {
    int index;
    QString value;
    int dutyAccounts;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void actualizarTexto(const QString &texto);
     std::vector<analogOutputData> tabla;




private slots:

    void on_enviarDatos_clicked();
    void dialTx(int data);
    void serialRead();
    void actualizarLCD(int data);

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    QString portName;
    void portInit(void);

};
#endif // MAINWINDOW_H
