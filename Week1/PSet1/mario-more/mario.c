#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        int height = get_int("Enter a positive integer between 1 and 8. ");
    }
    while (height < 1 || height > 8);

    for
}