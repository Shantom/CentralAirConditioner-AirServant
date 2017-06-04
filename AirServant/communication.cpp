#include "communication.h"
QTcpSocket Communication::socket;
Servant * Communication::servant;

Communication::Communication(QObject *parent) : QObject(parent)
{

}

bool Communication::connectToMaster(QHostAddress addr,quint16 port)
{
    socket.connectToHost(addr,port);
    qDebug()<<addr<<port;
    if(socket.waitForConnected())
    {
        qDebug()<<"connected!";
        connect(&socket,&QIODevice::readyRead,&Communication::on_readReady);
        return true;
    }
    else
    {
        qDebug()<<"connection failed";
        return false;
    }
}

void Communication::sendPack(AirPacket *package)
{
    std::string jsonStr=package->toJsonStr();
    QByteArray jsonB=QByteArray(jsonStr.c_str(),jsonStr.length());
    qDebug()<<jsonB;
    socket.write(jsonB);
}

void Communication::on_readReady()
{

    QByteArray data = socket.readAll();
    qDebug()<<"read successfully.";

    std::string dataStr=data.toStdString();
    qDebug()<< dataStr.c_str();
    auto dataJson=json::parse(dataStr);
    if(dataJson["type"]=="freshrate")
    {
        FreshRateServer packet(dataStr);
        RefreshRateHandler handler;
        handler.handleFromPacket(&packet,servant);

    }
    else if(dataJson["type"]=="mode")
    {
        //do something here
        ;
    }
    else if(dataJson["type"]=="bill")
    {
        //do something here
        ;
    }
    else if(dataJson["type"]=="wind")
    {
        //do something here
        ;
    }
}

void Communication::on_beat(TemperatureClient *package)
{
    sendPack(package);
}
