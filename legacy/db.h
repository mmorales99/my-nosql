#ifndef DB
#define DB

#include "lib.h"

#pragma region DB MORPHOLOGY

#define MAXCABINETS 5

typedef struct DataBaseType{
    char *name;
    unsigned long long int id;
    CabList cabinets;
}DataBase;

void Initialize(DataBase *db){
    db->cabinets = newCabList(db->cabinets,MAXCABINETS);
}

#pragma endregion

#endif