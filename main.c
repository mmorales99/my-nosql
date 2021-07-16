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
    myObj *mo;
    mo->base = (Object*)new_Object_p(mo,mo->base->this);
    return mo;
}

int main(){

    Object *o = new_Object_v();
    myObj *mo = new_MO();
    print("%p == %p",mo,((Object*)mo)->this);
    return 0;
}

#pragma endregion
#endif