#include <stdio.h>

int main(void)
{
    int x;
    printf("x: ");
    //Nesse caso, como queremos mudar o valor de "x" com a função scanf, devemos passar o address e não uma cópia do valor
    //Por isso estamos usando &x ao invés de *x ou só "x"
    scanf("%i", &x); //scanf gets input from the user (like get_int()).
    printf("x: %i\n", x);
}