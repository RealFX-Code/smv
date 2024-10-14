
#include <string>
#include <iostream>

#include "log.h"

// Stolen from: https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);

    return buf;
}

void Log(LOG_LEVEL level, std::string msg) {
    // ugly thing
    std::string LOG_LEVEL_STRING = "";
    switch (level)
    {
        case VERBOSE:
            LOG_LEVEL_STRING = " VERBOSE ";
            break;
        case INFO:
            LOG_LEVEL_STRING = " INFO ";
            break;
        case WARNING:
            LOG_LEVEL_STRING = " WARNING ";
            break;
        case ERROR:
            LOG_LEVEL_STRING = " ERROR ";
            break;
        case FATAL:
            LOG_LEVEL_STRING = " FATAL ";
            break;
        default:
            LOG_LEVEL_STRING = " ????? ";
            break;
    }

    // Begin log
    std::cout << "[" << currentDateTime() << "] [" << LOG_LEVEL_STRING << "] " << msg << std::endl;

}

void SetupLogs();