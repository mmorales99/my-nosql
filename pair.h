#ifndef PAIR
#define PAIR

#include "lib.h"

#pragma region PAIR MORPHOLOGY

typedef struct KVPairType{
    Key key;
    Val value;
    Keyval *next;
    Keyval *prev;
}Keyval;
typedef Keyval KeyvalList*;
typedef Keyval Pair;
typedef Pair PairList*;
#pragma endregion

#pragma region PAIR RELATED FUNCTIONS
    Pair* newEmptyPair();
    Pair* newPair(Key k, Val v);
#pragma endregion

#endif