#include "log.h"

Log::Log()
{

}

Log::startLogging()
{
    file.open("AirServant.log",std::ios_base::out|std::ios_base::app);
}
