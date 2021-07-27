#ifndef CABINET
#define CABINET

#include "lib.h"

#pragma region CABINET MORPHOLOGY

typedef struct KVPairType
{
    Key key;
    Val value;
    Keyval next;
    Keyval prev;
}Keyval;
typedef Keyval KeyvalList*;

typedef struct CabinetType{
    char *name;
    KeyvalList pairs;
    size_t size;
}Cabinet;


#pragma endregion

#pragma region CABINET RELATED FUNCTIONS
    int IsDup_c(const CabList &);
#pragma endregion

#endif