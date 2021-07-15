// Simulate genetic inheritance of blood type

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Each person has two parents and two alleles
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
}
person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    // Seed random number generator
    srand(time(0));

    // Create a new family with three generations
    person *p = create_family(GENERATIONS);

    // Print family tree of blood types
    print_family(p, 0);

    // Free memory
    free_family(p);
}

// Create a new individual with `generations`
person *create_family(int generations)
{
    // TODO: Allocate memory for new person
    person *tmp_family = malloc(sizeof(person));

    //Check if the pointer is NULL
    if (tmp_family == NULL)
    {
        return 1;
    }
    
    // Generation with parent data
    if (generations > 1)
    {
        // TODO: #2 Recursively create blood type histories for parents
        int current_gen = generations - 1;
        tmp_family->parents[0] = create_family(current_gen);
        tmp_family->parents[1] = create_family(current_gen);

        // TODO: #3 Randomly assign child alleles based on parents
        tmp_family->alleles[0] = tmp_family->parents[0]->alleles[rand() % 2];
        tmp_family->alleles[1] = tmp_family->parents[1]->alleles[rand() % 2];
    }

    // Generation without parent data
    else
    {
        // TODO: #4 Set parent pointers to NULL
        tmp_family->parents[0] = NULL;
        tmp_family->parents[1] = NULL;

        // TODO: #5 Randomly assign alleles


    }

    // Return newly created person
    return tmp_family;
}

// Free `p` and all ancestors of `p`.
void free_family(person *p)
{
    // TODO: #6 Handle base case

    // TODO: #7 Free parents

    // TODO: #8 Free child
}

// Print each family member and their alleles.
void print_family(person *p, int generation)
{
    // Handle base case
    if (p == NULL)
    {
        return;
    }

    // Print indentation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print person
    printf("Generation %i, blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Randomly chooses a blood type allele.
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}
