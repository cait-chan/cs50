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
            average = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen)/3.0);
            //need to divide by 3.0 so that we obtain a float which can then be rounded to an int to produce the correct value
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
            if (sepiaRed < 0)
            {
                sepiaRed = 0;
            }
            else if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            sepiaGreen = round((.349 * image[i][j].rgbtRed) + (.686 * image[i][j].rgbtGreen) + (.168 * image[i][j].rgbtBlue));
            if (sepiaGreen < 0)
            {
                sepiaGreen = 0;
            }
            else if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            sepiaBlue = round((.272 * image[i][j].rgbtRed) + (.534 * image[i][j].rgbtGreen) + (.131 * image[i][j].rgbtBlue));
            if (sepiaBlue < 0)
            {
                sepiaBlue = 0;
            }
            else if (sepiaBlue > 255)
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
            for (int j = 0; j < width / 2; j++)
            {
                tmp = image[i][j];
                image[i][j] = image[i][width - j - 1];
                image[i][width - j - 1] = tmp;
            }
        }
        else if (width % 2 != 0) //odd
        {
            for (int j = 0; j < ((width - 1) / 2); j++)
            {
                tmp = image[i][j];
                image[i][j] = image[i][width - j - 1];
                image[i][width - j - 1] = tmp;
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //need to make sure that the formula uses the original pixel colour profiles so will store the new colours in a variable to be used in a later loop
    RGBTRIPLE blur[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //need to make exceptions for first and last row and columns
            if ((i == 0) && (j == 0)) //top left corner
            {
                blur[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 4.0);
                blur[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 4.0);
                blur[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 4.0);
            }
            else if ((i == 0) && (j == (width - 1))) //top right corner
            {
                blur[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j - 1].rgbtRed) / 4.0);
                blur[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j -1 ].rgbtGreen) / 4.0);
                blur[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue) / 4.0);
            }
            else if ((i == (height - 1)) && (j == 0)) //bottom left corner
            {
                blur[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed) / 4.0);
                blur[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen) / 4.0);
                blur[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j +1 ].rgbtBlue) / 4.0);
            }
            else if ((i == (height - 1)) && (j == (width - 1))) //bottom right corner
            {
                blur[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed) / 4.0);
                blur[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen) / 4.0);
                blur[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue) / 4.0);
            }
            else if ((i == 0) && (0 < j < (width - 1))) //only first row middle
            {
                blur[i][j].rgbtRed = round((image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 6.0);
                blur[i][j].rgbtGreen = round((image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 6.0);
                blur[i][j].rgbtBlue = round((image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 6.0);
            }
            else if ((i == (height - 1)) && (0 < j < (width - 1)))//only last row middle
            {
                blur[i][j].rgbtRed = round((image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed) / 6.0);
                blur[i][j].rgbtGreen = round((image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen) / 6.0);
                blur[i][j].rgbtBlue = round((image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue) / 6.0);
            }
            else if ((0 < i < (height - 1)) && (j == 0)) //only first column middle
            {
                blur[i][j].rgbtRed = round((image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 6.0);
                blur[i][j].rgbtGreen = round((image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 6.0);
                blur[i][j].rgbtBlue = round((image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 6.0);
            }
            else if ((0 < i < (height - 1)) && (j == (width - 1))) //only last column middle
            {
                blur[i][j].rgbtRed = round((image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed) / 6.0);
                blur[i][j].rgbtGreen = round((image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen) / 6.0);
                blur[i][j].rgbtBlue = round((image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue) / 6.0);
            }
            else
            {
                blur[i][j].rgbtRed = round((image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 9.0);
                blur[i][j].rgbtGreen = round((image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 9.0);
                blur[i][j].rgbtBlue = round((image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 9.0);
            }
        }
    }

    //loop to replace the old colours with the new colours
    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            image[k][l].rgbtRed = blur[k][l].rgbtRed;
            image[k][l].rgbtGreen = blur[k][l].rgbtGreen;
            image[k][l].rgbtBlue = blur[k][l].rgbtBlue;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //need to make sure that the formula uses the original pixel colour profiles so will store the new colours in a variable to be used in a later loop
    RGBTRIPLE Gx[height][width];
    RGBTRIPLE Gy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //need to make exceptions for first and last row and columns
            if ((i == 0) && (j == 0)) //top left corner
            {
                Gx[i][j].rgbtRed = ((0 * image[i][j].rgbtRed) + (2.0 * image[i][j + 1].rgbtRed) + (0 * image[i + 1][j].rgbtRed) + (1.0 * image[i + 1][j + 1].rgbtRed));
                Gx[i][j].rgbtGreen = ((0 * image[i][j].rgbtGreen) + (2.0 * image[i][j + 1].rgbtGreen) + (0 * image[i + 1][j].rgbtGreen) + (1.0 * image[i + 1][j + 1].rgbtGreen));
                Gx[i][j].rgbtBlue = ((0 * image[i][j].rgbtBlue) + (2.0 * image[i][j + 1].rgbtBlue) + (0 * image[i + 1][j].rgbtBlue) + (1.0 * image[i + 1][j + 1].rgbtBlue));

                Gy[i][j].rgbtRed = ((0 * image[i][j].rgbtRed) + (0 * image[i][j + 1].rgbtRed) + (2.0 * image[i + 1][j].rgbtRed) + (1.0 * image[i + 1][j + 1].rgbtRed));
                Gy[i][j].rgbtGreen = ((0 * image[i][j].rgbtGreen) + (0 * image[i][j + 1].rgbtGreen) + (2.0 * image[i + 1][j].rgbtGreen) + (1.0 * image[i + 1][j + 1].rgbtGreen));
                Gy[i][j].rgbtBlue = ((0 * image[i][j].rgbtBlue) + (0 * image[i][j + 1].rgbtBlue) + (2.0 * image[i + 1][j].rgbtBlue) + (1.0 * image[i + 1][j + 1].rgbtBlue));
            }
            else if ((i == 0) && (j == (width - 1))) //top right corner
            {
                Gx[i][j].rgbtRed = ((-2.0 * image[i][j - 1].rgbtRed) + (0 * image[i][j].rgbtRed) + (-1.0 * image[i + 1][j - 1].rgbtRed) + (0 * image[i + 1][j].rgbtRed));
                Gx[i][j].rgbtGreen = ((-2.0 * image[i][j - 1].rgbtGreen) + (0 * image[i][j].rgbtGreen) + (-1.0 * image[i + 1][j - 1].rgbtGreen) + (0 * image[i + 1][j].rgbtGreen));
                Gx[i][j].rgbtBlue = ((-2.0 * image[i][j - 1].rgbtBlue) + (0 * image[i][j].rgbtBlue) + (-1.0 * image[i + 1][j - 1].rgbtBlue) + (0 * image[i + 1][j].rgbtBlue));

                Gy[i][j].rgbtRed = ((0 * image[i][j - 1].rgbtRed) + (0 * image[i][j].rgbtRed) + (1.0 * image[i + 1][j - 1].rgbtRed) + (2.0 * image[i + 1][j].rgbtRed));
                Gy[i][j].rgbtGreen = ((0 * image[i][j - 1].rgbtGreen) + (0 * image[i][j].rgbtGreen) + (1.0 * image[i + 1][j - 1].rgbtGreen) + (2.0 * image[i + 1][j].rgbtGreen));
                Gy[i][j].rgbtBlue = ((0 * image[i][j - 1].rgbtBlue) + (0 * image[i][j].rgbtBlue) + (1.0 * image[i + 1][j - 1].rgbtBlue) + (2.0 * image[i + 1][j].rgbtBlue));
            }
            else if ((i == (height - 1)) && (j == 0)) //bottom left corner
            {
                Gx[i][j].rgbtRed = ((0 * image[i - 1][j].rgbtRed) + (1.0 * image[i - 1][j + 1].rgbtRed) + (0 * image[i][j].rgbtRed) + (2.0 * image[i][j + 1].rgbtRed));
                Gx[i][j].rgbtGreen = ((0 * image[i - 1][j].rgbtGreen) + (1.0 * image[i - 1][j + 1].rgbtGreen) + (0 * image[i][j].rgbtGreen) + (2.0 * image[i][j + 1].rgbtGreen));
                Gx[i][j].rgbtBlue = ((0 * image[i - 1][j].rgbtBlue) + (1.0 * image[i - 1][j + 1].rgbtBlue) + (0 * image[i][j].rgbtBlue) + (2.0 * image[i][j + 1].rgbtBlue));

                Gy[i][j].rgbtRed = ((-2.0 * image[i - 1][j].rgbtRed) + (-1.0 * image[i - 1][j + 1].rgbtRed) + (0 * image[i][j].rgbtRed) + (0 * image[i][j + 1].rgbtRed));
                Gy[i][j].rgbtGreen = ((-2.0 * image[i - 1][j].rgbtGreen) + (-1.0 * image[i - 1][j + 1].rgbtGreen) + (0 * image[i][j].rgbtGreen) + (0 * image[i][j + 1].rgbtGreen));
                Gy[i][j].rgbtBlue = ((-2.0 * image[i - 1][j].rgbtBlue) + (-1.0 * image[i - 1][j + 1].rgbtBlue) + (0 * image[i][j].rgbtBlue) + (0 * image[i][j + 1].rgbtBlue));
            }
            else if ((i == (height - 1)) && (j == (width - 1))) //bottom right corner
            {
                Gx[i][j].rgbtRed = ((-1.0 * image[i - 1][j - 1].rgbtRed) + (0 * image[i - 1][j].rgbtRed) + (-2.0 * image[i][j - 1].rgbtRed) + (0 * image[i][j].rgbtRed));
                Gx[i][j].rgbtGreen = ((-1.0 * image[i - 1][j - 1].rgbtGreen) + (0 * image[i - 1][j].rgbtGreen) + (-2.0 * image[i][j - 1].rgbtGreen) + (0 * image[i][j].rgbtGreen));
                Gx[i][j].rgbtBlue = ((-1.0 * image[i - 1][j - 1].rgbtBlue) + (0 * image[i - 1][j].rgbtBlue) + (-2.0 * image[i][j - 1].rgbtBlue) + (0 * image[i][j].rgbtBlue));

                Gy[i][j].rgbtRed = ((-1.0 * image[i - 1][j - 1].rgbtRed) + (-2.0 * image[i - 1][j].rgbtRed) + (0 * image[i][j - 1].rgbtRed) + (0 * image[i][j].rgbtRed));
                Gy[i][j].rgbtGreen = ((-1.0 * image[i - 1][j - 1].rgbtGreen) + (-2.0 * image[i - 1][j].rgbtGreen) + (0 * image[i][j - 1].rgbtGreen) + (0 * image[i][j].rgbtGreen));
                Gy[i][j].rgbtBlue = ((-1.0 * image[i - 1][j - 1].rgbtBlue) + (-2.0 * image[i - 1][j].rgbtBlue) + (0 * image[i][j - 1].rgbtBlue) + (0 * image[i][j].rgbtBlue));
            }
            else if ((i == 0) && (0 < j < (width - 1))) //only first row middle
            {
                Gx[i][j].rgbtRed = ((-2.0 * image[i][j - 1].rgbtRed) + (0 * image[i][j].rgbtRed) + (2.0 * image[i][j + 1].rgbtRed) + (-1.0 * image[i + 1][j - 1].rgbtRed) + (0 * image[i + 1][j].rgbtRed) + (1.0 * image[i + 1][j + 1].rgbtRed));
                Gx[i][j].rgbtGreen = ((-2.0 * image[i][j - 1].rgbtGreen) + (0 * image[i][j].rgbtGreen) + (2.0 * image[i][j + 1].rgbtGreen) + (-1.0 * image[i + 1][j - 1].rgbtGreen) + (0 * image[i + 1][j].rgbtGreen) + (1.0 * image[i + 1][j + 1].rgbtGreen));
                Gx[i][j].rgbtBlue = ((-2.0 * image[i][j - 1].rgbtBlue) + (0 * image[i][j].rgbtBlue) + (2.0 * image[i][j + 1].rgbtBlue) + (-1.0 * image[i + 1][j - 1].rgbtBlue) + (0 * image[i + 1][j].rgbtBlue) + (1.0 * image[i + 1][j + 1].rgbtBlue));

                Gy[i][j].rgbtRed = ((0 * image[i][j - 1].rgbtRed) + (0 * image[i][j].rgbtRed) + (0 * image[i][j + 1].rgbtRed) + (1.0 * image[i + 1][j - 1].rgbtRed) + (2.0 * image[i + 1][j].rgbtRed) + (1.0 * image[i + 1][j + 1].rgbtRed));
                Gy[i][j].rgbtGreen = ((0 * image[i][j - 1].rgbtGreen) + (0 * image[i][j].rgbtGreen) + (0 * image[i][j + 1].rgbtGreen) + (1.0 * image[i + 1][j - 1].rgbtGreen) + (2.0 * image[i + 1][j].rgbtGreen) + (1.0 * image[i + 1][j + 1].rgbtGreen));
                Gy[i][j].rgbtBlue = ((0 * image[i][j - 1].rgbtBlue) + (0 * image[i][j].rgbtBlue) + (0 * image[i][j + 1].rgbtBlue) + (1.0 * image[i + 1][j - 1].rgbtBlue) + (2.0 * image[i + 1][j].rgbtBlue) + (1.0 * image[i + 1][j + 1].rgbtBlue));
            }
            else if ((i == (height - 1)) && (0 < j < (width - 1)))//only last row middle
            {
                Gx[i][j].rgbtRed = ((-1.0 * image[i - 1][j - 1].rgbtRed) + (0 * image[i - 1][j].rgbtRed) + (1.0 * image[i - 1][j + 1].rgbtRed) + (-2.0 * image[i][j - 1].rgbtRed) + (0 * image[i][j].rgbtRed) + (2.0 * image[i][j + 1].rgbtRed));
                Gx[i][j].rgbtGreen = ((-1.0 * image[i - 1][j - 1].rgbtGreen) + (0 * image[i - 1][j].rgbtGreen) + (1.0 * image[i - 1][j + 1].rgbtGreen) + (-2.0 * image[i][j - 1].rgbtGreen) + (0 * image[i][j].rgbtGreen) + (2.0 * image[i][j + 1].rgbtGreen));
                Gx[i][j].rgbtBlue = ((-1.0 * image[i - 1][j - 1].rgbtBlue) + (0 * image[i - 1][j].rgbtBlue) + (1.0 * image[i - 1][j + 1].rgbtBlue) + (-2.0 * image[i][j - 1].rgbtBlue) + (0 * image[i][j].rgbtBlue) + (2.0 * image[i][j + 1].rgbtBlue));

                Gy[i][j].rgbtRed = ((-1.0 * image[i - 1][j - 1].rgbtRed) + (-2.0 * image[i - 1][j].rgbtRed) + (-1.0 * image[i - 1][j + 1].rgbtRed) + (0 * image[i][j - 1].rgbtRed) + (0 * image[i][j].rgbtRed) + (0 * image[i][j + 1].rgbtRed));
                Gy[i][j].rgbtGreen = ((-1.0 * image[i - 1][j - 1].rgbtGreen) + (-2.0 * image[i - 1][j].rgbtGreen) + (-1.0 * image[i - 1][j + 1].rgbtGreen) + (0 * image[i][j - 1].rgbtGreen) + (0 * image[i][j].rgbtGreen) + (0 * image[i][j + 1].rgbtGreen));
                Gy[i][j].rgbtBlue = ((-1.0 * image[i - 1][j - 1].rgbtBlue) + (-2.0 * image[i - 1][j].rgbtBlue) + (-1.0 * image[i - 1][j + 1].rgbtBlue) + (0 * image[i][j - 1].rgbtBlue) + (0 * image[i][j].rgbtBlue) + (0 * image[i][j + 1].rgbtBlue));
            }
            else if ((0 < i < (height - 1)) && (j == 0)) //only first column middle
            {
                Gx[i][j].rgbtRed = ((0 * image[i - 1][j].rgbtRed) + (1.0 * image[i - 1][j + 1].rgbtRed) + (0 * image[i][j].rgbtRed) + (2.0 * image[i][j + 1].rgbtRed) + (0 * image[i + 1][j].rgbtRed) + (1.0 * image[i + 1][j + 1].rgbtRed));
                Gx[i][j].rgbtGreen = ((0 * image[i - 1][j].rgbtGreen) + (1.0 * image[i - 1][j + 1].rgbtGreen) + (0 * image[i][j].rgbtGreen) + (2.0 * image[i][j + 1].rgbtGreen) + (0 * image[i + 1][j].rgbtGreen) + (1.0 * image[i + 1][j + 1].rgbtGreen));
                Gx[i][j].rgbtBlue = ((0 * image[i - 1][j].rgbtBlue) + (1.0 * image[i - 1][j + 1].rgbtBlue) + (0 * image[i][j].rgbtBlue) + (2.0 * image[i][j + 1].rgbtBlue) + (0 * image[i + 1][j].rgbtBlue) + (1.0 * image[i + 1][j + 1].rgbtBlue));

                Gy[i][j].rgbtRed = ((-2.0 * image[i - 1][j].rgbtRed) + (-1.0 * image[i - 1][j + 1].rgbtRed) + (0 * image[i][j].rgbtRed) + (0 * image[i][j + 1].rgbtRed) + (2.0 * image[i + 1][j].rgbtRed) + (1.0 * image[i + 1][j + 1].rgbtRed));
                Gy[i][j].rgbtGreen = ((-2.0 * image[i - 1][j].rgbtGreen) + (-1.0 * image[i - 1][j + 1].rgbtGreen) + (0 * image[i][j].rgbtGreen) + (0 * image[i][j + 1].rgbtGreen) + (2.0 * image[i + 1][j].rgbtGreen) + (1.0 * image[i + 1][j + 1].rgbtGreen));
                Gy[i][j].rgbtBlue = ((-2.0 * image[i - 1][j].rgbtBlue) + (-1.0 * image[i - 1][j + 1].rgbtBlue) + (0 * image[i][j].rgbtBlue) + (0 * image[i][j + 1].rgbtBlue) + (2.0 * image[i + 1][j].rgbtBlue) + (1.0 * image[i + 1][j + 1].rgbtBlue));
            }
            else if ((0 < i < (height - 1)) && (j == (width - 1))) //only last column middle
            {
                Gx[i][j].rgbtRed = ((-1.0 * image[i - 1][j - 1].rgbtRed) + (0 * image[i - 1][j].rgbtRed) + (-2.0 * image[i][j - 1].rgbtRed) + (0 * image[i][j].rgbtRed) + (-1.0 * image[i + 1][j - 1].rgbtRed) + (0 * image[i + 1][j].rgbtRed));
                Gx[i][j].rgbtGreen = ((-1.0 * image[i - 1][j - 1].rgbtGreen) + (0 * image[i - 1][j].rgbtGreen) + (-2.0 * image[i][j - 1].rgbtGreen) + (0 * image[i][j].rgbtGreen) + (-1.0 * image[i + 1][j - 1].rgbtGreen) + (0 * image[i + 1][j].rgbtGreen));
                Gx[i][j].rgbtBlue = ((-1.0 * image[i - 1][j - 1].rgbtBlue) + (0 * image[i - 1][j].rgbtBlue) + (-2.0 * image[i][j - 1].rgbtBlue) + (0 * image[i][j].rgbtBlue) + (-1.0 * image[i + 1][j - 1].rgbtBlue) + (0 * image[i + 1][j].rgbtBlue));

                Gy[i][j].rgbtRed = ((-1.0 * image[i - 1][j - 1].rgbtRed) + (-2.0 * image[i - 1][j].rgbtRed) + (0 * image[i][j - 1].rgbtRed) + (0 * image[i][j].rgbtRed) + (1.0 * image[i + 1][j - 1].rgbtRed) + (2.0 * image[i + 1][j].rgbtRed));
                Gy[i][j].rgbtGreen = ((-1.0 * image[i - 1][j - 1].rgbtGreen) + (-2.0 * image[i - 1][j].rgbtGreen) + (0 * image[i][j - 1].rgbtGreen) + (0 * image[i][j].rgbtGreen) + (1.0 * image[i + 1][j - 1].rgbtGreen) + (2.0 * image[i + 1][j].rgbtGreen));
                Gy[i][j].rgbtBlue = ((-1.0 * image[i - 1][j - 1].rgbtBlue) + (-2.0 * image[i - 1][j].rgbtBlue) + (0 * image[i][j - 1].rgbtBlue) + (0 * image[i][j].rgbtBlue) + (1.0 * image[i + 1][j - 1].rgbtBlue) + (2.0 * image[i + 1][j].rgbtBlue));
            }
            else
            {
                Gx[i][j].rgbtRed = ((-1.0 * image[i - 1][j - 1].rgbtRed) + (0 * image[i - 1][j].rgbtRed) + (1.0 * image[i - 1][j + 1].rgbtRed) + (-2.0 * image[i][j - 1].rgbtRed) + (0 * image[i][j].rgbtRed) + (2.0 * image[i][j + 1].rgbtRed) + (-1.0 * image[i + 1][j - 1].rgbtRed) + (0 * image[i + 1][j].rgbtRed) + (1.0 * image[i + 1][j + 1].rgbtRed));
                Gx[i][j].rgbtGreen = ((-1.0 * image[i - 1][j - 1].rgbtGreen) + (0 * image[i - 1][j].rgbtGreen) + (1.0 * image[i - 1][j + 1].rgbtGreen) + (-2.0 * image[i][j - 1].rgbtGreen) + (0 * image[i][j].rgbtGreen) + (2.0 * image[i][j + 1].rgbtGreen) + (-1.0 * image[i + 1][j - 1].rgbtGreen) + (0 * image[i + 1][j].rgbtGreen) + (1.0 * image[i + 1][j + 1].rgbtGreen));
                Gx[i][j].rgbtBlue = ((-1.0 * image[i - 1][j - 1].rgbtBlue) + (0 * image[i - 1][j].rgbtBlue) + (1.0 * image[i - 1][j + 1].rgbtBlue) + (-2.0 * image[i][j - 1].rgbtBlue) + (0 * image[i][j].rgbtBlue) + (2.0 * image[i][j + 1].rgbtBlue) + (-1.0 * image[i + 1][j - 1].rgbtBlue) + (0 * image[i + 1][j].rgbtBlue) + (1.0 * image[i + 1][j + 1].rgbtBlue));

                Gy[i][j].rgbtRed = ((-1.0 * image[i - 1][j - 1].rgbtRed) + (-2.0 * image[i - 1][j].rgbtRed) + (-1.0 * image[i - 1][j + 1].rgbtRed) + (0 * image[i][j - 1].rgbtRed) + (0 * image[i][j].rgbtRed) + (0 * image[i][j + 1].rgbtRed) + (1.0 * image[i + 1][j - 1].rgbtRed) + (2.0 * image[i + 1][j].rgbtRed) + (1.0 * image[i + 1][j + 1].rgbtRed));
                Gy[i][j].rgbtGreen = ((-1.0 * image[i - 1][j - 1].rgbtGreen) + (-2.0 * image[i - 1][j].rgbtGreen) + (-1.0 * image[i - 1][j + 1].rgbtGreen) + (0 * image[i][j - 1].rgbtGreen) + (0 * image[i][j].rgbtGreen) + (0 * image[i][j + 1].rgbtGreen) + (1.0 * image[i + 1][j - 1].rgbtGreen) + (2.0 * image[i + 1][j].rgbtGreen) + (1.0 * image[i + 1][j + 1].rgbtGreen));
                Gy[i][j].rgbtBlue = ((-1.0 * image[i - 1][j - 1].rgbtBlue) + (-2.0 * image[i - 1][j].rgbtBlue) + (-1.0 * image[i - 1][j + 1].rgbtBlue) + (0 * image[i][j - 1].rgbtBlue) + (0 * image[i][j].rgbtBlue) + (0 * image[i][j + 1].rgbtBlue) + (1.0 * image[i + 1][j - 1].rgbtBlue) + (2.0 * image[i + 1][j].rgbtBlue) + (1.0 * image[i + 1][j + 1].rgbtBlue));
            }
        }
    }

    //loop to replace the old colours with the new colours
    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            image[k][l].rgbtRed = round(sqrt(pow(Gx[k][l].rgbtRed, 2.0) + pow(Gy[k][l].rgbtRed, 2.0)));
            if (image[k][l].rgbtRed < 0)
            {
                image[k][l].rgbtRed = 0;
            }
            else if (image[k][l].rgbtRed > 255)
            {
                image[k][l].rgbtRed = 255;
            }

            image[k][l].rgbtGreen = round(sqrt(pow(Gx[k][l].rgbtGreen, 2.0) + pow(Gy[k][l].rgbtGreen, 2.0)));
            if (image[k][l].rgbtGreen < 0)
            {
                image[k][l].rgbtGreen = 0;
            }
            else if (image[k][l].rgbtGreen > 255)
            {
                image[k][l].rgbtGreen = 255;
            }

            image[k][l].rgbtBlue = round(sqrt(pow(Gx[k][l].rgbtBlue, 2.0) + pow(Gy[k][l].rgbtBlue, 2.0)));
            if (image[k][l].rgbtBlue < 0)
            {
                image[k][l].rgbtBlue = 0;
            }
            else if (image[k][l].rgbtBlue > 255)
            {
                image[k][l].rgbtBlue = 255;
            }
        }
    }

    return;
}
