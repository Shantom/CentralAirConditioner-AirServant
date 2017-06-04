#ifndef LOG_H
#define LOG_H
#include <fstream>

class Log
{
public:
    Log();
    static void startLogging();
    static std::ofstream file;
};

#endif // LOG_H
