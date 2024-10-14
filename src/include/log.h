
#include <string>

#ifndef LOG_H
#define LOG_H

/*
    Log levels
*/
enum LOG_LEVEL : int {
    VERBOSE,
    INFO,
    WARNING,
    ERROR,
    FATAL
};

/*
    Logging things
*/
void Log(LOG_LEVEL level, std::string msg);

/*
    Initial setup for logging, Must be called once.
*/
void SetupLogs();


#endif // LOG_H