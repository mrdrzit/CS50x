#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b);


int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(&x, &y);//I'm passing the addresses of the variables to the functions.
    //Perceive that the function declaration is declaring poniters...
    //which is correct because pointers are just variables that takes an address to a certain location and this location holds a value.
    printf("x is %i, y is %i\n", x, y);
}

void swap(int *a, int *b) 
{
    int tmp = *a; //Here i'm saying, go to the location pointed at by "a" and copy that value into tmp.
    *a = *b; //Go to te location pointed at by "b" and copy it into the location pointed at by "a".
    *b = tmp; //Copy the value of tmp into the location pointed at by "b".

    //All of this is just changing the values assined to the function in main because we're using the addresses instead of a copy of thoses values.
}
