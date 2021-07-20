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

    #pragma region STRING
        typedef struct StringType{
            char *values;
            size_t (*leng)();
            void (*lconcat)();
            void (*rconcat)();
            void (*copy)(char*);
            char* (*split)();
        }string;
        size_t leng(const char* str){
            return (size_t)(sizeof(str)/sizeof(char)+1);
        }
        void rconcat(char *str ,const char*c){
            int last_char = leng(str);
            str = realloc(str,last_char+leng(c));
            last_char-=1;
            int i = 0;
            for(i;i<leng(c);i++){
                str[last_char+i] = c[i];
            }
            str[leng(str)-1]='\0';
        }
        void lconcat(char *str ,const char*c){
            int last_char = leng(str);
            str = realloc(str,last_char+leng(c));
            last_char+=leng(c);
            int i = 0;
            char *aux[last_char+leng(c)];
            for(i=0;i<leng(str);i++){
                aux[i+leng(c)] = str+i;
            }
            for(i=0;i<leng(c);i++){
                aux[i] = c+i;
            }
            for(i=0;i<leng(str);i++) str[i] = aux[i];
            str[leng(str)-1]='\0';
        }
        void copy(string *str1, const string *str2){
            str1->values = realloc(str1->values, leng(str2->values));
            memset(str1->values,'\0',leng(str1->values));
            rconcat(str1->values,str2->values);
        }
        char* split(){
            return 'o';
        }
        string new_String(){
            string str;
            str.lconcat = lconcat;
            str.leng = leng;
            str.rconcat = rconcat;
            str.split = split;
            str.values = malloc(sizeof(char));
        }
    #pragma endregion

    #pragma region NUMERIC 
        typedef struct NumericType{
            string          value;
            signed int      (*ToInt)();
            float           (*ToFloat)();
            double          (*ToDouble)();
            unsigned int    (*ToUInt)();
            void (*Add)();
            void (*Sub)();
            void (*Mul)();
            void (*Div)();
        }numeric;
    #pragma endregion

    #pragma region DATE
        typedef struct{ numeric nvalue; }day;
        typedef struct{ numeric nvalue; }month;
        typedef struct{ numeric nvalue; }year;
        typedef struct DateType{
            string time;
            day Day;
            month Month;
            year Year;
            void (*Format)();
        }date;
    #pragma endregion

    #pragma region LIST
        typedef struct DataType{
            string value;
            size_t leng;
            char termination;
            char *next;
        }Data;
        typedef struct DataCollection{
            string value;
            Data *values;
        }List;
    #pragma endregion

    /*  Renamed Funcs   */  
    #define print printf
#pragma endregion

#pragma region BASE OBJECT SUPPORT
    typedef struct CannonicalObject{
        void *this;
        /*void* (*constructor)();
        const Object Object_default = {.this = null, .constructor = (Object*)new_Object_v};*/
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