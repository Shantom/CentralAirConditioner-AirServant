#include "logincontroller.h"

LoginController::LoginController()
{

}

bool LoginController::login(std::__cxx11::string ROOMID, std::__cxx11::string USERID)
{
    Communication com;
    AuthClient p(ROOMID,USERID);
    com.sendPack(&p);

    return true;

}
