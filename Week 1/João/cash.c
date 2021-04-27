#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
//Prompt for change
{
    float change;
    do
    {
        change = get_float("Change: ");
    }
    while (change < 0);
//Define coins
    int cents = round(change * 100.00);
    int coins = 0;
//Count how many coins are necessary for change
    while (cents > 0)
    {
        if (cents >= 25)
        {
            cents -= 25;
            coins++;
        }
        else if (cents >= 10)
        {
            cents -= 10;
            coins++;
        }
        else if (cents >= 5)
        {
            cents -= 5;
            coins++;
        }
        else
        {
            cents -= 1;
            coins++;
        }
    }
//Sum and print how many coins are necessary for change
    printf("%i\n", coins);
}


