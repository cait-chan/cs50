#include <stdio.h>

//int main(void)
//{
    //int n = 50;
   // int *p = &n;
   // printf("%i\n", *p);
//}

//this means that the number 50 will end up in the computers memory and will be labelled "n"
//this integer will take up 4 bytes

int main(void)
{
    char *s = "HI!";
    printf("%s\n", s);
}
//this will print out "HI!", because it sends it to the address at s and prints until the nul