#include "servant.h"

Servant::Servant()
{
    Communication::servant=this;
}

void Servant::sendBeat()
{
    Communication com;
    TemperatureClient p(cur_temperature);
    com.sendPack(&p);
}

void Servant::setPeriod(int newPeriod)
{
    refresh_period=newPeriod;
}

void Servant::startBeat()
{
    while(true)
    {
        sendBeat();
        QTest::qWait(1000*refresh_period);
    }
}

