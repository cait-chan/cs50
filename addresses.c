#include <stdio.h>

int main(void)
{
    int n = 50;
    printf("%p\n", &n);
}

//this means that the number 50 will end up in the computers memory and will be labelled "n"
//this integer will take up 4 bytes