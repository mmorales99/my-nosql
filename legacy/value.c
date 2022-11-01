#include "value.h"

Val* newVal(Val k){
    Val *ik = newEmptyVal();
    strcpy(ik->value,k.value);
    return ik;
}

Val* newEmptyVal(){
    static unsigned long long int id_gen = 0;
    Val* k = (Val*)malloc(sizeof(Val));
    k->id = generateID(id_gen);
    return k;
}