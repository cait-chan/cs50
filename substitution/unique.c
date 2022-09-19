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
    int total = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        return key = s[i];
        return total += key;
    }

    if (atoi(alphabet) == key)
    {
        return true;
    }
    return false;
}