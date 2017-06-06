#ifndef TEMPCONTROLLER_H
#define TEMPCONTROLLER_H

#include <QObject>
#include "servant.h"
#include "requestcontroller.h"
#include <QTimer>

#define SPEED_FACTOR 30 //simulation speed factor
#define NATURE 0.2
#define WIND 0.03
#define HIGH 1.2
#define MEDIUM 1
#define LOW 0.8
#define NONE 0

class TempController : public QObject
{
    Q_OBJECT
public:
    explicit TempController(bool isSummer, QObject *parent = 0);
    Servant* servant;
private:
    QTimer timer;
    bool isSummer;
    std::string velocity;
signals:

public slots:
    void changeTemp();
};

#endif // TEMPCONTROLLER_H
