#include <stdio.h>
#include <math.h>

int main(void)
{
    int years_passed = 0;
    int pop_size = 100;
    int pop_final = 1000000;

    // int size_now = 0;
    while(pop_final > pop_size)
    {
    int birth = pop_size/3;
    int death = pop_size/4;
    pop_size = pop_size + birth - death;
    years_passed++;
    }

printf("%i\n",years_passed);

    // TODO: Calculate number of years until we reach threshold
    // TODO: Print number of years
}