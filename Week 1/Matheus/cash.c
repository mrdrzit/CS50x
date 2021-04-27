#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{

    //Gets a number from the user to be the change owned 
    float rem;
    do
    {
        rem = get_float("Change owed: ");
    }
    while (rem < 0);

    int number_of_coins = 0; //initialize the number of coins to be delivered
    int change = round(rem * 100); //Converts from float to int

    //Loop that cycles through the available coins until there is no change left
    while (change > 0)
    {
        if (change >= 25)
        {
            change = change - 25;
            number_of_coins = number_of_coins + 1;
            continue;
    
        }
        
        else if (change >= 10)
        {
            change = change - 10;
            number_of_coins++;
            continue;
    
        }
            
        else if (change >= 5)
            
        {
            change = change - 5;
            number_of_coins++;
            continue;
    
        }
            
        else if (change > 0)
        {
            change = change - 1;
            number_of_coins++;
            continue;
            
        }
    }
    printf("%i\n", number_of_coins); //Prints the number of coins that's going to be delivered to the user
}