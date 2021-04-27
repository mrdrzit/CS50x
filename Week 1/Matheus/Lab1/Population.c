#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int years_passed = 0;
    
    // Prompt for start size
    int pop_size;
    do 
    {
        pop_size = get_int("Start size: ");
    }
    while (pop_size < 9);

    // Prompt for end size
    int pop_final;
    do 
    {
        pop_final = get_int("End size: ");
    }
    while (pop_final < pop_size);

    // Calculate number of years until we reach threshold

    while (pop_final > pop_size)
    {
        int birth = pop_size / 3;
        int death = pop_size / 4;
        pop_size = pop_size + birth - death;
        years_passed++;
    }

    // Print number of years
    printf("Years: %i", years_passed);

}