#ifndef ERROR_H
#define ERROR_H
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "custom.h"
void thorw_fatal_error(const string str)
{
    printf("Error code: %i\n", errno);
    perror(str);
    exit(EXIT_FAILURE);
}

void thorw_error(const string str)
{
    printf("%s\n",str);
}
#endif