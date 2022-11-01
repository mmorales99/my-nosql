#ifndef PROMPT_H
#define PROMPT_H
#include "util.h"
#include "db.h"

typedef struct TERMINAL
{
    DBMS db;
} Prompt;

Prompt new_Prompt(DBMS db)
{
    Prompt p;
    p.db = db;
}


#endif