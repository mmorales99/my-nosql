#ifndef __COMUN__H__
    #define __COMUN__H__

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>
    #include <errno.h>

    #if defined(_WIN32) || defined(WIN32) || defined(_WIN64) || defined(WIN64)
        #include <conio.h>
        #include <Windows.h>
    #elif defined(__unix__ )
        #include <sys/stat.h>
        #include <ncurses.h>
        #include <unistd.h>
    #endif

    #include "bool.h"
    #include "config.h"
    #include "routing.h"

    typedef unsigned long long int t_size;

    unsigned long int getTimeStamp(){
        time_t t0 = time(NULL);
        struct tm *t1 = localtime(&t0);
        unsigned long int ts = 0;
        ts = 
            ( ( ( ( (t1->tm_year+1900)*100 + t1->tm_mon)*100 + t1->tm_mday)*100 + t1->tm_hour)*100 + t1->tm_min)*100 + t1->tm_sec;
        return ts;
    }
#endif
