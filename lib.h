#ifndef UTIL
#define UTIL

#pragma region INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "bool.h"
#pragma endregion

#pragma region TIPOS ESPECIALES
    #define null NULL
    #define Null NULL
    #define undefined 

    #define print printf
#pragma endregion

    typedef struct CannonicalObject{
        void *this;
    }Object;

    Object* new_Object_p(void*o,void*that){
        that = o;
        return o;
    }
    Object* new_Object_v(){
        Object *o;
        o->this = &o;
        return o;
    }
    Object* new_Object(void*o,...){
        if(o == null){
            return new_Object_v();
        }else if(o!=null){
            va_list va;
        }
        return null;
    }

#endif