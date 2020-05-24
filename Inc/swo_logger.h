#ifndef SWO_LOGGER_GUARD
#define SWO_LOGGER_GUARD

#include "stdint.h"


typedef enum LogLevel{
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR
}LogLevel;

static const char* const LogLevelNames[] ={
    [LOG_INFO]      = "[ INFO ]    ",
    [LOG_WARNING]   = "[ WARNING ] ",
    [LOG_ERROR]     = "[ ERROR ]   "
};

typedef struct LogConfiguration{
    uint32_t (*send)(uint32_t);
    LogLevel level;
}LogConfiguration;

void LogInit(LogConfiguration* configuration);



void Log(LogLevel level, const char* message);



#ifdef DEBUG

#define LOG_INFO(message) Log(LOG_INFO, message)
#define LOG_WARNING(message) Log(LOG_WARNING, message)
#define LOG_ERROR(message) Log(LOG_ERROR, message)
#else
#define LOG_INFO(message)
#define LOG_WARNING(message)
#define LOG_ERROR(message)
#endif

#endif //SWO_LOGGER_GUARD