#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        printf("Usage: ./reverse input.WAV output.WAV\n");
        return 1;
    }

    // Open input file for reading
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Unable to open input WAV file\n");
        return 1;
    }

    // Read header
    // TODO #3
    WAVHEADER header[44];
    fread(&header, 1, 44, input);

    // Use check_format to ensure WAV format
    // TODO #4
    if (check_format(header) == 0)
    {
        // Open output file for writing
        // TODO #5
        FILE *output = fopen(argv[2], "w");
        if (output == NULL)
        {
            printf("Unable to open output WAV file\n");
            return 1;
        }
    }

    // Write header to file
    // TODO #6



    // Use get_block_size to calculate size of block
    // TODO #7

    // Write reversed audio to file
    // TODO #8

    fclose(input);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    if (!(header[8] == 'W' && header[9] == 'A' && header[10] == 'V' && header[11] == 'E'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return 0;
}