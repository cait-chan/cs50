#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("Name: ");

    int i = 0;
    while (name[i] != '\0')
    {
        i++;
    }
    // this while loop increases the value of i so long
    // as it does not equal '\0'
    printf("%i\n", i);

}
// this finds the length of the string
