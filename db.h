#ifndef DB
#define DB

#include "lib.h"

#pragma region DB MORPHOLOGY

#define MAXCABINETS 5
typedef Cabinet CabinetList[MAXCABINETS];

typedef struct DataBaseType{
    char *name;
    CabinetList cabinets;
}DataBase;


#pragma endregion

#endif