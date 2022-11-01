#include <stdio.h>
#include "db.h"
#include "prompt.h"

#include "util.h"

int main ()
{
    LOGCONF log_conf = {
        .MAXLOGLEVEL = CONST_LOGGING_LEVELS.INFO,
        .CONSOLE = true,
        .OUTPUT = "./log/log",
        .MAXFILEMB = 1000,
        .CICLE = true,
        .CICLES = 5
    };
    UseLogConfig(&log_conf);
    log_verbose("Iniciando el programa.");
    InicializarConfig();

    CrearEstructura();

    DBMS db = new_DB();
    Prompt p = new_Prompt(db);

    log_verbose("Fin del programa.");
}