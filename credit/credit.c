#include <cs50.h>
#include <stdio.h>

long checksum(long credit);

int main(void)
{
    long credit = get_long("Credit card number: ");

    //Checksum
    int answer = checksum(credit);
    printf("Checksum: %i\n", answer);
}

long checksum(long credit)
{
    for (int i = credit; i > 0; i / 10)
    // where n is the number of digits
    {
       return i % 10;
    }

    //return credit % 100 * 2;
}