#ifndef LOG_H
#define LOG_H
#include <fstream>

#include <QString>
#include <QTime>
#include <QIODevice>
#include "airpacket.h"
using namespace std;

class Log
{
public:
    Log();
    void initLog();
    string getCurrentDT(QString curDT);
    void handlePacket(AirPacket* packet);
    ofstream out;
private:
    QString curDT;
};

#endif // LOG_H
