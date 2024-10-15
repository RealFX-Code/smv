
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <sys/stat.h>

#if defined(WIN32)
#include <Windows.h>
#endif

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
    
    char FormattedOutput[32768];
    // currentDateTime() -> std::String
    // LOG_LEVEL_STRING  -> std::String
    // msg               -> std::String
    sprintf(FormattedOutput, "[%s] -> [%s] %s\n",currentDateTime(), LOG_LEVEL_STRING, msg);
    std::string FormattedOutput_s(FormattedOutput);

    std::cout << FormattedOutput_s;

    std::ofstream FileStream;

    FileStream.open("logs/latest.log");
    FileStream << FormattedOutput_s;
    FileStream.close();

}

void SetupLogs() {
    // TODO: impl log dir creation and moving "latest.log" to "<date>.log"

    struct stat sb;

    if(stat("logs", &sb) != 0) {
        std::cout << "WARNING: Log directory doesn't exist, making it now!" << std::endl;
    }

    #if defined(WIN32)
    
    CreateDirectory("logs",NULL)

    #elif(UNIX)
    
    mkdir("logs/")

    #endif

    return;
}