#ifndef SERVANT_H
#define SERVANT_H
#include "headers.h"
#include "beatcontroller.h"
#include "refreshuicontroller.h"
#include <QTimer>
class MainWindow;
class Servant
{
public:
    Servant();
    void setWin(MainWindow * mWin){this->mWin=mWin;}
    void sendBeat();
    void setPeriod(int newPeriod);
    void setState(int temp, std::string mode);
    void setBill(float bill,float kwh);
    void startBeat();
    int getPeriod(){return refresh_period;}
    float getBill(){return bill;}
    float getKwh(){return kwh;}
    std::string getMode(){if(mode==mode_hot)return std::string("HOT");
        else return std::string("COLD");}

private:
    work_mode mode=mode_hot;
    int cur_temperature=26;
    int refresh_period=3;
    float bill=0;
    float kwh=0;
    QTimer *beatTimer;
    MainWindow * mWin;
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
