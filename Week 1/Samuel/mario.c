#include <stdio.h>
#include <cs50.h>

int get_positive_integer(void);

int main(void)
{
    int n = get_positive_integer();
    int i;
    int j;

    for (i = 1; i <= n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            printf(" ");
        }
        for (j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
//this function gives me the height of the pyramid between 1 and 8
int get_positive_integer(void)
{
    int positive_int;
    do
    {
        positive_int = get_int("Height: ");
    }
    while (positive_int < 1 || positive_int > 8);
    return positive_int;
}