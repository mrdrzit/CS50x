#include <stdio.h>
#include <cs50.h>
#include <math.h>

float change_owed(void);

int main(void)
{
    //transform the user's change owed into cents
    float dollars = change_owed();
    int cents = round(dollars * 100);

    //amount of coins
    int coins = 0;

    //US coins
    int quarters = 25;
    int dimes = 10;
    int nickels = 5;
    int pennies = 1;

    while (cents >= quarters)
    {
        cents = cents - quarters;
        coins++;
    }
    while (cents < quarters && cents >= dimes)
    {
        cents = cents - dimes;
        coins++;
    }
    while (cents < dimes && cents >= nickels)
    {
        cents = cents - nickels;
        coins++;
    }
    while (cents < nickels && cents >= pennies)
    {
        cents = cents - pennies;
        coins++;
    }

    printf("%i\n", coins);

}
//Get the user's change owed
float change_owed(void)
{
    float n;
    do
    {
        n = get_float("Change owed: ");
    }
    while (n < 0);
    return n;
}