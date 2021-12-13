#ifndef TYPES
#define TYPES

#pragma region ESPECIAL TYPES
    
    #pragma region STRING
        typedef struct StringType{
            char *values;
            size_t leng;
            unsigned int (*bytes)();
            void (*lconcat)();
            void (*rconcat)();
            void (*copy)(char*);
            char* (*split)();
        }string;
        
        size_t leng(const char* str){
            return (size_t)(sizeof(str)/sizeof(char));
        }
        void rconcat(string *str ,const char*c){
            size_t last_char = str->leng;
            str->values = (char*)realloc(str->values,sizeof(char)*str->leng + sizeof(c)/sizeof(char));
            last_char-=1;
            int i = 0;
            for(i;i<leng(c);i++){
                *(str->values+last_char+i) = (char)c[i];
            }
            *(str->values+leng(str->values)-1)='\0';
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
            if(str1!=null){
                free(str1);
            }
            str1=calloc(str2->leng,leng(str2->values));
            memset(str1->values,'\0',leng(str1->values));
            rconcat(str1,str2->values);
        }
        char* split(){
            return 'o';
        }
        string new_String(){
            string str;
            str.lconcat = lconcat;
            str.bytes = leng;
            str.rconcat = rconcat;
            str.split = split;
            str.values = calloc(0,sizeof(char));
            str.leng = 0;
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

#endif