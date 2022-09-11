#include <stdio.h>

int main(void)
{
    int scores[3];

    scores[0] = 72;
    scores[1] = 73;
    scores[2] = 33;

    printf("Average: %f\n", (score1 + score2 + score3) / 3.0);
}
// to get precise average without throwing away decimal points
// need to convert this into a float

// this is why we divide by "3.0" because in C, as long as one
// of the values participating in an arithetic expression is
// a float, the rest will be promoted to floats as well