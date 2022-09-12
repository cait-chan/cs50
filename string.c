#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string s = get_string("Input: ");
    printf("Output: ");

    //if you couldn't use %s in the printf function,
    //how else could you print out the string?

    for (int i = 0; i < strlen(s); i++)
    //the string is never changing in length, so it's repetitive
    //to keep checking the condition by comparing i to the
    //value of the strlen function after its called
    {
        printf("%c", s[i]);
    }
    printf("\n");
}