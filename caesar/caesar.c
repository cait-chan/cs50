#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string plaintext);

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