#ifndef VALUE
#define VALUE

#include "lib.h"

#pragma region VALUE MORPHOLOGY
typedef struct ValueType{
    char *value;
    unsigned long long int id;
}Val;
typedef Val VaList[];
#pragma endregion

#pragma region VALUE RELATED FUNCTIONS
    int Contained_with(const KeyList, const Val *); // gives the key given a value, return first occurrance
    int Contained_in(const CabList, const Val *); // give the Cab where is located a value, return first occurrance
    Val* newVal(Val v);
    Val* newEmptyVal();
#pragma endregion

#endif
    
    /*
    numeric (numérico entero o real)
    string (cadena de caracteres)
    date (fecha en formato YYYY-MM-DD o YYYY/MM/DD)
    list (lista de valores separados por el carácter 'ø' → código ASCII 248)*/