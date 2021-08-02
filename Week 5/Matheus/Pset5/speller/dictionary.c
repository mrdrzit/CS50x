// Implements a dictionary's functionality

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "dictionary.h"


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    int is_occupied;
    int offset;
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
unsigned int hash(const char *word)
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

    FILE *input = fopen(dictionary, "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return false;
    }

    char word[LENGTH];
    initialize(table, 97); // Função que inicializa todos os valores dentro da hashtable pra 0
    int hash_offset = 0; // Inicializa o valor que será o offset caso haja alguma colisão de chaves 

    while (fscanf(input, "%s", word) != EOF)
    {
        char fst_letter = tolower(word[0]); // Pega a primeira letra da palavra escaneada (tolower pra ficar sempre igual)
        int pos_alphab = fst_letter - 97;   // Usa a letra pra definir em qual posição inicial ela vai. Ordem alfabetica.

        //Check if the address is valid
        node *n = malloc(sizeof(node)); // Cria um node temporário (a cada iteração) pra guardar a palavra na linked list
        if (n == NULL)                  //|| table[pos_alphab] == NULL)
        {
            printf("Not enough memory");
            return false;
        }

        //n->next = NULL;        // Inicializa o campo next do node pra NULL
        strcpy(n->word, word); // Copia a palavra escaneada pra dentro do campo "word" do node temporário

        int index_in_list = hash(word); // Usa a função hash pra pegar um valor novo pra encaixar o node dentro da lista (entre a-z)
        printf("The position at which this node would go is: %d\n", index_in_list); // Debugging statementent

        if (table[index_in_list]->is_occupied != 0) // Se o node que quer inserir já estiver ocupado..
        {
            while (table[index_in_list]->is_occupied != 0) // Loopa procurando um outro lugar desocupado
            {
                if (index_in_list == 97) 
                {
                    index_in_list = index_in_list % 97; // Se chegar no fim da lista, vai pro começo 
                }
                index_in_list++; 
                hash_offset++; // Aumenta o valor do "offset" toda vez que andar um índice
            }
        }
        table[index_in_list] = n;
        table[index_in_list]->is_occupied = 1; // Assim que preencher o node, marca como ocupado
        table[index_in_list]->offset = hash_offset; // Guarda qual é o valor do offset pra poder usar na procura depois
    }
    return true;
    //Soundtrack - (Ocean) Bloom ft. Radiohead - Blue Planet II Unreleased Soundtrack
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