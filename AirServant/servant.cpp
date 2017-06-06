#include "servant.h"
#include "mainwindow.h"

Servant::Servant()
{
    Communication::servant=this;
    tempCtrler=new TempController(true);//here change the season
    tempCtrler->servant=this;
}

void Servant::sendBeat()
{
    TemperatureClient p(cur_temperature);
    BeatController::sendBeat(&p);
}

void Servant::setPeriod(int newPeriod)
{
    refresh_period=newPeriod;
    beatTimer->setInterval(1000*refresh_period);
}

void Servant::setState(int temp, std::__cxx11::string mode)
{
    tempOfMaster=temp;
    if(mode=="hot")
        this->mode=mode_hot;
    else if(mode=="cold")
        this->mode=mode_cold;
    RefreshUIController::theCtrler->refresh();
}

void Servant::setBill(float bill, float kwh)
{
    this->bill=bill;
    this->kwh=kwh;
    RefreshUIController::theCtrler->refresh();
}

void Servant::setWind(int windtemp, std::__cxx11::string velocity)
{
    if(velocity=="none")
        this->velocity="NONE";
    else if(velocity=="high")
        this->velocity="HIGH";
    else if(velocity=="medium")
        this->velocity="MEDIUM";
    else if(velocity=="low")
        this->velocity="LOW";
    this->tempOfMaster=windtemp;
}

void Servant::startBeat()
{
    BeatController::servant=this;
    BeatController::theCtrler=new BeatController();
    BeatController::connect(BeatController::theCtrler,
                            &BeatController::beat,
                            &Communication::on_beat);
    beatTimer=new QTimer();
    beatTimer->setInterval(1000*refresh_period);
    beatTimer->connect(beatTimer,&QTimer::timeout,&BeatController::on_beat);
    beatTimer->start();
}

