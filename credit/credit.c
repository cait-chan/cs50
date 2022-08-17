#include <cs50.h>
#include <stdio.h>

long checksum(long credit);

int main(void)
{
    do
    {
        long credit = get_long("Credit card number: ");
    }
    while (credit < 0);
    //Checksum
    int answer = checksum(credit);
    if (answer % 10 = 0)
    {
        //AMEX
        if ((credit / 10000000000000) = 34 || 37)
        {
            printf("AMEX\n");
        }
        //MASTERCARD
        else if ((credit / 100000000000000) = 51 || 52 || 53 || 54 || 55)
        {
            printf("MASTERCARD\n");
        }
        //VISA
        else if (((credit / 1000000000000000) = 4) || ((credit / 1000000000000) = 4))
        {
            printf("VISA\n");
        }
        //INVALID
        else
        {
            printf("INVALID\n";);
        }
    }
    else
    {
        printf("INVALID\n";)
    }
}

long checksum(long credit)
{
    for (long i = (credit / 10); i >= 1; i / 100)
    // where n is the number of digits
    {
        //for (int j = i % 10; j >= 0; j)
        return int j = i % 10 * 2;
        for (int j = j; j >= 0; j / 10)
        {
            return int k = j % 10
            for (int k = k; k >= 0; k)
        }


    }
    //return credit % 100 * 2;
}