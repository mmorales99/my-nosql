#ifndef __DB__H__
#define __DB__H__

#include "Cabinet.h"

typedef struct DataBase{
    cabinet* cabs;
    t_size size;
}DB;

DB* InitDB(DB* db){
    db->cabs = NULL;
    db->size = 0;
    return db;
}
DB* resizeDB(DB* db, t_size new_size){
    if(db==NULL) return NULL;
    if(db->cabs == NULL){
        db->cabs = (cabinet*)calloc(new_size,sizeof(cabinet));
        db->size = new_size;
        for(int i = 0;i<new_size;i++){
            db->cabs[i] = _createEmptyCabinet();
        }
    }
    else if(db->size > new_size){
        for(int i = new_size; i < db->size; i++){
            free(db->cabs+i);
        }
        db->size = new_size;
    }
    else if(db->size < new_size){
        db->cabs = (cabinet*)realloc(db->cabs,sizeof(cabinet)*new_size);
        for(int i = db->size;i<new_size;i++){
            db->cabs[i] = _createEmptyCabinet();
        }
        db->size = new_size;
    }
    return db;
}

cabinet * _CrearDataBaseContent(cabinet *bd, t_size MAX_CAB){
    if(bd == NULL) bd = (cabinet*)calloc(MAX_CAB,sizeof(cabinet));
    for(int i=0;i<MAX_CAB;i++){
        bd[i] = _createEmptyCabinet();
    }
    return bd;
}

/*
    DEMO
*/
cabinet * CrearDataBase(cabinet *bd){
    t_size MAX_CAB = 5;
    _CrearDataBaseContent(bd,5);
    return bd;
}
    

#endif