#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool real_is_digit(int x);
bool real_is_alphabetical(char x);
bool real_is_lower(char x);
bool real_is_upper(char x);

int main(int argc, string argv[])
{
    if (argc != 2) //Check if the user input has only 1 argument (2 becausa the function call "./caesar" counts in the argument count)
    {
        printf("Error: Inproper command line input!\n");
        exit(EXIT_FAILURE);
    }
    else 
    {
        // Check if the argument passed is composed of numeric values
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            char c = argv[1][i];
            bool usage = real_is_digit(c);
            if (!usage)
            {
                printf("Usage: ./caesar key\n");
                exit(EXIT_FAILURE);
            }
            else if (usage)
            {
                continue;
            }
        }
    }
    
    string text = get_string("Plaintext: ");
    int key = atoi(argv[1]);
    
    //Encrypts message using caesar's cypher
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (real_is_alphabetical(text[i]))
        {
            // ci = (pi + k) % 26
            if (real_is_lower(text[i]))
            {
                char temp_alphabetical = (text[i] - 97);
                text[i] = (temp_alphabetical + key) % 26;
                text[i] = text[i] + 97;
            }
            else if (real_is_upper(text[i]))
            {
                char temp_alphabetical = (text[i] - 65);
                text[i] = (temp_alphabetical + key) % 26;
                text[i] = text[i] + 65;
            }
            
            // char temp_current = text[i];
            // // modulo offset = 19. Meaning that 'a' % 26 = 19
            // // text[i] = (text[i] + key) % 26
            // if (real_is_lower(text[i]) && text[i] + key > 122)
            // {
            //     char temp_cyphered = (temp_uncyphered + key) % 26;
            //     text[i] = (char)temp_cyphered + temp_current;
            // }
            // // modulo offset = 13. Meaning that 'A' % 26 = 13
            // else if (real_is_upper(text[i]) && text[i] + key > 90)
            // {
            //     char temp_cyphered = (temp_uncyphered + key) % 26;
            //     text[i] = (char)temp_cyphered + temp_current;
            // }
            // else
            // {
            //     char temp_cyphered = (temp_uncyphered + key) % 26;
            //     text[i] = (char)temp_cyphered + temp_current; 
            // }
        }
    }
    printf("ciphertext: %s\n", text);
}

//Returns a boolean value in a check for digits between 0 and 9
bool real_is_digit(int x)
{
    int d = isdigit(x);
    if (d > 0)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

//Returns a boolean value in a check for alphabetical characters
bool real_is_alphabetical(char x)
{
    int d = isalpha(x);
    if (d > 0)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

//Returns a boolean value in a check for lowercase letters
bool real_is_lower(char x)
{
    int d = islower(x);
    if (d > 0)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

//Returns a boolean value in a check for uppercase letters
bool real_is_upper(char x)
{
    int d = isupper(x);
    if (d > 0)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}