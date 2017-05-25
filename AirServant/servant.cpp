#include "servant.h"

Servant::Servant()
{

}

void Servant::sendbeat()
{
    Communication com;
    TempPack p(cur_temperature);
    com.sendPack(p);
}

