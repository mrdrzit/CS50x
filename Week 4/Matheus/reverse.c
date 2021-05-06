#include <stdio.h>
#include <math.h>

int main(void)
{
    int array[4]={ 0 };
    int array_length = sizeof(array) / sizeof(array[0]);

    for (int i = 1; i <= array_length; i++)
    {
        array[i] = i;
    }

    if (array_length % 2 != 0)
    {
        int start_pointer = array[0];
        int end_pointer = array_length - 1;
        int swap_temp;

        //Actually swap the values of an array that contains an even number of elements
        for (int i = 0; i < floor(array_length/2.0); i++)
        {
            swap_temp = array[i];
            array[i] = array[end_pointer];
            array[end_pointer] = swap_temp;
            end_pointer--;
            start_pointer++;
        }
    }
    else 
    {
        int start_pointer = array[0];
        int end_pointer = array_length - 1;
        int swap_temp;

        //Actually swap the values of an array that contains an odd number of elements
        for (int i = 0; i < round(array_length/2); i++)
        {
            swap_temp = array[i];
            array[i] = array[end_pointer];
            array[end_pointer] = swap_temp;
            end_pointer--;
            start_pointer++;
        }
    }
}