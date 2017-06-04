#include "handler.h"

Handler::Handler()
{

}

RefreshRateHandler::RefreshRateHandler()
{

}

void RefreshRateHandler::handleFromPacket(AirPacket *packet, Servant * servant)
{
    FreshRateServer * packet_f=reinterpret_cast<FreshRateServer*>(packet);
    int period = packet_f->freshperiod;
    servant->setPeriod(period);
    qDebug()<<period<<"modified period successfully.";

    //do something here

}

void WorkingModeHandler::handleFromPacket(AirPacket *packet, Servant *servant)
{
    WorkStateServer * packet_w=reinterpret_cast<WorkStateServer*>(packet);
    int temp=packet_w->defaulttemp;
    std::string mode=packet_w->workingmode;
    servant->setState(temp,mode);
    qDebug()<<temp<<"modified state to *"<<mode.c_str()<<"* successfully.";

}
