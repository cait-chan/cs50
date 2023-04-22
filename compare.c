#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int i = get_int("i: ");
    int j = get_int("j: ");

    if (i == j)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}
//comparison works easily with integers, but how can we do it with strings?

int main(void)
{
    string s = get_string("s: ");
    string t = get_string("t: ");

    if (s == t)
    {
        printf("Same\n");
    }
    else
    {
      printf("Different\n");
    }
}
//even if you enter the same word for both prompts, the code will denote that they are different
//because the comparison is happening between the two memory addresses of the variables, rather than the values of the string

int main(void)
{
    string s = get_string("s: ");
    string t = get_string("t: ");

    if (strcmp(s,t) == 0)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}
//this will correctly categorize same prompts as SAME, because it will go to s and t, and individually
//compare them left to right, stopping once it hits the NUL and return a value based on that comparison