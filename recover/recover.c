#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
 if (argc != 2)
 {
    printf("Usage: ./recover IMAGE\n");
    return 1;
 }

FILE *file = fopen(argv[1], "r");
 if (fopen(argv[1], "r") == NULL)
 {
    printf("Cannot open file for reading.\n");
    return 1;
 }

//create buffer to read into
BYTE buffer[512];

//create array to store
char image[8] = {0};

//initialize file pointer for new image files
FILE *img = NULL;

int idx = 0;

 while (fread(buffer, 1, 512, file) == 512)
 {
   //if start of new JPEG
   if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
   {
      //if this is the first JPEG
      if (img != NULL)
      {
         fclose(img);
         idx++;
      }

      //make new JPEG file to write this data into
      sprintf(image, "%03i.jpg", idx);
      img = fopen(image, "w");
   }
   //if already found JPEG and need to continue writing into same file
   else if (img != NULL)
   {
      fwrite(buffer, sizeof(BYTE)*512, 1, img);
   }
 }
 if (img != NULL)
 {
   fclose(img);
 }
 fclose(file);

 return 0;
}