#include "pair.h"

Pair newEmptyPair(){
    Pair *p = (Pair)malloc(sizeof(Pair));
    p->key = newKey();
    p->value = newVal();
    p->next = null;
    p->prev null;
    return p;
}

Pair newPair(Key k, Val v){

}