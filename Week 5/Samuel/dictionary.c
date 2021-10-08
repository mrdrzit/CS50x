// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = (LENGTH + 1)* 'z';

// Hash table
node *table[N];

int total_words = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // get the hash value of the word
    unsigned int index = hash(word);

    node *head = table[index];
    node *cursor = head;

    // access linked list at that index in the hash table
    while (cursor != NULL)
    {
        // traverse linked list, looking for the word (strcasecmp)
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
// hash table
// by Robert Edwards
unsigned int hash(const char *word)
{
    // TODO
    int g = 31;
    unsigned long hash = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        hash = g * hash + tolower(word[i]);
    }
    return (hash % N); // hash % array's size
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // open dictionary
    FILE *dic_type = fopen(dictionary, "r");
    if (dic_type == NULL)
    {
        return false;
    }

    // read strings from file(dictionary) one at a time till the end of it
    char word[LENGTH + 1];
    while (fscanf(dic_type, "%s", word) != EOF)
    {
        // create a new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(dic_type);
            return false;
        }

        strcpy(n->word, word);
        n->next = NULL;

        // hash word to obtain a hash value(index)
        unsigned int index = hash(n->word);
        //printf("The position at which this node would go is: %d\n", index); // Debugging statementent

        // insert node into the hash table at that location
        if (table[index] == NULL)
        {
            table[index] = n;

        }

        // if table[index] is already storing a value at that location
        // linked list
        else
        {                               //table[index]->n1->n2->n3
            n->next = table[index];     //          \\  ||
            table[index] = n;           //            new_n
        }                               //table[index]->new_n->n1->n2->n3

        total_words++;
    }

    fclose(dic_type);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return total_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{

    // iterate through the array
    for (int index = 0; index < N; index++)
    {
        node *head = table[index];
        node *cursor = head;
        node *tmp = head;

        // freeing the linked list
        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }

    }

    return true;
}
