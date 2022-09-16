#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

//want to encrypt a message by replacing every letter with another letter
//the key will be a mapping of each of the letters of the alphabet to
//the letter it should correspond to after the encryption

string substitution(string s);

int main(int argc, string argv[])
{
    string comparison = ABCDEFGHIJKLMNOPQRSTUVWXYZ';
    if (argc == 2)
        //the number of command-line arguments must be 2
        //one to run the program and the other to specify the key
    {
        if (isalpha(argv[]) = 0)
            //this specifies that the key must be alphabetical
        {
            printf("Key must only contain alphabetic characters.");
            return 1;
        }
        else if (strcasecmp(argv[1], comparison) != 0)
            //this specifies that the key not have repeated characters
            //this should be case-insensitive
        {
            printf("Key must not contain repeated characters.");
            return 1;
        }
        else if (strlen(argv[]) != 26)
            //this specifies that the key must be 26 characters
        {
            printf("Key must contain 26 characters.");
            return 1;
        }
        else
            //if the key fulfils all requirements, we can prompt the user for plaintext
        {
            string plaintext = get_string("Plaintext:  ");

            printf("ciphertext: ");
            printf("%c", substitution(plaintext));
            printf("\n");
        }
    }
    //this will print if there is no command-line argument or too many
    printf("Usage: ./substitution key");
    return 1;
}

char substitution(string plaintext, string key)
{
    //should convert the plaintext to ASCII values
    //then should can plug in the plaintext letter values into
    //the key array so that the key values will be substituted
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];
        if (isalpha(c))
        {
            if (islower(c))
            {
                return tolower(c) = key[c - 'a'];
            }
            //else is uppercase
            return toupper(c) = key[c - 'A'];
        }
        return c;
    }
}