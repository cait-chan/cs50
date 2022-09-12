#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string s = get_string("Input: ");
    printf("Output: ");
    int length = strlen(s);

    //if you couldn't use %s in the printf function,
    //how else could you print out the string?

    for (int i = 0; i < length; i++)
    //the string is never changing in length, so it's repetitive
    //to keep checking the condition by comparing i to the
    //value of the strlen function after its called
        //it's optimal to store the strlen(s) in the variable length
        //and then check the condition against length
    {
        printf("%c", s[i]);
    }
    printf("\n");
}