#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt user for x
    long x = get_long("x: ");

    //prompt user for y
    long y = get_long("y: ");

    //perform addition
    //int z = x + y;
    printf("%li\n", x + y);
    //can place z inside the printf function, but not
    //neccessary unless you intend you reuse z variable

    //long is used for larger numbers to calculate like 4 billion
}