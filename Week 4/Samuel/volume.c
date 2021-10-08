// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

typedef uint8_t BYTE;
typedef int16_t SAMPLES;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    BYTE header[HEADER_SIZE];
    /* fread (a pointer that stores information, size of each unit of
    information, quantity of information to store, file pointer
    where we get the information)*/
    fread(&header, sizeof(BYTE), HEADER_SIZE, input);
    /* fwrite (a pointer that stores information, size of each unit of
    information, quantity of information to write, file pointer
    where we write the information stored)*/
    fwrite(&header, sizeof(BYTE), HEADER_SIZE, output);
    // stops at 44th byte


    // TODO: Read samples from input file and write updated data to output file
    // starts at 45th byte
    SAMPLES buffer;
    /* Since we don't know the quantity of information, we'll read and write one
    SAMPLE at a time */
    while (fread(&buffer, sizeof(SAMPLES), 1, input))
    {
        /* Multiply AND assignment operator. It multiplies the right
        operand with the left operand and assigns the result to the
        left operand.*/
        // Update volume
        buffer *= factor;
        fwrite(&buffer, sizeof(SAMPLES), 1, output);
    }
    // Close files
    fclose(input);
    fclose(output);
}
