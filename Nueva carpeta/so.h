#ifndef SO_H
#define SO_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include "custom.h"

void makedir(const string path)
{
    #ifdef __linux__
    struct stat sb;
    if (stat(path, &sb) == 0 && (sb.st_mode & S_IFDIR)) {
    } else {
        mkdir(path, 0777);
    }
    #endif
}

string sgetline() {
    int lineLentgth = 0;
    string line = (string)calloc(1,sizeof(char));
    if(line is null) return null;
    line[0] = 0;
    while(line[lineLentgth-(lineLentgth<1?0:1)] not EOF and line[lineLentgth-(lineLentgth<1?0:1)] not '\n') {
        line[lineLentgth++] = (char)fgetc(stdin);
        line = (string)realloc(line,sizeof(char)*(strlen(line)+1));
        if(!line) return null;
    }
    if(strlen(line) > 0) line[strlen(line)-1] = '\0';
    return line;
}

#endif