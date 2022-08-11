#include <cs50.h>
#include <stdio.h>

//parity just means even or odd

int main(void)
{
    int n = get_int("n: ");

    //If n is even
    if (n % 2 == 0)
    //n divided by 2 and remainder equals 0, print even
    {
        printf("even\n");
    }
    //Else
    else
    {
        printf("odd\n");
    }
}