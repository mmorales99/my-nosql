#ifndef CABINET
#define CABINET

#include "lib.h"

#pragma region CABINET MORPHOLOGY

typedef struct CabinetType{
    char *name;
    PairList pairs;
    unsigned long int size;
    unsigned long long int id
}Cabinet;

typedef Cabinet CabList[];

#pragma endregion

#pragma region CABINET RELATED FUNCTIONS
    int IsDup_c(const CabList*,unsigned long long int);
    CabList newCabList(CabList cl, unsigned total);
#pragma endregion

#endif