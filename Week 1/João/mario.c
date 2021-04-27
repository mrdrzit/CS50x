#include <cs50.h>
#include <stdio.h>

int main(void)
//Prompt for height
{
    int heightuser;
    do
    {
        heightuser = get_int("Height: ");
    }
    while (heightuser < 1 || heightuser > 8);
//Construct the pyramid, given it's height and width in a given iteration, and the height just given by the user
    int heightprogram;
    int widthprogram;
    for (heightprogram = 0; heightprogram < heightuser; heightprogram++)
    {
        for (widthprogram = 0; widthprogram < heightuser; widthprogram++)
        {
            if (widthprogram + heightprogram >= heightuser - 1)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}