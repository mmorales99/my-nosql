#ifndef __KV__H__
    #define __KV__H__

    #include "comun.h"

    typedef struct KV{
        unsigned long int id;
        char *key;
        char *val;
        struct KV *next;
    } pair;

#endif
