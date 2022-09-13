#include <cs50.h>
#include <stdio.h>

//want to write a program that will quit if argc is not
//equal to 2
//we can make the program quit but having main return a value
//

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing command-line argument\n");
        return 1;
    }
    printf("hello, %s\n", argv[1]);
    //don't need to write 'else' here because it will continue
    //there if 1 isn't returned
    return 0;
}