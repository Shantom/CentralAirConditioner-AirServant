#ifndef SERVANT_H
#define SERVANT_H
#include "headers.h"
#include "beatcontroller.h"
#include "refreshuicontroller.h"
#include "tempcontroller.h"
#include <QTimer>
class MainWindow;
class TempController;
class Servant
{
public:
    Servant();
    void setWin(MainWindow * mWin){this->mWin=mWin;}
    void sendBeat();
    void setGoal(int goal){goalTemp=goal;}
    int getGoal(){return goalTemp;}
    void setTemp(int temp){cur_temperature=temp;}
    void setTemp(double temp){dTemp=temp;}
    double getDTemp(){return dTemp;}
    int getTemp(){return cur_temperature;}
    void setPeriod(int newPeriod);
    int getPeriod(){return refresh_period;}
    void setState(int temp, std::string mode);
    int getMaTemp(){return tempOfMaster;}
    std::string getMode(){if(mode==mode_hot)return std::string("HOT");
        else return std::string("COLD");}
    void setBill(float bill,float kwh);
    float getBill(){return bill;}
    float getKwh(){return kwh;}
    void setActive(bool isActive){this->isActive=isActive;}
    bool getActive(){return isActive;}
    void setWind(int windtemp,std::string velocity){this->velocity=velocity;
                                                    this->tempOfMaster=windtemp;}
    std::string getVelocity(){return velocity;}
    void startBeat();

private:
    int goalTemp=26;
    work_mode mode=mode_hot;// working mode of the master
    int tempOfMaster=18;
    int cur_temperature=26;
    double dTemp=26.0;
    int refresh_period=3;
    float bill=0;
    float kwh=0;
    bool isActive;//to mark if the servant is active
    std::string velocity="NONE";
    QTimer *beatTimer;
    TempController *tempCtrler;
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
