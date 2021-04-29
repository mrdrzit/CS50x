#include <cs50.h> //string library
#include <stdio.h> //standart input and output library

int main(void)
{

    string answer = get_string("What's your name?\n"); //get the person's name
    printf("hello, %s\n", answer); //say hello to the person;

}