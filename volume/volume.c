// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

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

    //create header to read into
    uint8_t header[44];

    // TODO: Copy header from input file to output file
    while (fread(header, HEADER_SIZE, 1, input))
    {
        fwrite(header, HEADER_SIZE, 1, output);
    }

    //create buffer to store audio samples
    int16_t buffer;

    // TODO: Read samples from input file and write updated data to output file
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
            //multiply sample by factor to change volume
            int16_t newsample = buffer * factor;
            fwrite(&newsample, sizeof(int16_t), 1, output);
    }

    //free memory
    //free(header);

    // Close files
    fclose(input);
    fclose(output);
}
