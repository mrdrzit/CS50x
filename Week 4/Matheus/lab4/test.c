#include <stdio.h>
#include <stdint.h>

int main(void)
{
    FILE *output = fopen("C:\\Users\\uzuna\\Documents\\Harvard course Computer Science\\Weeks\\Week 4\\Matheus\\test.txt","w");
    FILE *input = fopen("input","r");
    uint8_t *header[44];

    if(input == NULL)
    {
        printf("couldn't open file");
        return 1;
    }

    while(fwrite(header, sizeof(uint8_t), 1, input))
    {
        fwrite(header, sizeof(uint8_t), 1, input);
    }
    fclose(input);
    fclose(output);
}