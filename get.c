#include <stdio.h>


//this will mimic the idea of getting integers manually without using the cs50 library
//ie. without using get_int

int main(void)
{
    int x;
    printf("x: ");
    scanf("%i", &x);
    //this is a built in function for c which "scans" the users keyboard for input
    //we have to store it in x, but must use &
}