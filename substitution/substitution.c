#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    //want to encrypt a message by replacing every letter with another letter
    //the key will be a mapping of each of the letters of the alphabet to
    //the letter it should correspond to after the encryption
    if (argc == 2)
        //the number of command-line arguments must be 2
        //one to run the program and the other to specify the key
    {
        if (isalpha(argv[]) = 0)
        //this specifies that the key must be 26 alphabetical unique characters
        {
            printf("Key must only contain alphabetic characters.");
            return 1;
        }
        else if ()
        {
            printf("Key must not contain repeated characters.");
            return 1;
        }
        else if (strlen(argv[]) != 26)
        {
            printf("Key must contain 26 characters.");
            return 1;
        }
        else
        {
            string plaintext = get_string("Plaintext:  ");
        }
    }
    //this will print if there is no command-line argument or too many
    printf("Usage: ./substitution key");
    return 1;
}