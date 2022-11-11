#include <stdio.h>
#include "so.h"
int main()
{
    while (true)
    {
        string c = sgetline();
        printf("%s", c);
    }
    
    return 0;
}