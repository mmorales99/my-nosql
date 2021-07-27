#include "cabinet.h"

Cabinet* newCabinet(){
    Cabinet * c = (Cabinet)malloc(sizeof(Cabinet));
    c->pairs = newEmptyPair();
    return 
}
void destroyCabinet(Cabinet* c){

    free(c);
}

CabList newCabList(CabList cl, unsigned total){
    if(cl==null) cl = newEmptyCabList(total);
    int i = 0;
    for(i;i<MAXCABINETS;i++){
        if(db->cabinets[i] == null) db->cabinets[i] = newCabinet();
        else { destroyCabinet(db->cabinets[i]); db->cabinets[i] = newCabinet(); }
    }
}

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
