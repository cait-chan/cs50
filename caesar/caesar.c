#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool only_digits(string plaintext);

int main(int argc, string argv[])
{
    //want to encrypt messages using Caesar's algorithm
    if (argc == 2)
    {
        string plaintext = get_string("plaintext:  ");
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {

        }
        printf("ciphertext: ");
        printf("\n");
        return 0;
    }
    printf("Usage: ./caesar key\n");
    return 1;
}

bool only_digits(string plaintext)
{
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if

            return true

        return false
    }

}