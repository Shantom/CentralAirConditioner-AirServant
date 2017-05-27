#include "servant.h"

Servant::Servant()
{

}

void Servant::sendbeat()
{
    Communication com;
    TemperatureClient p(cur_temperature);
    com.sendPack(&p);
}

void Servant::setPeriod(int newPeriod)
{
    refresh_period=newPeriod;
}

