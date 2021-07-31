// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"

//Prototype for the hash function
unsigned long hash(char *word);

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table
const unsigned int N = 50;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO #10 Create Check Function
    // Its case insensitive
    // Acess the list at the index found
    // Look for the word with strcasecmp
    return false;
}

// djb2 hash function from http://www.cse.yorku.ca/~oz/hash.html
// Hashes word to a number
unsigned long hash(char *word)
{
    // TODO #11 Create Hash function (or find a good one in the internet)
    // Receives a word with alphabetical chars and apostrophes
    // Coughs out a numerical index between 0 and N - 1 (inclusive)
    // Needs to be deterministic as in, when calculating the hash, it outputs the same result every time

    unsigned long hash = 5381;
    int c;
    while ((c = *word++))
    {
        hash = ((hash << 5) + hash) + tolower(c);
    }
    return hash % (N - 1);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO #12 Create the load function
    // Read strings from the file one at a time
    // fscanf, which returns a EOF when it reaches the end

    // Create a new node for each word
    // Use malloc for each node and check for null value
    // Copy word into the node using strcpy

    // Hash the word to obtain a hash value
    // The hash function return an index

    // Insert node into hashtable at that location
    // Index into the hash table using the correct pointer onder
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO #13 Create a size func #13
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO #14 Create a unload fu #14on
    return false;
}
