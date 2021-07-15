#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t byte;

bool isjpg(byte *block);

int main(int argc, char *argv[])
{

    //Vê se tudo tá certo
    if (argc != 2)
    {
        printf("Usage: ./recover File(.raw)\n");
        return 1;
    }

    // Vê se tudo tá certo
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }


    FILE *jpg; // Arquivo que será o final
    byte block[512]; // BUffer temporário
    bool foundjpg = false; // Checa se já tem um jpg aberto
    int curr_jpg = 0;

    while (fread(block, sizeof(block), 1, input) == 1)
    {
        if (isjpg(block))
        {

            // Nome do arquivo que muda a cada iteração
            char filename[8];

            // Nome é um número inteiro aleatório
            sprintf(filename, "%03.3i.jpg", curr_jpg);
            
            
            if (foundjpg == true)
            {
                // Buffer ativo
                fclose(jpg);
            }
            else
            {
                // Buffer inativo
                foundjpg = true;
            }

            // Começa a escrever o arquivo final
            jpg = fopen(filename, "w");
            fwrite(block, sizeof(block), 1, jpg);

            curr_jpg++;

        }
        // Caso não achar um Header, continua
        else
        {
            // Buffer ativo
            if (foundjpg == true)
            {
                // Escreve o arquivo final
                fwrite(block, sizeof(block), 1, jpg);

            }
        }
    }

    fclose(input);
    fclose(jpg);

}

//Confere se o block atual é um header
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