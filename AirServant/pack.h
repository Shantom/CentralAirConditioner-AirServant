#ifndef PACK_H
#define PACK_H
#include "headers.h"

class Pack
{
public:
    Pack();
    QByteArray plainData();
    QJsonObject data;
};

class AuthPack : public Pack
{
public:
    AuthPack(std::string roomID, std::string userID);
private:

};

class TempPack :public Pack
{
public:
    TempPack(int temp);
};

#endif // PACK_H
