#ifndef BEATCONTROLLER_H
#define BEATCONTROLLER_H

#include <QObject>
#include "headers.h"
#include "airpacket.h"
#include "communication.h"
#include "servant.h"
class Servant;
class BeatController : public QObject
{
    Q_OBJECT
public:
    explicit BeatController(QObject *parent = 0);
    static void sendBeat(TemperatureClient *packet);
    static BeatController * theCtrler;//representative instantiation to emit signal
    static Servant * servant;
signals:
    void beat(TemperatureClient * packet);

public slots:
    static void on_beat();
};

#endif // BEATCONTROLLER_H
