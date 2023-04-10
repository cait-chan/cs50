#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[] = {4, 6, 8, 2, 7, 5, 0};
    //can use curly braces to define a set of values in an array

    //this is an example of linear search
    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == -1)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}