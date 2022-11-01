#ifndef __COMUN__H__
    #define __COMUN__H__

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>

    #if defined(_WIN32) || defined(WIN32) || defined(_WIN64) || defined(WIN64)
        #include <conio.h>
        #include <Windows.h>
    #else defined(__unix__ )
        #include <ncurses.h>
        #include <unistd.h>
    #endif

    #include "comun/bool.h"

    typedef unsigned long long int t_size;

    unsigned long int getTimeStamp(){
        time_t t0 = time(NULL);
        struct tm *t1 = localtime(&t0);
        unsigned long int ts = 0;
        ts = t1->tm_year+1900
            + t1->tm_mon
            + t1->tm_mday
            + t1->tm_hour
            + t1->tm_min
            + t1->tm_sec;
        return ts;
    }
#endif
