#include "tempcontroller.h"

TempController::TempController( bool isSummer,QObject *parent)
    : QObject(parent),isSummer(isSummer)
{
    timer.setInterval(30000/SPEED_FACTOR);
    timer.start();
    connect(&timer,&QTimer::timeout,this,&TempController::changeTemp);
}

void TempController::changeTemp()
{
    double delta=isSummer?NATURE:-NATURE;
    double curTemp=servant->getDTemp();
    int windTemp=servant->getMaTemp();
    double windFactor=(double(windTemp)-curTemp);
    windFactor+=(windFactor>0)?15:-15;
    windFactor*=WIND;
    std::string velocity=servant->getVelocity();
    if(velocity=="NONE")
        windFactor*=NONE;
    else if(velocity=="HIGH")
        windFactor*=HIGH;
    else if(velocity=="MEDIUM")
        windFactor*=MEDIUM;
    else if (velocity=="LOW")
        windFactor*=LOW;
    delta+=windFactor;
    servant->setTemp(curTemp+delta);
    double change=servant->getDTemp()-double(servant->getTemp());
    if(change>=0.99||change<=-0.99)
    {
        if(change>=0.99)
        {
            servant->setTemp(servant->getTemp()+1);
        }
        else if(change<=-0.99)
        {
            servant->setTemp(servant->getTemp()-1);
        }
        if(servant->getActive())//only when active
        {
            if(servant->getGoal()==servant->getTemp()
                    &&RequestController::getVelocity()!="NONE")
            {
                RequestController::request(0,"NONE");
            }
            if(servant->getGoal()!=servant->getTemp()
                    &&RequestController::getVelocity()=="NONE")
            {
                RequestController::request();
            }
        }
        RefreshUIController::theCtrler->refresh();
    }
}
