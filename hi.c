#include <stdio.h>

int main(void)
{
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';

    printf("%i %i %i\n", (int) c1, (int) c2, (int) c3);
    // printf is printing the ASCII values of each of the letters
    // we are converting the chars to ints
}