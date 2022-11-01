#ifndef DB_H
#define DB_H

#include "util.h"

#include "cabinet.h"

typedef struct DATABASE
{
    int total_cabinets;
    cabinet *cabinets;
    string name;
} DB;

typedef DB* DBMS;

void ClearDB(DBMS db)
{
    if(db == null)
    {
        thorw_error("No se puede inicializar/limpiar una base de datos nula.");
        return;
    }
    log_info("Inicializando %i cabinets.",db->total_cabinets);
    int i = 0;
    for (i; i < db->total_cabinets ; i++)
    {
        db->cabinets[i].len = 0;
        db->cabinets[i].list = null;
        db->cabinets[i].name = null;
        log_info("Cabinet construido {len:%i,name:%s}.",db->cabinets[i].len,db->cabinets[i].name);
    }
    log_info("%i cabinets inicializados.",db->total_cabinets);
}

void kill_DB(DBMS db)
{
    int i = 0;
    for (i;i<db->total_cabinets;i++)
    {
        kill_Cabinet(&(db->cabinets[i]));
    }
    free(db->cabinets);
    free(db->name);
    free(db);
}

DBMS new_DB_i(int total_cabinets)
{
    if(total_cabinets < 1) {
        thorw_error("No se puede inicializar menos de 1 cabinet.");
        return null;
    }
    log_info("Construyendo DBMS.");
    DBMS db = (DBMS) malloc(sizeof(DB));
    db->total_cabinets = total_cabinets;
    db->cabinets = (cabinet*)calloc(total_cabinets,total_cabinets*sizeof(cabinet));
    log_info("DBMS construido con: %i cabinets.",db->total_cabinets);
    ClearDB(db);
    return db;
}

DBMS new_DB()
{
    DBMS db = new_DB_i(1);
    if(db is null)
        thorw_error("No se ha podido crear una base datos con almenos 1 cabient.");
    return db;
}

void save_DB(const DBMS db)
{
    string path = (string)malloc(sizeof(char)*(strlen(globalConfig.savePath) + strlen(db->name) + 2));
    strcpy(path,globalConfig.originConfig);
    strcat(path,"\\");
    strcat(path,db->name);
    makedir(path);
    int i = 0;
    for (i;i<db->total_cabinets;i++)
    {
        save_Cabinet(&(db->cabinets[i]),path);
    }
    //free(db);
}

#endif