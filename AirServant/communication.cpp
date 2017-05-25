#include "communication.h"
QTcpSocket Communication::socket;
Communication::Communication(QObject *parent) : QObject(parent)
{

}

bool Communication::connectToMaster(QHostAddress addr,quint16 port)
{
    socket.connectToHost(addr,port);
    if(socket.waitForConnected(1000))
    {
        return true;
    }
    else
    {
        return false;
    }

}

void Communication::sendPack(Pack package)
{
    socket.write(package.plainData());
}
