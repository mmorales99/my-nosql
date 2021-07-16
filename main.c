#ifndef MAIN
#define MAIN main

#pragma region INCLUDES
#include "lib.h"
#pragma endregion

#pragma region MAIN_CODE

typedef struct myObject{
    Object *base;
}myObj;
myObj* new_MO(){
    myObj *mo = (myObj*)malloc(sizeof(myObj));
    mo->base = (Object*)new_Object_p(mo,mo->base);
    return mo;
}

int main(){

    myObj *mo = new_MO();
    print("%p == %p",mo,mo->base->this);
    free(mo);
    return 0;
}

#pragma endregion
#endif