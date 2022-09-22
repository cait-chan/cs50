#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    //string names[] = {"Carter", "David"};
    //string numbers[] = {"+1-617-495-1000", "+1-949-468-2750"};
    //difficult to use this using a large database when blind trust is relating the name to the phone number

    person people[2];

    person[0].name = "Carter"
    //the dot means go inside the variable called name and give it the value of "Carter"

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(names[i], "David") == 0)
        {
            printf("Found %s\n", numbers[i]);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}