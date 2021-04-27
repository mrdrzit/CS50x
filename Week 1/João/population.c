#include <cs50.h>
#include <stdio.h>

int main(void)
// TODO: Prompt for start size
{
    int initialnumber;
    int endingnumber;
    do
    {
        initialnumber = get_int("Start size: ");
    }
    while (initialnumber < 9);
// TODO: Prompt for end size
    do
    {
        endingnumber = get_int("End size: ");
    }
    while (endingnumber < initialnumber);
// TODO: Calculate number of years until we reach threshold
    int years = 0;
    while (endingnumber > initialnumber)
    {
        initialnumber = initialnumber + (initialnumber / 3) - (initialnumber / 4); 
        years++;
    }
// TODO: Print number of years
    printf("Years: %i\n", years);
}