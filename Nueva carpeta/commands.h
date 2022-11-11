#ifndef COMMANDS_H
#define COMMANDS_H
#include <stdio.h>
#include <stdlib.h>
#include "custom.h"
#include "string_extension.h"
#include "loggin.h"
#include "db.h"
#include "commands/quit.h"

const int TOTAL_DEFAULT_COMMAND = 23;
const string DEFAULT_COMMAND_LIST[] = {
    "QUIT",
    "NEWDB",
    "SAVEDB",
    "LISTDB",
    "ACTIVEDB",
    //"COPYDB",
    "NEWCAB",
    "LISTCAB",
    "ACTIVECAB",
    "COPYCAB",
    "SETPAIR",
    "GETVALUE",
    "GETKEY", // BUSCAR CLAVE POR PATRON O PARECIDO
    "DEL",
    "RPUSH",
    "LPUSH",
    "RPOP",
    "LPOP",
    "RANGE",
    "INC",
    "DEC",
    "RNKEY",
    "SORT",
    "TERMINATE",
};

bool isCommand(const string command){
    if(command is null or strlen(command) is 0)
        return false;
    int i = 0;
    bool check = false;
    for (i;i<TOTAL_DEFAULT_COMMAND;i++)
        check |= stringContains(command,DEFAULT_COMMAND_LIST[i]);
    return check;
}

string * checkSintax(const string comand, bool *check, int *total_tokens)
{
    log_info("Checking Sintax");
    log_info("Checking Sintax: Trying to tokenize.");
    string* tokens = tokenize(comand,total_tokens);
    log_info("Checking Sintax: Tokenized to %i.",*total_tokens);
    for (int i = 0;i<*total_tokens;i++) log_info("Checking Sintax: Tokens[%i] - |%s|",i,tokens[i]);
    *check = isCommand(tokens[0]);
    return tokens;
}

bool checkSemantica(const string* tokens,const int total_tokens)
{
    const string command = tokens[0];
    if(equals(command,"QUIT"))
        return quit_semantic(tokens,total_tokens);
    return false;
}

#endif