#include "cabinet.h"

int IsDup_c( const CabList &cabs , char* id){
    int i = -1;
    Cabinet c;
    for(i;i<cabs.length();i++){
        c = cabs[i];
        if(i<0) continue;
        if(strcmp(c.id,id)==0) break;
    }
    return i;
}