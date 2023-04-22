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
    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
}
//this will print out the addresses of the first character in the string twice,
//then each of the rest of the chars which are continguous in memory

int main(void)
{
    char *s = "HI!";
    printf("%s\n", s);
    printf("%s\n", s+1);
    printf("%s\n", s+2);
}
//this will print out the string, shifted by each byte or char
