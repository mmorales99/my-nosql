#include "key.h"

int IsDup_k( const KeyList &keys , char* id){
    int i = -1;
    Key k;
    for(i;i<keys.length();i++){
        k = keys[i];
        if(i<0) continue;
        if(strcmp(k.id,id)==0) break;
    }
    return i;
}