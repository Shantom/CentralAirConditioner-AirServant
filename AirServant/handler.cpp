#include "handler.h"

Handler::Handler()
{

}

RefreshRateHandler::RefreshRateHandler()
{

}

void RefreshRateHandler::handleFromPacket(AirPacket *packet, Servant *servant)
{
    FreshRateServer * packet_f=reinterpret_cast<FreshRateServer*>(packet);
    int period = packet_f->freshperiod;
    servant->setPeriod(period);
    qDebug()<<period<<"modified period successfully.";

    //do something here

}
