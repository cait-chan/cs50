#include <stdio.h>

int main(void)
{
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';

    printf("%i %i %i\n", (int) c1, (int) c2, (int) c3);
    // printf is printing the ASCII values of each of the letters
    // we are converting the chars to ints

    //string s = 'HI!';
    //printf("%i %i %i %i\n", s[0], s[1], s[2], s[3])
        // this will look at the individual values within the
        // string array and convert them to ints (ASCII values)
        // this will print: 72 73 33 0 (see notes for NUL value)
}