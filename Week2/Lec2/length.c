#include <cs50.h>
#include <stdio.h>

int string_length(string s);

int main(void)
{
    string name = get_string("Name: ");
    int length = string_length(name);
    printf("%i\n", length);

}

int string_length(string s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    // this while loop increases the value of i so long
    // as it does not equal '\0'
    return i;
}
// this finds the length of the string

// we don't need to do this though because there is the
// 'strlen' function within the <string.h> library that
// already finds the length of a string
