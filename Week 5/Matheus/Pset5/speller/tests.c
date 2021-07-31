#include <ctype.h>
#include <stdio.h>

#include "dictionary.h"

#define HASHTABLE 31
#define MAXSTR 46

// djb2 hash function from http://www.cse.yorku.ca/~oz/hash.html
unsigned long hash_func (char* word)
{
    unsigned long hash = 5381;
    int c;
    while ((c = *word++))
    {
        hash = ((hash << 5) + hash) + tolower(c);
    }
    return hash % HASHTABLE;
}

int main(void)
{
    char* nome = "MATHEUS";
    long index = hash_func(nome);
    printf("Key is %ld", index);
}
