#ifndef UTIL
#define UTIL

#define null NULL
#define Null NULL
#define undefined
#define Undefined 

#pragma region INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "bool.h"
//#include "objects.h"
//#include "types.h"
#pragma endregion

unsigned long long int generateID(unsigned long long gen){
    int c;
    return gen*c;
}

#pragma region DEPENDENCIES
    #include "value.h"
    #include "key.h"
    #include "pair.h"
    #include "cabinet.h"
    #include "db.h"
#pragma endregion

#endif