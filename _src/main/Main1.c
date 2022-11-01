#ifndef __MAIN__1__
#define __MAIN__1__

#include "comun/comun.h"
#include "KeyValue/KeyValue.h"
#include "db/Cabinet.h"

int main(){
    t_size MAX_CAB = 5;
    cabinet *bd = NULL;

    bd = calloc(MAX_CAB,sizeof(cabinet));
    for(int i=0;i<MAX_CAB;i++){
        bd[i] = _createEmptyCabinet();
    }
}

#endif