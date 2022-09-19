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
    int key = 0;

    for (int i = 0, n = strlen(alphabet); i < n; i += 0)
    {
        for (int j = 0, o = strlen(s); j < o; j += 0)
        {
            if (s[j] != alphabet[i])
            {
                return key += 0;
                j++;
            }
            return key += 1;
            i++;
        }
    }
    if (key == 26)
    {
        return true;
    }
    return false;
}