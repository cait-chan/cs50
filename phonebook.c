//Saves names and numbers to a CSV file

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *file = fopen("phonebook.csv", "a");
    //FILE is a new data type (specific to c), and this utilizes a pointer
    //fopen is a new function which opens a file and returns a pointer there to in memory
        //this will be called phonebook.csv and will be in append mode "a" so that we can keep adding more names and numbers

    string name = get_string("Name: ");
    string number = get_string("Number: ");

    fprintf(file, "%s,%s\n", name, number);
    //fprintf prints to a file, rather than to the string
    //hence, needing to start it with the file you want to print to: "file"

    fclose(file);
}