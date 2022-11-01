#include "cabinet.h"

Cabinet* newCabinet(){
    Cabinet * c = (Cabinet*)malloc(sizeof(Cabinet));
    c->pairs = newEmptyPair();
    return c;
}
void destroyCabinet(Cabinet* c){

    free(c);
}

CabList newEmptyCabList(unsigned total){
    CabList l = (Cabinet*)calloc(total,sizeof(Cabinet));
    memset(&l,sizeof(Cabinet)*total,0);
    
}

CabList newCabList(CabList cl, unsigned total){
    if(cl==null) cl = newEmptyCabList(total);
    int i = 0;
    for(i;i<MAXCABINETS;i++){
        if(db->cabinets[i] == null) db->cabinets[i] = newCabinet();
        else { destroyCabinet(db->cabinets[i]); db->cabinets[i] = newCabinet(); }
    }
}

int IsDup_c( const CabList *cabs , unsigned long long int id){
    int i = -1;
    Cabinet *c;
    for(i;i<cabs->size;i++){
        c = (Cabinet*)cabs[i];
        if(i<0) continue;
        if(c->id == id) break;
    }
    return i;
}
