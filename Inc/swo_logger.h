#ifndef SWO_LOGGER_GUARD
#define SWO_LOGGER_GUARD

#include "stdint.h"

/**
 * @brief definition of the logger levels,
 * The smaller value is more significant
 * 
 */
typedef enum LogLevel{
    LOG_ERROR,
    LOG_WARNING,
    LOG_INFO    
}LogLevel;

static const char* const LogLevelNames[] ={
    [LOG_INFO]      = "[ INFO ]    ",
    [LOG_WARNING]   = "[ WARNING ] ",
    [LOG_ERROR]     = "[ ERROR ]   "
};

/**
 * @brief configuration object of the logger
 * 
 * send  function to send one character. The interface is design to work with ITM_sendChar()
 * level this is  level that the logger will react to
 * 
 */
typedef struct LogConfiguration{
    uint32_t (*send)(uint32_t);
    LogLevel level;
}LogConfiguration;

/**
 * @brief initialize the logger
 * 
 * @param configuration apply configuration 
 * The configuration has to be valud as long as the logger is used.
 * Because, the module keep the pointer to this config, the value can change in runtime,
 */
void LogInit(LogConfiguration* configuration);

/**
 * @brief write a log message
 * 
 * @param level see enum LogLevel
 * @param message message to send
 */
void Log(LogLevel level, const char* message);

/**
 * @brief DEBUG macro has to be defined if the logger is to be used
 * 
 */
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