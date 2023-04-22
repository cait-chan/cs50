#include <cs50.h>
#include <stdio.h>

//int main(void)
//{
    //int i = get_int("i: ");
    //int j = get_int("j: ");

    //if (i == j)
    //{
        //printf("Same\n");
    //}
    //else
    //{
        //printf("Different\n");
    //}
//}
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
//because the comparison is happening between the two memory addresses, rather than the values
