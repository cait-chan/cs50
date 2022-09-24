#include <cs50.h>
#include <stdio.h>

//want to redo the mario problem from week 1 using recursion

void draw(int n);

int main(void)
{
    int height = get_int("Height: ");

    draw(height);
}

void draw(int n)
//since we only need the side effect of printing something, rather than returning a value,
//we can put void before the function name
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}