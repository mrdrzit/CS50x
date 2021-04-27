#include <cs50.h>
#include <stdio.h>


void print_hashes(int n);
void print_dots(int n);
int y;


int main(void)
{
    
    //Gets a number from the user to be the size of the pyramid
    do 
    {
        y = get_int("Height: ");
    } 
    while (y < 1 || y > 8);
    
    //Actuallly creates the pyramid by printing each line from top to bottom, letf to right
    for (int i = 0; i < y; i++)
    {
        print_dots(i); //says print dots but in reality prints blank spaces
        print_hashes(i);
        printf("\n");
    }
}

//prints the spaces before each new line
void print_dots(int n)
{
    for (int i = y - 1; i > n; i--)
    {
        printf(" ");
    }
}

//prints the hashtags in each line
void print_hashes(int n)
{
    for (int i = 0; i <= n; i++)
    {
        printf("#");
    }
}