#include "log.h"

log::log()
{
    initLog();
}

void log::initLog()
{
    out.open("log.txt",ios::out);
}

//CURRENT TIME
string log::getCurrentDT(QString curDT)
{
    QDateTime dt=QDateTime::currentDateTime();
    curDT = dt.toString("yyyy-MM-dd hh:mm:ss ddd");
    string s = curDT.toStdString();
    return s;
}

void log::handlePacket(AirPacket *packet)
{
    string s = getCurrentDT(curDT);
    out << s << " ";
    PACKET_TYPE type = packet->getType();
    switch(type){
    case 1:{
        TemperatureClient *tempPacket=(TemperatureClient*)packet;
        out<<"temp="<<tempPacket->temp<<endl;
    }
    case 2:{
        AuthClient *AuthPacket = (AuthClient*)packet;
        out<<"room="<<AuthPacket->room;
        out<<" id="<<AuthPacket->id<<endl;
    }
    case 3:{
        StartWindClient *StartWPacket = (StartWindClient*)packet;
        out<<"desttemp="<<StartWPacket->desttemp<<" velocity="<<StartWPacket->velocity<<endl;
    }
    case 4:{
        StopWindClient *stopWPacket = (StopWindClient*)packet;
        out<<" "<<endl;
    }
    case 5:{
        FreshRateServer *FRPacket = (FreshRateServer*)packet;
        out<<"freshperiod="<<FRPacket->freshperiod<<endl;
    }
    case 6:{
        WorkStateServer *WSPacket = (WorkStateServer*)packet;
        out<<"workingmode="<<WSPacket->workingmode;
        out<<" defaulttemp="<<WSPacket->defaulttemp<<endl;
    }
    case 7:{
        CountFeeServer *CFPacket = (CountFeeServer*)packet;
        out<<"kwh="<<CFPacket->kwh;
        out<<" bill="<<CFPacket->bill<<endl;
    }
    case 8:{
        SendWindServer *sendWPacket = (SendWindServer*)packet;
        out<<"windtemp="<<sendWPacket->windtemp;
        out<<" velocity="<<sendWPacket->velocity<<endl;
    }
    case 9:{

    }
    default:{

    }
    }
}

