#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i = get_negative_int();
    printf("%i\n", i);
}

int get_negative_int()