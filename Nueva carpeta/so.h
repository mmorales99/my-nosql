#ifndef SO_H
#define SO_H
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

#endif
    