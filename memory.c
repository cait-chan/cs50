#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x = malloc(3 * sizeof(int));
    //this is asking for enough memory for an array of size 3
    //must use *x rather than x because we need to store the allocated memory in an address
    x[1] = 72;
    x[2] = 73;
    x[3] = 33;
}