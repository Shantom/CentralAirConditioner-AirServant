#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QObject>
#include <headers.h>
#include "servant.h"
#include "airpacket.h"
#include "handler.h"
#include <QQueue>

class Communication : public QObject
{
    Q_OBJECT
public:
    explicit Communication(QObject *parent = 0);
    static bool connectToMaster(QHostAddress addr, quint16 port);
    static void sendPack(AirPacket* package);
    static QTcpSocket socket;
    static Servant * servant;
private:
    static QQueue<AirPacket *> sendQueue;

signals:

public slots:
    static void on_readReady();
    static void on_beat(TemperatureClient * package);
};

#endif // COMMUNICATION_H
