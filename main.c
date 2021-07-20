#ifndef MAIN
#define MAIN main

#pragma region INCLUDES
#include "lib.h"
#pragma endregion

#pragma region MAIN_CODE


int main(){
    //string str = new_String();
    char *str = "hola";
    char *ctr = "mundo";
    rconcat(str,ctr);
    print("%s\n",str);
    return 0;
}

#pragma endregion
#endif