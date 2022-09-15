#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string plaintext);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    //want to encrypt messages using Caesar's algorithm
    if (argc == 2)
    {
        if (only_digits(argv[1]))
        {
            return 0;
            int letter = atoi(argv[1]);
            string plaintext = get_string("plaintext:  ");

        }
        printf("Usage: ./caesar key\n");
        return 1;
        //printf("ciphertext: ");
        //printf("\n");
       // return 0;
    }
    printf("Usage: ./caesar key\n");
    return 1;
}

bool only_digits(string plaintext)
{
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isdigit(plaintext[i]))
        {
            return true;
        }
        return false;
    }
    return false;
}

char rotate(char c, int n)
{
    if (isalpha(c))
    //if char c is a letter, the function will rotate that char
    //by int n positions and return that char
    {
        //want to cast char to an int so that its ASCII value
        //will be used. Then can subtract 'A' from uppercase or
        //'a' from lowercase so that it can be rotated properly
        //by int n, then will add it back afterwards
        if (isupper(c))
        {
            return (char) c = ((int) c - 'A') + (n % 26) + 'A';
        }
        return (char) c = ((int) c - 'a') + (n % 26) + 'a';
    }
    return c;
    //if char c is not a letter, the function will return
    //the same char
}