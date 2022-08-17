#include <cs50.h>
#include <stdio.h>

long checksum(long credit);

int main(void)
{
    long credit;
    do
    {
        credit = get_long("Credit card number: ");
    }
    while (credit <= 0);
    //Checksum
    long answer = checksum(credit);
    if (answer % 10 == 0)
    {
        //AMEX
        if (((credit / 10000000000000 % 10) == (4 | 7)) && ((credit / 100000000000000 % 10) == 3))
        {
            printf("AMEX\n");
        }
        //MASTERCARD
        else if (((credit / 100000000000000 % 10) == (1 | 2 | 3 | 4 | 5)) && ((credit / 1000000000000000 % 10) == 5))
        {
            printf("MASTERCARD\n");
        }
        //VISA
        else if ((credit / 1000000000000000 % 10 == 4) || (credit / 1000000000000 % 10 == 4))
        {
            printf("VISA\n");
        }
        //INVALID
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

long checksum(long credit)
{
    int oddsum = 0;
    int evensum = 0;
    for (long i = (credit / 10); i > 1; i = i / 100)
    // where n is the number of digits
    {
        //j is the odd digits starting second from last
        int j = (i % 10) * 2;
        int k = 0;
        if (j >= 10)
        {
            k = ((j % 10) + ((j / 10) % 10));
        }
        else
        {
            k = j;
        }
        oddsum += k;
    }
    for (long l = credit; l > 1; l = l / 100)
    {
        evensum += (l % 10);
    }
    return oddsum + evensum;
}