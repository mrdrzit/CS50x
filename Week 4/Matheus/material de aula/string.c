#include <stdio.h>

int main(void)
{
    char *s[6]; //intialization of the string
    printf("s: ");
    scanf("%s", (char *)s); //scanf gets input from the user (like get_int()).
    printf("x: %s\n", (char *)s);
}