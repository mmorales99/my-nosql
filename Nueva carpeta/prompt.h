#ifndef PROMPT_H
#define PROMPT_H
#include "util.h"
#include "db.h"
#include "loggin.h"

typedef struct TERMINAL
{
    DBMS db;
    string text;
    cabinet* activeCab;
} Prompt;

const Prompt DEFAULT_PROMPT = {
    .db = null,
    .text = "[./.]>>",
    .activeCab = null
}

Prompt new_Prompt(DBMS db)
{
    if(db  is null) log_verbose("Creando terminal sin base de datos.");
    else log_verbose("Creando terminal con base de datos(%s).",db->name);
    Prompt p = DEFAULT_PROMPT;
    p.db = db;
    return p;
}

string * checkSintax(const string comand, bool *check)
{
    string* tokens = null;

    return tokens;
}

void checkSemantica(const string* tokens)
{

}

typedef enum DEFAULT_COMMAND_LIST{
    QUIT,
    NEWDB,
    SAVEDB,
    LISTDB,
    ACTIVEDB,
    //COPYDB
    NEWCAB,
    LISTCAB,
    ACTIVECAB,
    COPYCAB
    SETPAIR,
    GETVALUE,
    GETKEY, // BUSCAR CLAVE POR PATRON O PARECIDO
    DEL,
    RPUSH,
    LPUSH,
    RPOP,
    LPOP,
    RANGE,
    INC,
    DEC,
    RNKEY,
    SORT,
    TERMINATE,
}ComandList;

void Prompt_StartSession(Prompt *p)
{
    string command = null;
    command = (string)calloc(strlen("start\0"),sizeof(char)*strlen("start\0"));
    strcpy(command,"start\0");
    string* tokens = null;
    while(strcmp(command,"terminate") is 0)
    {
        printf("%s",p->text);
        free(command);
        command = sgetline();
        tokens = checkSintax(command);
        checkSemantica(tokens);
        free(tokens);
    }
}

void Prompt_SaveDB(Prompt *p, const DBMS bd)
{
    if(p->text not null) free(p->text);
    int newLength = (strlen(bd->name) + strlen(DEFAULT_PROMPT.text)+1);
    p->text = (string)calloc(newLength,sizeof(char)*newLength);
    strcpy(p->text,"[");
    strcat(p->text,bd->name);
    strcat(p->text,"/.]>>");
}

void Prompt_SaveCab(Prompt *p, const DBMS bd, const cabinet *cab)
{
    if(p->text not null) free(p->text);
    int newLength = (strlen(bd->name) + strlen(DEFAULT_PROMPT.text)+1+strlen(cab->name));
    p->text = (string)calloc(newLength,sizeof(char)*newLength);
    strcpy(p->text,"[");
    strcat(p->text,bd->name);
    strcat(p->text,"/");
    strcat(p->text,cab->name);
    strcat(p->text,"]>>");
}

void Prompt_ModifyDB(Prompt *p, const DBMS bd)
{
    if(p->text not null) free(p->text);
    int newLength = (strlen(bd->name) + strlen(DEFAULT_PROMPT.text)+1);
    p->text = (string)calloc(newLength,sizeof(char)*newLength);
    strcpy(p->text,"[");
    strcat(p->text,bd->name);
    strcat(p->text,"/.]*>>");
}

void Prompt_ModifyCab(Prompt *p, const DBMS bd, const cabinet *cab)
{
    if(p->text not null) free(p->text);
    int newLength = (strlen(bd->name) + strlen(DEFAULT_PROMPT.text)+1+strlen(cab->name));
    p->text = (string)calloc(newLength,sizeof(char)*newLength);
    strcpy(p->text,"[");
    strcat(p->text,bd->name);
    strcat(p->text,"/");
    strcat(p->text,cab->name);
    strcat(p->text,"]*>>");
}

void Prompt_SelectDB(Prompt *p, const DBMS bd)
{
    Prompt_SaveDB(p,bd);
    if(p->db not null) kill_DB(p->db);
    p->db = bd;
}

void Prompt_SelectCAB(Prompt *p, const DBMS bd, const cabinet *cab)
{
    Prompt_SaveCab(p, bd, cab);
    if(p->activeCab not null) kill_Cabinet(p->activeCab);
    p->activeCab = cab;
}



#endif