#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int scores[3];

    for (int i = 0; i < 3; i++)
        {
            scores[i] = get_int("Score: ");
        }

    printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
}
// to get precise average without throwing away decimal points
// need to convert this into a float

// this is why we divide by "3.0" because in C, as long as one
// of the values participating in an arithetic expression is
// a float, the rest will be promoted to floats as well