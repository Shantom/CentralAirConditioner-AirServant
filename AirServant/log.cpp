#include "log.h"

Log::Log()
{
    initLog();
}

void Log::initLog()
{
    out.open("log.txt",ios::out);
}

//CURRENT TIME
string Log::getCurrentDT(QString curDT)
{
    QDateTime dt=QDateTime::currentDateTime();
    curDT = dt.toString("yyyy-MM-dd hh:mm:ss ddd");
    string s = curDT.toStdString();
    return s;
}

void Log::handlePacket(AirPacket *packet)
{
    string s = getCurrentDT(curDT);
    out << s << " ";
    PACKET_TYPE type = packet->getType();
    switch(type){
    case TEMP_PACKET:{
        TemperatureClient *tempPacket=(TemperatureClient*)packet;
        out<<"temp="<<tempPacket->temp<<endl;
    }
    case AUTH_PACKET:{
        AuthClient *AuthPacket = (AuthClient*)packet;
        out<<"room="<<AuthPacket->room;
        out<<" id="<<AuthPacket->id<<endl;
    }
    case START_WIND_PACKET:{
        StartWindClient *StartWPacket = (StartWindClient*)packet;
        out<<"desttemp="<<StartWPacket->desttemp<<" velocity="<<StartWPacket->velocity<<endl;
    }
    case STOP_WIND_PACKET:{
        StopWindClient *stopWPacket = (StopWindClient*)packet;
        out<<"stopWPacket"<<endl;
    }
    case FRESHRATE_PACKET:{
        FreshRateServer *FRPacket = (FreshRateServer*)packet;
        out<<"freshperiod="<<FRPacket->freshperiod<<endl;
    }
    case WORK_STATE_PACKET:{
        WorkStateServer *WSPacket = (WorkStateServer*)packet;
        out<<"workingmode="<<WSPacket->workingmode;
        out<<" defaulttemp="<<WSPacket->defaulttemp<<endl;
    }
    case COUNT_FEE_PACKET:{
        CountFeeServer *CFPacket = (CountFeeServer*)packet;
        out<<"kwh="<<CFPacket->kwh;
        out<<" bill="<<CFPacket->bill<<endl;
    }
    case SEND_WIND_PACKET:{
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

