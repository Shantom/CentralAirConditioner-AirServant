#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QObject>
#include <headers.h>
#include "pack.h"

class Communication : public QObject
{
    Q_OBJECT
public:
    explicit Communication(QObject *parent = 0);
    static bool connectToMaster(QHostAddress addr, quint16 port);
    void sendPack(Pack package);
private:
    static QTcpSocket socket;

signals:

public slots:
};

#endif // COMMUNICATION_H
