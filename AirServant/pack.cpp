#include "pack.h"

Pack::Pack()
{

}

QByteArray Pack::plainData()
{
    QJsonDocument doc(data);
    return doc.toBinaryData();
}

AuthPack::AuthPack(std::__cxx11::string roomID, std::__cxx11::string userID)
{
    data["type"]="auth";
    data["room"]=roomID;
    data["id"]=userID;
}

TempPack::TempPack(int temp)
{
    data["type"]="temp";
    data["temp"]=temp;
}
