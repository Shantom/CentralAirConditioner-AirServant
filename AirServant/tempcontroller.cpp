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
    //windFactor
    double delta=isSummer?NATURE:-NATURE;
    double curTemp=servant->getDTemp();
    int windTemp=servant->getMaTemp();
    double windFactor=(double(windTemp)-curTemp);
    windFactor+=(windFactor>0)?20:-20;
    windFactor*=WIND;

    //velocityFactor
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

    if(servant->getVelocity()!="NONE")
        this->velocity=servant->getVelocity();

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
            if(((servant->getTemp()<=servant->getGoal()
                &&servant->getMode()=="COLD")
                    ||
                    (servant->getTemp()>=servant->getGoal()
                                    &&servant->getMode()=="HOT"))
                    &&servant->getVelocity()!="NONE")
            {
                RequestController::request(0,"NONE");
            }
            else if(((servant->getTemp()>servant->getGoal()
                      &&servant->getMode()=="COLD")
                          ||
                          (servant->getTemp()<servant->getGoal()
                                          &&servant->getMode()=="HOT"))
                    &&servant->getVelocity()=="NONE")
            {
                RequestController::request(-1,this->velocity);
            }
        }
        RefreshUIController::theCtrler->refresh();
    }
}
