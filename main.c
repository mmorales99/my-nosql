#ifndef MAIN
#define MAIN main

#pragma region INCLUDES
#include "lib.h"
#pragma endregion

#pragma region MAIN_CODE

typedef struct myObject{
    Object *base;
    const char * msg;
    bool (*setMsg)();
}myObj;
bool _SetMSG(myObj* this, char * new_msg){
    char *_msg = &(this->msg);
    _msg = realloc(_msg,new_msg == null ? 0 : sizeof(new_msg));
    strncpy(this->msg,new_msg,strlen(new_msg));
    return true;
}
myObj* new_MO(){
    myObj *mo = (myObj*)new_Object_p(mo);
    mo->msg = (char*)malloc(sizeof(char)*20);
    mo->setMsg = _SetMSG;
    return mo;
}


int main(){

    printf("%ld\n", strlen("abcd"));

    myObj *mo = new_MO();
    mo->setMsg(((Object*)mo)->this,"aydioslmao");
    print("%p == %p == %p == %p\n",mo,mo->base->this,(mo->base)->this,((Object*)mo)->this);
    print("%s\n",mo->msg);
    free(mo);
    return 0;
}

#pragma endregion
#endif