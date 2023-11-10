#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPortInfo>
#include <QDebug>
#include <QFile>
#include "serialcomunication.h"
#include "analogoutput.h"
#include "comunicationthread.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);  //Constructor
    ~MainWindow();                          //Destructor
    void digitalInputChange(uint8_t digitalInputs);

    analogOutput       _analogOutputData;   //Instancia de la clase con los datos del duty para los PWM
    comunicationThread _comunicationThread; //Instancia de la clase para el manejo del puerto serie

public slots:
    void displayRxData(const unionRx_t &data);
                                            /**********************************************************************/
    void PWM1dialChange(int data);          /*Slots que envian las cuentas del pwm al thread para la comunicacion */
    void PWM2dialChange(int data);          /**********************************************************************/

    void on_d1Button_clicked();
    void on_d2Button_clicked();
    void on_d3Button_clicked();             /**********************************************************************/
    void on_d4Button_clicked();             /*     Slots de los botones que modifican las salidas analógicas      */
    void on_d5Button_clicked();             /**********************************************************************/
    void on_d6Button_clicked();
    void on_d7Button_clicked();
    void on_d8Button_clicked();



signals:
    void digitalOutputChange  (uint8_t dChange);
    void analogOutput1Change  (uint8_t aChange);
    void analogOutput2Change  (uint8_t aChange);



private slots:

    void on_startButton_clicked();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    bool working = false;

};
#endif // MAINWINDOW_H
