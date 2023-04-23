#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x = malloc(3 * sizeof(int));
    //this is asking for enough memory for an array of size 3
    x[1] = 72;
    x[2] = 73;
    x[3] = 33;
}