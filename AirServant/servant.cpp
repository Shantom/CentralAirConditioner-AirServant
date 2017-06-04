#include "servant.h"

Servant::Servant()
{
    Communication::servant=this;
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
    cur_temperature=temp;
    if(mode=="hot")
        this->mode=mode_hot;
    else if(mode=="cold")
        this->mode=mode_cold;
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

