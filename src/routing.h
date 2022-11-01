#ifndef __ROUTING__H__
#define __ROUTING__H__

    #include "comun.h"

    #define WINDOWS_SEPARATOR '\\'
    #define UNIX_SEPARATOR '/'

#if defined(_WIN32) || defined(WIN32) || defined(_WIN64) || defined(WIN64)
    #define ROUTE_SEPARATOR '\\'
#elif defined(__unix__ )
    #define ROUTE_SEPARATOR '/'
#else
    #define ROUTE_SEPARATOR '/'
#endif

const char* toPath(const char* non_safe_path){
    char* safe_path;
    t_size size = strlen(non_safe_path);
    safe_path = (char*)calloc(size,sizeof(char));
    memset(safe_path, '\0', sizeof(safe_path));
    strcpy(safe_path,non_safe_path);
    for(int i = 0; i < size; i++){
        if(non_safe_path[i] == WINDOWS_SEPARATOR){
            safe_path[i] = ROUTE_SEPARATOR;
        } else if(non_safe_path[i] == UNIX_SEPARATOR){
            safe_path[i] = ROUTE_SEPARATOR;
        }
    }
    const char* retornable = safe_path;
    return retornable;
}

int makedir(const char* path){
    #if defined(_WIN32) || defined(WIN32) 
        char * command = "mkdir \"";
        strcat(command,path);
        strcat(command,"\"");
        return system(command);
    #elif defined(_WIN64) || defined(WIN64)
        char * command = "New-Item -ItemType Directory -Path '";
        strcat(command,path);
        strcat(command,"'");
        return system(command);
    #elif defined(__unix__ )
        return mkdir(path);
    #endif
}

#endif