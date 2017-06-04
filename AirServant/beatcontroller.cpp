#include "beatcontroller.h"
BeatController * BeatController::theCtrler;
BeatController::BeatController(QObject *parent) : QObject(parent)
{

}

void BeatController::sendBeat(TemperatureClient *packet)
{
    emit theCtrler->beat(packet);
}
