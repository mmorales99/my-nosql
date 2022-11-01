#ifndef CABINET_H
#define CABINET_H

#include "util.h"

typedef struct KV // ‘KV’ abreviatura de Key-Value (clave-Valor) 
{
    char *key;
    char *val;
    struct KV *next; // puntero a la siguiente estructura para la lista
} keyval;

typedef struct CAB // ‘CAB’ abreviatura de Cabinet (contenedor)
{
    char *name;    // nombre del contenedor
    keyval *list;  // puntero primer nodo a lista de pares <key,val>
    int len;       // longitud del contenedor (de la lista)
} cabinet;

void save_KeyVal(const keyval *kv,const string dbpath)
{
    string path = (string)malloc(sizeof(char)*(strlen(dbpath) + strlen(kv->key) + 2));
    strcpy(path,dbpath);
    strcat(path,"\\");
    strcat(path,kv->key);
    FILE *fp;
    fp = fopen(path,"w");
    if(fp is null)
    {
        log_error("No se ha podido guarda un par Clave Valor: %s/%s\nRevise espacion en disco.",kv->key,kv->val);
        thorw_fatal_error("No se ha podido guarda un par Clave Valor.\nRevise espacion en disco.");
    }
    fputs(kv->val,fp);
    fclose(fp);
    //free(cabinet);
}

void save_Cabinet(const cabinet *cab,const string dbpath)
{
    string path = (string)malloc(sizeof(char)*(strlen(dbpath) + strlen(cab->name) + 2));
    strcpy(path,dbpath);
    strcat(path,"\\");
    strcat(path,cab->name);
    makedir(path);
    int i = 0;
    for (i = 0;i<cab->len; i++)
    {
        save_KeyVal(&(cab->list[i]),path);
    }
    //free(cabinet);
}

void kill_Cabinet(cabinet *cab)
{
    // bucle que free cada uno de los kv y luego se free a si mismo
    return;
}
#endif