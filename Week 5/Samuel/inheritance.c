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

    // print family tree of blood types
    print_family(p, 0);

    // Free memory
    free_family(p);
}

// Create a new individual with `generations`
person *create_family(int generations)
{
    // TODO: Allocate memory for new person
    // cur_person is always a different person
    person *cur_person = malloc(sizeof(person));

    // Generation with parent data
    if (generations > 1)
    {
        // TODO: Recursively create blood type histories for parents
        /* cur_person  is a node storing two addresses, one from the father and other
        from the mother. Same thing happens to the father(parents[0]) and
        the mother(parents[1]), they're all NODES*/
        cur_person->parents[0] = create_family(generations - 1);
        cur_person->parents[1] = create_family(generations - 1);
        // TODO: Randomly assign cur_person alleles based on parents
        cur_person->alleles[0] = cur_person->parents[0]->alleles[rand() % 2];
        cur_person->alleles[1] = cur_person->parents[1]->alleles[rand() % 2];
    }

    // Generation without parent data
    else
    {
        // TODO: Set parent pointers to NULL
        // cur_person->parents[0] stores the addresses of the father's grandparents
        cur_person->parents[0] = NULL;
        // cur_person->parents[1] stores the addresses of the mother's grandparents
        cur_person->parents[1] = NULL;
        // TODO: Randomly assign alleles
        cur_person->alleles[0] = random_allele();
        cur_person->alleles[1] = random_allele();
    }

    // TODO: Return newly created person
    return cur_person;
}

// Free `p` and all ancestors of `p`.
void free_family(person *p)
{
    // TODO: Handle base case
    if (p == NULL)
    {
        return;
    }
    // TODO: Free parents
    free_family(p->parents[0]);
    free_family(p->parents[1]);
    // TODO: Free p
    free(p);
}

// print each family member and their alleles.
void print_family(person *p, int generation)
{
    // Handle base case
    if (p == NULL)
    {
        return;
    }

    // print indentation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // print person
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
