#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average = 0;
    //initiallizing average to be zero so that we use the variable to denote the average colour value

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen)/3);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed = 0;
    int sepiaGreen = 0;
    int sepiaBlue = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaRed = round((.393 * image[i][j].rgbtRed) + (.769 * image[i][j].rgbtGreen) + (.189 * image[i][j].rgbtBlue));
            if(sepiaRed < 0)
            {
                sepiaRed = 0;
            }
            else if(sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            sepiaGreen = round((.349 * image[i][j].rgbtRed) + (.686 * image[i][j].rgbtGreen) + (.168 * image[i][j].rgbtBlue));
            if(sepiaGreen < 0)
            {
                sepiaGreen = 0;
            }
            else if(sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            sepiaBlue = round((.272 * image[i][j].rgbtRed) + (.534 * image[i][j].rgbtGreen) + (.131 * image[i][j].rgbtBlue));
            if(sepiaBlue < 0)
            {
                sepiaBlue = 0;
            }
            else if(sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp;
    //temporary variable to store the first half of the reflection before swapping

    for (int i = 0; i < height; i++)
    {
        if (width % 2 == 0) //even
        {
            for (int j = 0; j < width/2; j++)
            {
                tmp = image[i][j];
                image[i][j] = image[i][width - j];
                image[i][width - j] = tmp;
            }
        }
        else if (width % 2 == 1) //odd
        {
            for (int j = 0; j < (width/2 - 1); j++)
            {
                tmp = image[i][j];
                image[i][j] = image[i][width - j];
                image[i][width - j] = tmp;
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int blur = round()
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

        }
    }
    return;
}
