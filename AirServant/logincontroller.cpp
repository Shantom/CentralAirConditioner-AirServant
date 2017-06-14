#include "logincontroller.h"

LoginController::LoginController()
{

}

bool LoginController::login(std::string ROOMID, std::string USERID)
{
    Communication com;
    AuthClient p(ROOMID,USERID);
    com.sendPack(&p);

    if(Communication::socket.waitForReadyRead(-1))
        return true;
    else
        return false;

}
