#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPortInfo>
#include <QDebug>
#include <QFile>
#include "serialcomunication.h"
#include "analogoutput.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void actualizarTexto(const QString &texto);
    serialComunication serialCom;
    analogOutput analogOutputData;

private slots:

    void dialTx(int data);
    void serialRead();
    void actualizarLCD(int data);

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
