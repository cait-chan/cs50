#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    string s = get_string("s: ");

    string t = s;

    if (strlen(t) > 0)
    //this will prevent crashing if the user does not give an input
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);
}
//Even though only the first letter of t is being changed to uppercase, this also affects s because
//t copies the value of the address at s, not the character

//this is because strings are just the address of the first char stored in a value

int main(void)
{
    string s = get_string("s: ");
    if (s == NULL)
    {
        return 1;
    }

    string t = malloc(strlen(s) + 1);
    //this will ask malloc for bytes that will fit the string length plus one extra for the NUL terminator
    if (t == NULL)
    {
        return 1;
    }

    for (int i = 0; i < strlen(s) + 1; i++)
    //it isn't good practice to have a function inside your condition because it gets called repeatedly as you run the for loop

    for (int i = 0, n = strlen(s) + 1; i < n; i++)
    //this is better designed, so that n is static and strlen is only called once
    //this is how you can define two variables within a for loop
    {
        t[i] = s[i];
    }
    //this copies each character in s to t individually and includes the NUL terminator

    //this for loop can be replaced by
    //strcpy(t, s);

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(t);
    //you MUST free any memory obtained from using malloc at the end of a program

    return 0;
}
//this is the better way to copy a string to another variable