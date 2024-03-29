#ifndef LOGGIN_H
#define LOGGIN_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "error.h"
#include "custom.h"
#include "bool.h"

/* maybe add custom logging level? */
/* do this serializable from file and if not file defiend then use this _standard_ levels */
typedef enum LOGGING_LEVELS
{
    ERROR = 0,
    WARNING = 1,
    INFO = 2,
    VERBOSE  = 3
} LOG_LEVEL;

typedef struct STANDAR_LOGGING_LEVELS
{
    int ERROR;
    int WARNING;
    int INFO;
    int VERBOSE;
}SLL;

const SLL CONST_LOGGING_LEVELS = {0, 1, 2, 3};

typedef struct LOGGIN_CONFIGURATION{
    LOG_LEVEL MAXLOGLEVEL;
    string OUTPUT;
    int CICLES;
    bool CICLE;
    bool CONSOLE;
    long int MAXFILEMB;
} LOGCONF;

const LOGCONF DEFAULT_LOG_CONF = {
    .MAXLOGLEVEL = VERBOSE,
    .OUTPUT = "./log",
    .CICLES = 10,
    .CICLE = true,
    .CONSOLE = false,
    .MAXFILEMB = 1000000
};

LOGCONF LOG_CONF = DEFAULT_LOG_CONF;

void UseLogConfig( const LOGCONF *conf )
{
    if(conf is null)
        LOG_CONF = DEFAULT_LOG_CONF;
    else{
        LOG_CONF = *conf;
    }
}

int FILECICLE = 0;
bool alreadyCicled = false;
string logFileName;

int tolog(const LOG_LEVEL level, const string str, va_list args)
{
    if(level < 0 or level > LOG_CONF.MAXLOGLEVEL or LOG_CONF.MAXLOGLEVEL > 3 or LOG_CONF.MAXLOGLEVEL < 0)
        return 0;
    if(str is null || strlen(str) is 0)
        return 0;
    /* maybe add custom logging level? */
    string LEVELS[4] = {"ERROR", "WARNING", "INFO", "VERBOSE"};
    int messageLength = strlen(str);
    char *message = (char*)calloc(messageLength+1,(messageLength+1)*sizeof(char));
    strcat(message, str);
    strcat(message, "\n");
    time_t now;
    time(&now);
    char * date = ctime(&now);
    date[strlen(date) - 1] = '\0';

    FILE *fp;

    if(FILECICLE >= LOG_CONF.CICLES)
    {
        FILECICLE = 0;
        alreadyCicled = true;
    }
    string newFileName = (string)calloc(strlen(LOG_CONF.OUTPUT)+10,(strlen(LOG_CONF.OUTPUT)+10)*sizeof(char));
    strcat(newFileName,LOG_CONF.OUTPUT);
    strcat(newFileName,"%i");
    string logFileName = (string)calloc(strlen(newFileName),(strlen(newFileName))*sizeof(char));
    sprintf(logFileName,newFileName,FILECICLE);

    fp = fopen(logFileName,alreadyCicled?"w":"a+");
    if(fp is null)
    {
        thorw_fatal_error("No se encuentra la ruta donde depositar los logs. Asegurese de que existe.");
    }

    if(alreadyCicled)
        fseek(fp,0,SEEK_END);

    int total_needed_mem = fprintf(fp, "[%s - %s] ", date, LEVELS[level]);
    total_needed_mem += vfprintf(fp, message, args);
    if(LOG_CONF.CONSOLE)
    {
        fseek(fp, -1*total_needed_mem, SEEK_END);
        string temp = (string)malloc(sizeof(char)*total_needed_mem);
        fgets(temp, total_needed_mem, fp);
        printf("%s\n",temp);
        free(temp);
    }

    long int totalChars = ftell(fp);
    if(totalChars >= LOG_CONF.MAXFILEMB)
        FILECICLE++;

    fclose(fp);
    free(message);
    free(newFileName);
    free(logFileName);
    return 0;
}

void log_error(const string str, ...)
{
    va_list args;   
    va_start(args, str);
    tolog(ERROR, str, args);
    va_end(args);
}

void log_warning(const string str, ...)
{
    va_list args;   
    va_start(args, str);
    tolog(WARNING, str, args);
    va_end(args);
}

void log_info(const string str, ...)
{
    va_list args;   
    va_start(args, str);
    tolog(INFO, str, args);
    va_end(args);
}

void log_verbose(const string str, ...)
{
    va_list args;   
    va_start(args, str);
    tolog(VERBOSE, str, args);
    va_end(args);
}

#endif