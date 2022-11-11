#ifndef PROMPT_H
#define PROMPT_H
#include "util.h"
#include "db.h"
#include "loggin.h"
#include "commands.h"

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
};

Prompt new_Prompt(DBMS db)
{
    if(db  is null) log_verbose("Creando terminal sin base de datos.");
    else log_verbose("Creando terminal con base de datos(%s).",db->name);
    Prompt p = DEFAULT_PROMPT;
    p.db = db;
    return p;
}

void printInfo(){
    string info =
        "\
        \n\
        AUTHOR: MANUEL JUAN MORALES AMAT\n\
        EMIAL: mjmorales.mcv+dev@gmail.com\n\
        \n\
        WELCOME TO LDB (Light Data Base).\n\
        Version: 0.0.0\n\
        \n\
        \n\
        TRY USING help FOR A COMPLETE LIST OF COMMANDS\n\
        TRY newDB TO GET STARTED...\n\
        \n\
        TRY terminate TO EXIT...\n\
        \n\
        ==============================================\n\
        ";
    printf("%s",info);
}

void execute(Prompt *p, const string* tokens,const int total_tokens)
{

}
void showError(const string* tokens,const int total_tokens)
{

}
bool tryExecute(Prompt *p, const string command){
    if(command is null)
        return false;
    log_info("Trying to execute %s.",command);
    if(strcmp(command,"terminate") is 0)
    {
        printf("WARNING::This will terminate session. It will leave memory trash loaded.\n");
        printf("Are you sure? yes | no\n");
        command = sgetline();
        if(equals(command,"YES"))
            return true;
        else
            return false;
    }
    bool correctSintax = false, correctSemantic = false;
    log_info("TryExecute: Trying to tokenize.");
    int total_tokens = 0;
    string* tokens = checkSintax(command, &correctSintax, &total_tokens);
    log_info("TryExecute: Tokenized to %i tokens.",total_tokens);
    for (int i = 0;i<total_tokens;i++)
        log_info("TryExecute: Tokens[%i] - |%s|",i,tokens[i]);
    if (correctSintax)
            correctSemantic = checkSemantica((const string *)tokens, total_tokens);
    if(correctSemantic)
        execute(p, (const string*)tokens, total_tokens);
    else
        showError((const string*)tokens, total_tokens);
    free(tokens);
    return false;
}

void Prompt_StartSession(Prompt *p)
{
    string command = null;
    command = (string)calloc(strlen("start\0"),sizeof(char)*strlen("start\0"));
    strcpy(command,"start\0");
    printInfo();
    bool terminate = false;
    while(!terminate)
    {
        printf("%s",p->text);
        free(command);
        command = sgetline();
        terminate = tryExecute(p,command);
    }
}

void Prompt_SaveDB(Prompt *p, const DBMS bd)
{
    if(p->text not null) free(p->text);
    int newLength = (strlen(p->db->name) + strlen(DEFAULT_PROMPT.text)+1);
    p->text = (string)calloc(newLength,sizeof(char)*newLength);
    strcpy(p->text,"[");
    strcat(p->text,p->db->name);
    strcat(p->text,"/.]>>");
}

void Prompt_SaveCab(Prompt *p)
{
    if(p->text not null) free(p->text);
    int newLength = (strlen(p->db->name) + strlen(DEFAULT_PROMPT.text)+1+strlen(p->activeCab->name));
    p->text = (string)calloc(newLength,sizeof(char)*newLength);
    strcpy(p->text,"[");
    strcat(p->text,p->db->name);
    strcat(p->text,"/");
    strcat(p->text,p->activeCab->name);
    strcat(p->text,"]>>");
}

void Prompt_ModifyDB(Prompt *p)
{
    if(p->text not null) free(p->text);
    int newLength = (strlen(p->db->name) + strlen(DEFAULT_PROMPT.text)+1);
    p->text = (string)calloc(newLength,sizeof(char)*newLength);
    strcpy(p->text,"[");
    strcat(p->text,p->db->name);
    strcat(p->text,"/.]*>>");
}

void Prompt_ModifyCab(Prompt *p)
{
    if(p->text not null) free(p->text);
    int newLength = (strlen(p->db->name) + strlen(DEFAULT_PROMPT.text)+1+strlen(p->activeCab->name));
    p->text = (string)calloc(newLength,sizeof(char)*newLength);
    strcpy(p->text,"[");
    strcat(p->text,p->db->name);
    strcat(p->text,"/");
    strcat(p->text,p->activeCab->name);
    strcat(p->text,"]*>>");
}

void Prompt_SelectDB(Prompt *p, DBMS bd)
{
    Prompt_SaveDB(p,bd);
    if(p->db not null) kill_DB(p->db);
    p->db = bd;
}

void Prompt_SelectCAB(Prompt *p, cabinet *cab)
{
    Prompt_SaveCab(p);
    if(p->activeCab not null) kill_Cabinet(p->activeCab);
    p->activeCab = cab;
}



#endif