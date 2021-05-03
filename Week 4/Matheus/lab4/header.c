// Detects if a file is a JPEG

#include <errno.h>
#include <stdint.h>
#include <stdio.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    // Read first 44 bytes
    BYTE bytes[44];
    errno = 0;
    FILE *source = fopen("C:\\Users\\uzuna\\Documents\\Harvard course Computer Science\\Weeks\\Week 4\\Matheus\\lab4/\\input.wav", "r");
    FILE *output = fopen("C:\\Users\\uzuna\\Documents\\Harvard course Computer Science\\Weeks\\Week 4\\Matheus\\lab4/\\output.txt", "w");
    
    for(int i = 0; i < 44; i++)
    {
        fread(&bytes, sizeof(BYTE), 1, source);
        fwrite(&bytes,sizeof(BYTE), 1, output);
    }

    // Close file
    fclose(source);
}
