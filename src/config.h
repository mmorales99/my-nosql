#ifndef __CONFIG__H__
#define __CONFIG__H__

#include "comun.h"

#define DEFAULT_WORKSPACE "DATA"

int Install(){
    int exists = mkdir(toPath(DEFAULT_WORKSPACE));

    return exists;
}

#endif