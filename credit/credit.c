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
    for (long i = credit; i > 0; i / 10)
    // where n is the number of digits
    {
        for (int j = i % 10; j >= 0; j)
        return int j = i % 10;
        for (int j = )
    }

    //return credit % 100 * 2;
}