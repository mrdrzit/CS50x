#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    int key = 0;
    int len = 0;
    int i = 0;
//não aceitar mais de 2 inputs do usuário
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
//se houver 2 inputs, não aceitar se o segundo for número negativo ou letra
    if (argc == 2)
    {
        key = atoi(argv[1]);
        if (key < 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        for (i = 0, len = strlen(argv[1]); i < len; i++)
        {
            if (isalpha(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    }
//pegar plaintext do usuário e introduzir variáveis ciphertext como int e char (cipher)
    string plaintext = get_string("Plaintext: ");
    int ciphertext = 0;
    ciphertext = atoi(plaintext);
    char cipher;
//fazer a criptografia com a key e o plaintext dados pelo usuário
    printf("Ciphertext: ");
    for (i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (!isalpha(plaintext[i]))
        {
            ciphertext = (plaintext[i]);
            cipher = (char)ciphertext;
            printf("%c", cipher);
        }
        if (isalpha(plaintext[i]))
        {
            if (islower(plaintext[i]))
            {
                plaintext[i] -= 97;
                ciphertext = (plaintext[i] + key) % 26;
                cipher = (char)ciphertext;
                printf("%c", cipher + 97);
            }
            if (isupper(plaintext[i]))
            {
                plaintext[i] -= 65;
                ciphertext = (plaintext[i] + key) % 26;
                cipher = (char)ciphertext;
                printf("%c", cipher + 65);
            }
        }
    }
    printf("\n");
//printar o ciphertext pro usuário
}
