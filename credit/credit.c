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
        if ((credit / 10000000000000) == (34 | 37))
        {
            printf("AMEX\n");
        }
        //MASTERCARD
        else if ((credit / 100000000000000) == (51 | 52 | 53 | 54 | 55))
        {
            printf("MASTERCARD\n");
        }
        //VISA
        else if (((credit / 1000000000000000) == 4) || ((credit / 1000000000000) == 4))
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
    for (long i = (credit / 10); i >= 1; i / 100)
    // where n is the number of digits
    {
        //j is the odd digits starting second from last
        int j = (i % 10) * 2;
        int k;
        if (j > 9)
        {
            k = ((j % 10) + ((j / 10) % 10));
            oddsum = k + oddsum;
        }
        else
        {
            return k;
            oddsum = k + oddsum;
        }
    }
    for (long l = credit; l >= 1; l / 100)
    {
        int m = l % 10;
            return m;
        evensum = m + evensum;
    }
    return oddsum + evensum;
}
       // for (int j = j; j >= 0; j)
       //     return int k = j % 10
       //     for (int k = k; k >= 0; k)
    //return credit % 100 * 2;