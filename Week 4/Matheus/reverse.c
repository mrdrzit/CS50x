#include <stdio.h>
#include <math.h>

int main(void)
{
    int even[10]={ [0 ... 9 ] = 0 };
    int odd[11]={ [0 ... 10 ] = 0 };

    int even_length = sizeof(even) / sizeof(even[0]);
    int odd_length = sizeof(odd) / sizeof(odd[0]);
    for (int i = 1; i <= even_length; i++)
    {
        even[i] = i;
    }
    for (int i = 1; i <= odd_length; i++)
    {
        odd[i] = i;
    }

    int start_pointer = odd[0];
    int end_pointer = odd_length;
    int swap_temp;


    for (int i = 0; i < round(odd_length/2.0); i++)
    {
        swap_temp = odd[i];
        odd[i] = odd[end_pointer];
        odd[end_pointer] = swap_temp;
        end_pointer--;
        start_pointer++;
    }

    int start_pointer = even[0];
    int end_pointer = even_length;
    int swap_temp;


    for (int i = 0; i < round(even_length/2); i++)
    {
        swap_temp = even[i];
        even[i] = even[end_pointer];
        even[end_pointer] = swap_temp;
        end_pointer--;
        start_pointer++;
    }

}