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
}

WorkingModeHandler::WorkingModeHandler()
{

}

void WorkingModeHandler::handleFromPacket(AirPacket *packet, Servant *servant)
{
    WorkStateServer * packet_w=reinterpret_cast<WorkStateServer*>(packet);
    int temp=packet_w->defaulttemp;
    std::string mode=packet_w->workingmode;
    servant->setState(temp,mode);
    qDebug()<<temp<<" modified state to *"<<mode.c_str()<<"* successfully.";

}

UpdateBillHandler::UpdateBillHandler()
{

}

void UpdateBillHandler::handleFromPacket(AirPacket *packet, Servant *servant)
{
    CountFeeServer *packet_c=reinterpret_cast<CountFeeServer*>(packet);
    float bill=packet_c->bill;
    float kwh=packet_c->kwh;
    servant->setBill(bill,kwh);
    qDebug()<<"modified bill and kwh successfully.";

}
