#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
 if (argc != 2)
 {
    printf("Usage: ./recover IMAGE\n");
    return 1;
 }

 if (fopen(argv[1], "r") == NULL)
 {
    printf("Cannot open file for reading.\n");
    return 1;
 }

//create buffer to read into
int buffer[512];

//create array to store
char *image[8];

//create array of new JPEG files
FILE *img[50];

int idx = 0;

FILE *file = fopen(argv[1], "r");

 while (fread(buffer, 1, 512, file) == 512)
 {
   //if start of new JPEG
   if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
   {
      //if this is the first JPEG
      if (idx == 0)
      {
         //make new JPEG file to write this data into
         sprintf(image[idx], "%03i.jpg", idx);
         img[idx] = fopen(image[idx], "w");
         fwrite(&buffer, 1, 512, img[idx]);
      }
      //need to close current file and open another file to write into
      else
      {
         fclose(img[idx]);
         idx++;

         sprintf(image[idx], "%03i.jpg", idx);
         img[idx] = fopen(image[idx], "w");
         fwrite(&buffer, 1, 512, img[idx]);
      }
   }
   //if already found JPEG and need to continue writing into same file
   else
   {
      if ()
   }
 }
 for (int i = 0; i < 50; i++)
 {
   fclose(img[i]);
 }
 fclose(file);
}