#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H
#include <string>
#include "headers.h"



class LoginController
{
public:
    LoginController();
    bool login(std::string ROOMID,std::string USERID);
};

#endif // LOGINCONTROLLER_H
