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

#endif // HANDLER_H
