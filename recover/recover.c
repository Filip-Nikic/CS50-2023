#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    typedef uint8_t BYTE;
    // Check for invalid usage
    if (argc != 2)
    {
        printf("Please input one argument\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    int block_size = 512;
    BYTE buffer[block_size];
    int count = 0;
    char *images_name;

    FILE *img = NULL;

    if (file != NULL)
    {
        while (fread(buffer, block_size, 1, file))
        {
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))
            {
                if (img != NULL)
                {
                    fclose(img);
                }
                images_name = malloc(9);
                sprintf(images_name, "%03i.jpg", count);
                img = fopen(images_name, "w");
                fwrite(buffer, block_size, 1, img);
                count++;
                free(images_name);
            }
            else if (count > 0)
            {
                fwrite(buffer, block_size, 1, img);
            }
        }
        fclose(file);
        fclose(img);
    }
    else
        return 1;

    return 0;
}
