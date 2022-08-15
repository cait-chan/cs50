#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Enter a positive integer between 1 and 8. ");
    }
    while (height < 1 || height > 8);
    // do while loop executes the loop within do {} until
    // the while condition is false

    for (int i = 0; i < height; i++)
    {
        for (int j = i + 2; j <= height; j++)
        {
            printf(".");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
    // loops for integers j and k are nested within the
    // loop for integer i

    // printf("Height: %i\n", height);
}