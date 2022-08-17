#include <cs50.h>
#include <stdio.h>

long checksum(long credit);

int main(void)
{
    //Variables to find card digits
    long afirst = 100000000000000;
    long asecond = 10000000000000;
    long mfirst = 1000000000000000;
    long msecond = 100000000000000;
    long vfirst = 1000000000000;
    long vsecond = 1000000000000000;

    long credit;
    do
    {
        credit = get_long("Credit card number: ");
    }
    while (credit <= 0);
    //Checksum
    long answer = checksum(credit);
    if (answer % 10 == 0)
    //if the credit card number passes Luhn's Algorithm
    {
        //AMEX
        if (((credit / asecond % 10) == (4 | 7)) && ((credit / afirst % 10) == 3))
        {
            printf("AMEX\n");
        }
        //MASTERCARD
        else if ((((credit / msecond % 10) == 1) | ((credit / msecond % 10) == 2) | ((credit / msecond % 10) == 3) | ((credit / msecond % 10) == 4) | ((credit / msecond % 10) == 5)) && ((credit / mfirst % 10) == 5))
        {
            printf("MASTERCARD\n");
        }
        //VISA
        else if ((credit / vsecond % 10 == 4) || (credit / vfirst % 10 == 4))
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
    {
        //j is the odd digits starting second from last
        int j = (i % 10) * 2;
        int k = 0;
        if (j >= 10)
        {
            // this adds digits for sums > 9
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
        //l is the even digits starting from the end
        evensum += (l % 10);
    }
    //returns the sum of Luhn's Algorithm
    return oddsum + evensum;
}