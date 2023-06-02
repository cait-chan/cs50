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
    WAVHEADER header;
    fread(header, 1, 44, input);

    // Use check_format to ensure WAV format
    // TODO #4
    check_format(header) == true;

    // Open output file for writing
    // TODO #5

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
    header[8] = 'W'
    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return 0;
}