#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What is your name?\n"); //Asks for username
    printf("hello, %s\n", name); //Prints Hello, "username".
}