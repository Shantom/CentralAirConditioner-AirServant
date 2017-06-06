#include "requestcontroller.h"
QTimer RequestController::oneSecond;
Servant *RequestController::servant;
int RequestController::goal;
std::string RequestController::velocity;
RequestController::RequestController(QObject *parent) : QObject(parent)
{

}

void RequestController::initial(Servant * serv)
{
    RequestController::servant=serv;
    velocity="NONE";
    oneSecond.setInterval(1000);
    oneSecond.setSingleShot(true);
    connect(&oneSecond,&QTimer::timeout,&RequestController::sendRequest);
}

void RequestController::sendRequest()
{
    if(velocity=="NONE")
    {
        StopWindClient packet;
        Communication::sendPack(&packet);
    }
    else
    {
        StartWindClient packet(goal,velocity);
        Communication::sendPack(&packet);
    }
}

bool RequestController::request(int goal, std::string velocity)
{
    int cur_temp=servant->getTemp();
    if(goal<=cur_temp&&servant->getMode()=="COLD"
            ||goal>=cur_temp&&servant->getMode()=="HOT"
            ||velocity=="NONE"
            ||goal==-1)
    {
        if(goal!=-1&&goal!=0)
            RequestController::goal=goal;
        if(!velocity.empty())
            RequestController::velocity=velocity;
        oneSecond.stop();
        oneSecond.start();
        return true;
    }
    else
    {
        return false;
    }
}
