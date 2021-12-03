#include <stdio.h>
#include <cs50.h>

int y = 0;
int s = 0;
int e = 0;

int main(void)
{
    // TODO: Prompt for start size
    do
    {
        s = get_int("Start size: ");
    }
    while (s < 9);

    // TODO: Prompt for end size
    do
    {
        e = get_int("End size: ");
    }
    while (e < s);

    // TODO: Calculate number of years until we reach threshold
    if (s == e)
    {
        y = 0;
    }
    else
    {
        do
        {
            s = s + (s / 3) - (s / 4);
            y++;
        }
        while (s < e);
    }

    // TODO: Print number of years
    printf("Years: %i.\n", y);
}