#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt user for x
    int x = get_int("x: ");

    //prompt user for y
    int y = get_int("y: ");

    // Divide x by y
    float z = x / (float) y;

    //perform addition
    //int z = x + y;
    printf("%f\n", z);
    //can place z inside the printf function, but not
    //neccessary unless you intend you reuse z variable

    //long is used for larger numbers to calculate like 4 billion
}