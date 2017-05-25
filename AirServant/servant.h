#ifndef SERVANT_H
#define SERVANT_H
#include "headers.h"

class Servant
{
public:
    Servant();
    void sendbeat();

private:
    int cur_temperature;
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
