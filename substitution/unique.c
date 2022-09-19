#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool unique(string s);

int main(int argc, string argv[])
{
    if (unique(argv[1]) == false)
    {
        printf("False\n");
    }
    printf("True\n");
}

bool unique(string s)
{
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0, n = strlen(alphabet); i < n; i++)
    {
        for (int j = 0, o = strlen(s); j < o; j++)
        {
            if (s[j] != alphabet[i])
            {
                j++;
            }
            else
            {
                i++;
            }
        }
        return false;
    }
    return true;
}