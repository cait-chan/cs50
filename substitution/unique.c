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
    else
    {
        printf("True\n");
    }
}

bool unique(string s)
{
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int key = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        for (int j = 1; j < n; j += 0)
        {
            if (s[i] == s[j])
            {
                return false;
            }
            j++;
        }
    }
    return true;
}