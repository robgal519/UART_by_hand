#include "swo_logger.h"

#include <stdlib.h>

static LogConfiguration* Configuration;

void LogInit(LogConfiguration* cfg){
    Configuration = cfg;    

}

static void LogString(const char* message){
    while(*message){
        Configuration->send((uint32_t)*message);
        message++;
    }
}

void Log(LogLevel level, const char* message) {
    if(Configuration == NULL)
        return;
    if(Configuration->level < level)
        return;
    if(Configuration->send == NULL)
        return;

    
    LogString(LogLevelNames[level]);
    LogString("\t");
    LogString(message);
    LogString("\n");
}
