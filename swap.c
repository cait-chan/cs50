#include <stdio.h>

void swap(int a, int b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(x, y);
    printf("x is %i, y is %i\n", x, y);
}

void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
//this does not correctly swap x and y because in c when you call a function and pass in two arguments (a and b),
//you're passing in those argument by value only (ie. a copy, not the actual variable)

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(&x, &y);
    //we need to add the & in here because we are entering the addresses of x and y
    printf("x is %i, y is %i\n", x, y);
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
//this now utilizes * to dereference and go to the values stored at the variables, which are the addresses since we use &
//when passing through the variables into the function in main