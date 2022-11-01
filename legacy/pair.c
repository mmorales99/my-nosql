#include "pair.h"

Pair* newEmptyPair(){
    Pair *p = (Pair)malloc(sizeof(Pair));
    p->key = newEmptyKey();
    p->value = newEmptyVal();
    p->next = null;
    p->prev null;
    return p;
}

Pair* newPair(Key k, Val v){
    Pair *p = (Pair)malloc(sizeof(Pair));
    p->key = newKey(k);
    p->value = newVal(v);
    p->next = null;
    p->prev null;
    return p;
}