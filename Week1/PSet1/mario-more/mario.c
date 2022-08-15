#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for a height between 1 and 8 inclusive
    int height;
    do
    {
        int height = get_int("Enter a positive integer between 1 and 8. ");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        for (int j = i + 2; j <= height; j++)
            {
                printf(".");
            }
        for (int k = 0; k <= height; k++)
        {
            printf("#");
        }
        {
            printf("\n");
        }
    }
}