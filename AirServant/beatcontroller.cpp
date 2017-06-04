#include "beatcontroller.h"
BeatController * BeatController::theCtrler;
Servant * BeatController::servant;
BeatController::BeatController(QObject *parent) : QObject(parent)
{

}

void BeatController::sendBeat(TemperatureClient *packet)
{
    emit theCtrler->beat(packet);
}

void BeatController::on_beat()
{
    TemperatureClient *packet=new TemperatureClient(servant->getPeriod());
    sendBeat(packet);
    delete packet;
}
