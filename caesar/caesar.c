#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    //want to encrypt messages using Caesar's algorithm
    if (argc == 2)
    {
        if (only_digits(argv[1]))
        //tests whether the key is numeric
        {
            int key = atoi(argv[1]);
            //need to do this because command-line arguments are enterred as strings
            //need our key to be an integer in order to do math with it later on
            string plaintext = get_string("plaintext:  ");
            printf("ciphertext: ");

            for (int i = 0, n = strlen(plaintext); i < n; i++)
            {
                printf("%c", rotate(plaintext[i], key));
            }
            printf("\n");
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

bool only_digits(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isdigit(s[i]) == 0)
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int key)
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
            return c = (((c - 'A') + key) % 26) + 'A';
        }
        return c = (((c - 'a') + key) % 26) + 'a';
    }
    return c;
    //if char c is not a letter, the function will return
    //the same char
}