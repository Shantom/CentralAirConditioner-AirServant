#ifndef BEATCONTROLLER_H
#define BEATCONTROLLER_H

#include <QObject>
#include "headers.h"
#include "airpacket.h"
#include "communication.h"

class BeatController : public QObject
{
    Q_OBJECT
public:
    explicit BeatController(QObject *parent = 0);
    static void sendBeat(TemperatureClient *packet);
    static BeatController * theCtrler;
signals:
    void beat(TemperatureClient * packet);

public slots:
};

#endif // BEATCONTROLLER_H
