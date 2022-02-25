#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

const int BLOCK = 512;

int main(int argc, char *argv[])
{
    //verfy arguments
    if (argc != 2)
    {
        printf("Usage: ./recover [image name]\n");
        return 1;
    }

    //open file and check
    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    //declarate variables
    typedef uint8_t BYTE;
    BYTE buffer[BLOCK];
    int jpeg_counter = 0;
    bool first_JPEG = false;
    bool found_JPEG = false;
    FILE *newJPEG;

    //repeat until end of card
    while (fread(buffer, sizeof(BYTE), BLOCK, file))
    {
        //read 512 bytes into a buffer
        if (buffer[0] == 0xff && buffer[1] == 0xd8 &&
            buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            found_JPEG = true;

            //verify if is the first jpeg
            if (!first_JPEG)
            {
                first_JPEG = true;
            }
            else
            {
                fclose(newJPEG);
            }

            //start write new jpeg
            char filename[8]; // xxx.jpg'\0'
            sprintf(filename, "%03i.jpg", jpeg_counter);
            newJPEG = fopen(filename, "w");
            if (newJPEG == NULL)
            {
                return 1;
            }
            fwrite(buffer, sizeof(BYTE), BLOCK, newJPEG);
            jpeg_counter++;
        }

        else
        {
            //keep writing to jpeg
            if (found_JPEG)
            {
                fwrite(buffer, sizeof(BYTE), BLOCK, newJPEG);
            }
        }
    }
    //end memory and files
    fclose(file);
    fclose(newJPEG);
    return 0;
}