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
    qDebug()<<">>"<<jsonB.constData();
    socket.write(jsonB);
}

void Communication::on_readReady()
{

    QByteArray data = socket.readAll();

    std::string dataStrs=data.toStdString();
    auto packets=parseJsonStr(dataStrs);

    for(auto dataStr:packets)
    {
        qDebug()<<"<<" <<dataStr.c_str();
        auto dataJson=json::parse(dataStr);
        if(dataJson["type"]=="freshrate")
        {
            FreshRateServer packet(dataStr);
            RefreshRateHandler handler;
            handler.handleFromPacket(&packet,servant);
        }
        else if(dataJson["type"]=="mode")
        {
            WorkStateServer packet(dataStr);
            WorkingModeHandler handler;
            handler.handleFromPacket(&packet,servant);
            ;
        }
        else if(dataJson["type"]=="bill")
        {
            CountFeeServer packet(dataStr);
            UpdateBillHandler handler;
            handler.handleFromPacket(&packet,servant);
        }
        else if(dataJson["type"]=="wind")
        {
            SendWindServer packet(dataStr);
            ReceiveWindHandler handler;
            handler.handleFromPacket(&packet,servant);
        }
    }
}

void Communication::on_beat(TemperatureClient *package)
{
    sendPack(package);
}

std::vector<std::string> Communication::parseJsonStr(std::string &originStr)
{
    std::vector<std::string> allJsons;
    std::string oneJson = parseOneJson(originStr);
    while(!oneJson.empty()){
        allJsons.push_back(oneJson);
        oneJson = parseOneJson(originStr);
    }
    return allJsons;
}

std::string Communication::parseOneJson(std::string &originStr)
{
    unsigned leftCounter=0,flag=0,rightCounter=0;
    while(flag < originStr.size()){
        if(originStr[flag] == '{'){
            leftCounter++;
        }
        if (originStr[flag] == '}'){
            rightCounter++;
            if (rightCounter == leftCounter){
                std::string res = originStr.substr(0,flag+1);
                originStr=originStr.substr(flag+1,originStr.size()-flag);
                return res;
            }
        }
        flag++;
    }
    return "";
}
