#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    int height = get_int("Height: ");

    draw(height);
}

void draw(int n)
{
    if (n <= 0)
    {
        return;
        //just saying return suffices because this function doesn't return a value
    }
    //this if statement is the base case which ensures that the function doesn't continue forever

    draw(n - 1);
    //this recursion calls these functions within itself first before continuing to the for loop

    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}