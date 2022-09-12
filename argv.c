#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("hello, %s\n", argv[1]);
    //since argv records everything the human types,
    //argv[0] will be the name of the program run
    //ie. it will print "hello, ./argv"
    //this is why we need to print argv[1] for the
    //name typed immediately after the ./argv command
    //so that it will accept "./argv NAME" and
    //print "hello, NAME"
    }
    else
    {
        printf("hello, world\n");
    }
}