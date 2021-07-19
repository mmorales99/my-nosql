#ifndef UTIL
#define UTIL

#pragma region INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
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
        //void* (*constructor)();
        //const Object Object_default = {.this = null, .constructor = (Object*)new_Object_v};
    }Object;

    typedef struct InheritedCannonical{
        Object base;
        void * this;
    }Heir;
    

    Object* new_Object(void*o);

    
    #define Type(x) (__typeof__(x))
    
    Object* new_Object_p(void*o){
        o = (Object*)malloc(sizeof(Object));
        ((Object*)o)->this = o;
        Object* b = o;
        b->this = ((Object*)o);
        return b;
    }
    Object* new_Object_v(){
        Object *o;
        o = (Object*)malloc(sizeof(Object));
        o->this = o;
        return o;
    }
    Object* new_Object(void*o){
        if(o == null){
            return new_Object_v();
        }else if(o!=null){
            return new_Object_p(o);
        }
        return null;
    }

#endif