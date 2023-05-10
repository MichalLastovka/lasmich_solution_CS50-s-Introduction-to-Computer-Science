/*/
Task:

https://cs50.harvard.edu/college/2022/fall/psets/4/
/*/

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

// Defining some helpful constatnts, formats and global variables
typedef uint8_t BYTE;
int CHUNK_SIZE = 512;
int JPEG_found = 0;
int JPEG_counter = 0;
char name_buffer[8];
BYTE file_buffer[512];

// Introducing two void functions, to deal with data
void make_new(void);
void continue_previous(void);

int main(int argc, char *argv[])
{
    // Restricting user input on command line
    if (argc != 2)
    {
        printf("Usage: ./recover <filename>");
        return 1;
    }

    // Openning fiven file from command line
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        printf("Cannot open the file");
        return 1;
    }

    // Main loop loops until reaches the end
    while (fread(file_buffer, 1, CHUNK_SIZE, file) == CHUNK_SIZE)
    {
        // Differentiating behavior of 1st JPEG from the rest of data chunks
        if (JPEG_found < 1)
        {
            if (file_buffer[0] == 0xff &&
                file_buffer[1] == 0xd8 &&
                file_buffer[2] == 0xff &&
                (file_buffer[3] & 0xf0) == 0xe0)
            {
                sprintf(name_buffer, "%03i.jpg", JPEG_counter);
                FILE *img = fopen(name_buffer, "w");
                fwrite(file_buffer, CHUNK_SIZE, 1, img);
                fclose(img);
                JPEG_found++;
            }

            else
            {
                continue;
            }
        }

        // Depending on the header, loop calls function make_new or continue_previous
        else
        {
            if (file_buffer[0] == 0xff &&
                file_buffer[1] == 0xd8 &&
                file_buffer[2] == 0xff &&
                (file_buffer[3] & 0xf0) == 0xe0)
            {
                make_new();
            }

            else
            {
                continue_previous();
            }
        }

    }
    fclose(file);
    printf("%d\n", JPEG_counter);
}

// Void function oppening files and writing first chunk of 512B data
void make_new(void)
{
    JPEG_counter++;
    sprintf(name_buffer, "%03i.jpg", JPEG_counter);
    FILE *img = fopen(name_buffer, "w");
    fwrite(file_buffer, CHUNK_SIZE, 1, img);
    fclose(img);
}

// Void function appending the rest of the chunks belonging to appropriate JPEG file
void continue_previous(void)
{
    FILE *img = fopen(name_buffer, "a");
    fwrite(file_buffer, CHUNK_SIZE, 1, img);
    fclose(img);
}
