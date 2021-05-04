// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;
typedef uint8_t BYTE;
typedef int16_t SAMPLE;


int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen("C:\\Users\\uzuna\\Documents\\Harvard course Computer Science\\Weeks\\Week 4\\Matheus\\lab4/\\input.wav", "rb");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen("C:\\Users\\uzuna\\Documents\\Harvard course Computer Science\\Weeks\\Week 4\\Matheus\\lab4/\\output.wav", "wb");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    BYTE bytes[44] = {};
    SAMPLE samples[88200] = {};

    fread(&bytes, sizeof(BYTE), 44, input);
    fwrite(&bytes,sizeof(BYTE), 44, output);

    // TODO: Read samples from input file and write updated data to output file
    int idx = 0;
    int16_t buffer;
    while(idx < sizeof(samples))
    {
        fread(&buffer, sizeof(SAMPLE), 1, input);
        buffer = buffer * factor;
        fwrite(&buffer, sizeof(SAMPLE), 1, output);
        idx++;
    }

    // Close files
    fclose(input);
    fclose(output);
}