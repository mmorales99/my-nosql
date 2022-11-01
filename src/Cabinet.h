#ifndef __CAB__H__
#define __CAB__H__

#include "comun.h"
#include "KeyValue.h"

typedef struct CAB{
    unsigned long int id;
    char *name;
    pair *list;
    t_size len; 
} cabinet;

cabinet _createEmptyCabinet(){
    cabinet cab;
    cab.name = NULL;
    cab.list = NULL;
    cab.len = 0;
    cab.id = getTimeStamp();
    return cab;
}

cabinet* createEmptyCabinet(cabinet *cab){
    if(cab == NULL) *cab = _createEmptyCabinet();
    return cab;
}
#endif