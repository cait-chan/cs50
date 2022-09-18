#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

//want to encrypt a message by replacing every letter with another letter
//the key will be a mapping of each of the letters of the alphabet to
//the letter it should correspond to after the encryption

bool alphabetical(string s);
bool unique(string s);
char substitution(string plaintext, string key);

int main(int argc, string argv[])
{
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (argc == 2)
        //the number of command-line arguments must be 2
        //one to run the program and the other to specify the key
    {
        if (alphabetical(argv[1]) == false)
            //this specifies that the key must be alphabetical
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
        else if (unique(argv[1]) == false)
            //this specifies that the key not have repeated characters
            //this should be case-insensitive
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
        else if (strlen(argv[1]) != 26)
            //this specifies that the key must be 26 characters
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else
            //if the key fulfils all requirements, we can prompt the user for plaintext
        {
            string plaintext = get_string("plaintext:  ");

            printf("ciphertext: ");

            for (int i = 0, n = strlen(plaintext); i < n; i++)
            {
                printf("%c", substitution(plaintext, argv[1]));
            }
            printf("\n");
        }
    }
    //this will print if there is no command-line argument or too many
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

bool alphabetical(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]) == 0)
        {
            return false;
        }
    }
    return true;
}

bool unique(string s)
{
    int alphatotal = 0;
    int value = 0;

    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0, n = strlen(alphabet); i < n; i++)
    {
        return alphatotal += (int) alphabet[i];
    }

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        return value += s[i];
    }

    if (alphatotal == value)
    {
        return true;
    }
    return false;
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
                return c = tolower(key[c - 'a']);
            }
            //else is uppercase
            return c = toupper(key[c - 'A']);
        }
        return c;
    }
    return 1;
}