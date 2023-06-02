#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
 if (argc != 2)
 {
    printf("Please enter only one command-line argument.\n");
    return 1;
 }

 if (!fopen(argv[1]))
 {
    printf("Cannot open file for reading.\n");
    return 1;
 }

//create buffer to read into
char buffer[512];

//create array to store 

FILE *file = fopen(argv[1], "r");

 while (fread(buffer, 1, 512, file) == 512)
 {

 }
}