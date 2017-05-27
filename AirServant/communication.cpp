#include "communication.h"
QTcpSocket Communication::socket;
Servant *Communication::servant;

Communication::Communication(QObject *parent) : QObject(parent)
{

}

bool Communication::connectToMaster(QHostAddress addr,quint16 port)
{

    socket.connectToHost(addr,port);
    qDebug()<<addr<<port;
    if(socket.waitForConnected(300000))
    {
        qDebug()<<"connected!";
        connect(&socket,&QIODevice::readyRead,&Communication::on_readReady);
        return true;
    }
    else
    {
        qDebug()<<"failed";
        return false;
    }
}

void Communication::sendPack(AirPacket *package)
{
    std::string jsonStr=package->toJsonStr();
    socket.write(QByteArray(jsonStr.c_str(),jsonStr.length()));
}

void Communication::on_readReady()
{
    QByteArray data = socket.readAll();
    std::string dataStr=data.toStdString();
    auto dataJson=json::parse(dataStr);
    if(dataJson["type"]=="freshrate")
    {
        FreshRateServer packet(dataStr);
        RefreshRateHandler handler;
        handler.handleFromPacket(&packet,servant);

    }
    else
    {
        //do something here
        ;
    }


    qDebug()<<"triggered successfully.";
}
