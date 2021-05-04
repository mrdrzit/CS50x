#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//If you use malloc, valgrind (in the cs50 IDE) can detect memory leaks

int main(void)
{
    char *s = get_string("s: ");
    char *t = malloc(strlen(s) + 1); //allocate a memory address for this pointer
    if (t == NULL)
    {
        return 1;
    }

    strcpy(t,s);

    t[0] = toupper(t[0]);
    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(t); //Free up the memory allocated by malloc (The exact same number of bytes)
}
