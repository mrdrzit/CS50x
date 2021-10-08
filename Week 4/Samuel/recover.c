#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage:./recover card.raw\n");
        return 1;
    }

    FILE *card_raw = fopen(argv[1], "r");
    if (card_raw == NULL)
    {
        printf("Error\n");
        return 1;
    }

    int img_num = 0;

    char file[8];
    sprintf(file, "%03i.jpg", img_num);

    FILE *svd_photo = fopen(file, "w");
    if (svd_photo == NULL)
    {
        printf("Error\n");
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];
    // loop until the end of the file "card.raw"
    while (fread(&buffer, sizeof(BYTE), BLOCK_SIZE, card_raw))
    {
        // if found a jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8
            && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // if first jpeg
            if (img_num == 0)
            {
                fwrite(&buffer, sizeof(BYTE), BLOCK_SIZE, svd_photo);
                img_num++;
            }
            else
            {
                // close the file every time we find a new jpeg
                fclose(svd_photo);
                sprintf(file, "%03i.jpg", img_num);

                // I just reopen the same file again
                svd_photo = fopen(file, "w");
                if (svd_photo == NULL)
                {
                    printf("Error\n");
                    return 1;
                }

                fwrite(&buffer, sizeof(BYTE), BLOCK_SIZE, svd_photo);
                img_num++;
            }
        }
        // if found a jpeg
        else if (img_num > 0) /* because the first jpeg may begin  with 0s,
                            we need to check if we already found one*/
        {
            fwrite(&buffer, sizeof(BYTE), BLOCK_SIZE, svd_photo);
        }
    }
}

