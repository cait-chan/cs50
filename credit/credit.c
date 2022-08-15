#include <cs50.h>
#include <stdio.h>

long checksum(void);

int main(void)
{
    long credit = get_long("Credit card number: ");

    //Checksum
    long checksum = credit % 100 * 2

    if ()
        printf("AMEX\n");
    else if ()
        printf("MASTERCARD\n");
    else if ()
        printf("VISA\n");
    else
        printf("INVALID\n");
}

long checksum(long credit)
{
    
}