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

Key* newKey(Key k){
    Key *ik = newEmptyKey();
    strcpy(ik->value,k.value);
    return ik;
}

Key* newEmptyKey(){
    static unsigned long long int id_gen = 0;
    Key* k = (Key*)malloc(sizeof(Key));
    k->id = generateID(id_gen);
    return k;
}