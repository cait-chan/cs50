#include <stdio.h>


//this will mimic the idea of getting integers manually without using the cs50 library
//ie. without using get_int

int main(void)
{
    int x;
    printf("x: ");
    scanf("%i", &x);
        //this is a built in function for c which "scans" the users keyboard for input
        //we have to store it in x, but must use & to denote the location by reference
    printf("x: %i\n", x);
}
//this works pretty easily for integers, but how about strings?

int main(void)
{
    char *s = NULL;
        //this is so that we initialize the value
    printf("s: ");
    scanf("%s", s);
        //we don't need an & in front of s here because s is already declared as an address by using char *
        //strings are special in this way
    printf("s: %s\n", s);
}
//this does not work because we only have memory allocated for the pointer, and nothing to store the string that we request
//it is difficult to know in advance how much memory to allocate for the user input, which is why get_string exists for cs50