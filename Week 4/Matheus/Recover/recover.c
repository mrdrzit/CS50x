#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t byte;

bool isjpg(byte *block);

int main(int argc, char *argv[])
{

    // Check command-line argument
    if (argc != 1)
    {
        printf("Usage: ./recover File(.raw)\n");
        return 1;
    }
    
    // Check if files can be opened
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Arquivo que será o final
    FILE *JPG;

    // BUffer temporário
    byte block[512];

    // bool to see if we've found any jpgs yet
    bool foundjpg = false;
    int readblock;
    int jpgnum = 0;



    while (fread(block, sizeof(block), 1, input) == 1)
    {
        if (isjpg(block))
        {

            // Nome do arquivo que muda a cada iteração
            char filename = rand() + 71;

            // Nome é um número inteiro aleatório mais 17
            sprintf(filename, "%i.jpg", jpgnum);


            if (foundjpg == true)
            {
                // Buffer ativo
                fclose(JPG);
            }
            else
            {
                // Buffer inativo
                foundjpg = true;
            }

            // Começa a escrever o arquivo final
            JPG = fopen(filename, "w");
            fwrite(block, sizeof(block), 1, JPG);


            jpgnum++;

        }
        // Caso não achar um Header, continua
        else
        {
            // Buffer ativo
            if (foundjpg == true)
            {
                // Escreve o arquivo final 
                fwrite(block, sizeof(block), 1, JPG);

            }
        }
    }

    fclose(input);
    fclose(JPG);

}

bool isjpg(byte *block)
{
    if (block[0] == 0xff && 
        block[1] == 0xd8 &&
        block[2] == 0xff &&
        (block[3] & 0xf0) == 0xe0)  
    {
        return true;
    }
    else
    {
        return false;
    }
}