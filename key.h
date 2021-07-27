#ifndef KEY
#define KEY

#include "lib.h"

#pragma region KEY MORPHOLOGY
typedef struct KeyType{
    char *value;
    unsigned long long int id;
}Key;
typedef Key KeyList*;
#pragma endregion

#pragma region KEY RELATED FUNCTIONS
    int IsDup_k(const KeyList &);
#pragma endregion

#endif