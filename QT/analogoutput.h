#ifndef ANALOGOUTPUT_H
#define ANALOGOUTPUT_H

#include <QObject>

struct analogOutputStruct
{
    QString value;
    int dutyAccounts;

};

class analogOutput : public QObject
{
    Q_OBJECT
public:
    explicit analogOutput(QObject *parent = nullptr);
    std::vector<analogOutputStruct> tabla;

    void tableInitialization(void);
signals:

};


#endif // ANALOGOUTPUT_H
