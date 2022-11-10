#ifndef CONFIG_H
#define CONFIG_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <sys/stat.h>
#include "error.h"
#include "custom.h"
#include "loggin.h"
#include "so.h"

const string rootFolder = "DATA";

typedef struct CONFIGURATION
{
    string savePath;
    string originConfig;
} Config;

const Config DEFAUTL_CONFIG = {
    .savePath = "./DATA",
    .originConfig = "./.config"
};

Config globalConfig = DEFAUTL_CONFIG;

void UseConfig(const Config *config)
{
    if (config is null)
    {
        log_warning("Asumiendo configuracion por defecto.");
        globalConfig = DEFAUTL_CONFIG;
    }
    globalConfig = *config;
    globalConfig.originConfig = config->originConfig is null ? "./.config" : config->originConfig;
}
void addToConfig(const string key, const string value)
{
    if(strcmp("SavePath",key)==0){
        globalConfig.savePath = null;
        globalConfig.savePath = (string)malloc(sizeof(char) * strlen(value) + 1);
        strcpy(globalConfig.savePath, value);
        log_verbose("Configurado SavePath con el valor: %s",key);
    }
}
void InicializarConfig ()
{
    log_verbose("Iniciando configuracion.");
    string defConfig = globalConfig.originConfig;

    FILE *fp;
    fp = fopen(defConfig, "r");
    if(fp is null)
    {
        log_warning("El archivo de configuracion %s no existe.",defConfig);
        UseConfig(NULL);
        return;
    }
    #ifdef __linux__
        char *line = NULL;
        size_t len = 0;
        ssize_t nread;
        while ((nread = getline(&line, &len, fp)) not -1) {
            log_verbose("Leyendo linea de configuracion, longitud %zu: %s\n", nread, line);
            const char sep[2] = ":";
            char *token;
            char *token2;
            token = strtok(line,sep);
            token2 = strtok(NULL, sep);
            addToConfig(token,token2);
        }
    #endif
    fclose(fp);
}

void CrearEstructura() 
{
    // #ifdef __linux__
    //     #include <dirent.h>
    //     #include <errno.h>
    //     DIR* dir = opendir("mydir");
    //     if (dir) {
    //         /* Directory exists. */
    //         closedir(dir);
    //     } else if (ENOENT == errno) {
    //          mkdir(globalConfig.savePath);
    //     } else {
    //         /* opendir() failed for some other reason. */
    //     }
    // #endif

    makedir(globalConfig.savePath);
}

#endif