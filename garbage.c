#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int scores[1024];

    for (int i = 0; i < 1024; i++)
    {
        printf("%i\n", scores[i]);
    }
}
//in c, if you do not initialize a variable or an array of values, there will be garbage values there
//these are remnants of that memory being used before