#ifndef UTIL
#define UTIL

#pragma region INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "bool.h"
#pragma endregion

#pragma region ESPECIAL TYPES
    #define null NULL
    #define Null NULL
    #define undefined
    #define Undefined 

    #pragma region NUMERIC
        
        typedef struct StringType{
            char *values;
            size_t leng;
        }string;

        typedef struct NumericType{
            string value;
        }numeric;
        
        typedef struct{ short unsigned int value; }day;
        typedef struct{ short unsigned int value; }month;
        typedef struct{ short unsigned int value; }year;
        typedef struct DateType{
            string time;
        }date;

        typedef struct DataType{
            string value;
            size_t leng;
            char termination;
            char *next;
        }Data;
        typedef struct DataCollection{
            string value;
            Data *values;
        }
        

    #pragma endregion

    //////////////////////
    //  Renamed Funcs   //
    #define print printf
#pragma endregion

#pragma region BASE OBJECT SUPPORT
    typedef struct CannonicalObject{
        void *this;
        //void* (*constructor)();
        //const Object Object_default = {.this = null, .constructor = (Object*)new_Object_v};
    }Object;
    Object* New_Object_p(void*o){
        o = (Object*)malloc(sizeof(Object));
        ((Object*)o)->this = o;
        Object* b = o;
        b->this = ((Object*)o);
        return b;
    }
    Object* New_Object_v(){
        Object *o;
        o = (Object*)malloc(sizeof(Object));
        o->this = o;
        return o;
    }
    Object* New_Object(void*o){
        if(o == null){
            return New_Object_v();
        }else if(o!=null){
            return New_Object_p(o);
        }
        return null;
    }

    /*
    C doesn`t support objects natively, but its possible to trick the system like this:
    
    typedef struct myObject{ // all public methods
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

    typedef structMyOtherObject{ // has privacity
        union{
            const Object *base; // cannot be modified
            myObject *mo; // can be modified
        };
    }myOO;

    How to call object methods:
    mo->setMsg(((Object*)mo)->this,"aydioslmao");
    
    */
#pragma endregion


#endif