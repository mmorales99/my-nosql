#ifndef CABINET
#define CABINET

#include "lib.h"

#pragma region CABINET MORPHOLOGY

typedef struct CabinetType{
    char *name;
    KeyvalList pairs;
    size_t size;
}Cabinet;

typedef Cabinet CabList*;

#pragma endregion

#pragma region CABINET RELATED FUNCTIONS
    int IsDup_c(const CabList &);
    CabList newCabList(CabList cl, unsigned total);
#pragma endregion

#endif