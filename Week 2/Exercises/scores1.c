#include <stdio.h>
#include <cs50.h>

//Constant
const int TOTAL = 3;

//Prototype
float average (int lenght, int array[]);

int main(void)
{
    int scores[TOTAL];

    for (int i = 0; i < TOTAL; i++)
    {
        scores[i] = get_int("Score:");
    }

    printf ("Average: %f\n", average(TOTAL, scores));
}

float average (int lenght, int array[])
{
    int sum = 0;

    for (int i = 0; i < lenght; i++)
    {
        sum += array[i];
    }
    return sum / lenght;
}