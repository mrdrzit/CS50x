#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int *list = malloc(3*sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    int *tmp = malloc(4*sizeof(int));
    if (tmp == NULL)
    {
        free(list); 
        return 1;
    }
}