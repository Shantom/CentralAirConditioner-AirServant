#ifndef HANDLER_H
#define HANDLER_H
#include "headers.h"
#include "servant.h"

class Servant;

class Handler
{
public:
    Handler();
    virtual void handleFromPacket(AirPacket *packet, Servant * servant)=0;
};

class RefreshRateHandler:public Handler
{
public:
    RefreshRateHandler();
    void handleFromPacket(AirPacket *packet, Servant * servant);
};

class WorkingModeHandler:public Handler
{
public:
    WorkingModeHandler();
    void handleFromPacket(AirPacket *packet, Servant * servant);
};

class UpdateBillHandler:public Handler
{
public:
    UpdateBillHandler();
    void handleFromPacket(AirPacket *packet, Servant * servant);
};

class ReceiveWindHandler:public Handler
{
public:
    ReceiveWindHandler();
    void handleFromPacket(AirPacket *packet, Servant * servant);

};


#endif // HANDLER_H
