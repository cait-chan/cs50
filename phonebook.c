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
    //this array called people stores persons which are composed of a name and number

    people[0].name = "Carter";
    //the dot means go inside the variable called name and give it the value of "Carter"
    people[0].number = "+1-617-495-1000";

    people[1].name = "David";
    people[1].number = "+1-949-468-2750";

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(people[i].name, "David") == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}