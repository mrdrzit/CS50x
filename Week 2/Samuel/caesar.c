#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

// int argument count, string argument vector[]
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key");
        // exit program = went wrong
        return 1;
    }

    int key = 0;

    if (argc == 2)
    {
        // now the variable "key" is storing argv[1] as an integer.
        key = atoi(argv[1]);

        // gets the size of argv[1] string.
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isalpha(argv[1][i]) || key < 0)
            {
                printf("Usage: ./caesar key\n");

                // exit program = went wrong
                return 1;
            }
        }

        string plaintext = get_string("plaintext: ");

        printf("ciphertext: ");

        // gets the size of plaintext string.
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            int ciphertext[i];

            if (isupper(plaintext[i]))
            {
                /* ex: the first letters of the plaintext is 'B', B = 66 and A = 65
                according to the ascii chart, and let's suppose the user types 2 as
                the value of the key, ciphertext[i] = ((66 - 65) + 2) % 26. Now we
                know the value of ciphertext[0] is the integer 3, we just need to
                convert it to a string. */
                ciphertext[i] = ((plaintext[i] - 'A') + key) % 26;

                // 3 + 'A' = 68 and 68 = 'D', according to the ascii chart.
                printf("%c", ciphertext[i] + 'A');
            }

            else if (islower(plaintext[i]))
            {
                /* ex: the first letters of the plaintext is 'b', b = 98 and a = 97
                according to the ascii chart, and let's suppose the user types 2 as
                the value of the key, ciphertext[i] = ((98 - 97) + 2) % 26. Now we
                know the value of ciphertext[0] is the integer 3, we just need to
                convert it to a string. */
                ciphertext[i] = ((plaintext[i] - 'a') + key) % 26;

                // 3 + 'a' = 100 and 100 = 'd', according to the ascii chart.
                printf("%c", ciphertext[i] + 'a');
            }

            else if (!isalpha(plaintext[i]) || isspace(plaintext[i]))
            {
                /* if there is a space or a comma in plaintext it will have in
                ciphertext as though */
                ciphertext[i] = (plaintext[i]);
                printf("%c", ciphertext[i]);
            }
        }
        printf("\n");
    }
    // exit program = nothing went wrong
    return 0;
}