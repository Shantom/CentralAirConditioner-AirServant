#ifndef SERVANT_H
#define SERVANT_H
#include "headers.h"

class Servant
{
public:
    Servant();
    void sendbeat();
    void setPeriod(int newPeriod);

private:
    int cur_temperature=26;
    int refresh_period=3;

};

class ServantInfo{
public:
    ServantInfo(std::string roomID,std::string userID):m_roomID(roomID),m_userID(userID){}
    std::string roomID(){return m_roomID;}
    std::string userID(){return m_userID;}

private:
    std::string m_roomID;
    std::string m_userID;
};

#endif // SERVANT_H
