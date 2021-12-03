#include <stdio.h>
#include <cs50.h>

int h = 10;
int i, j, k;

int main(void)
{
    //Name of de program
    printf("######## SUPER MARIO BROTHERS ########\n");
    printf("########  PYRAMID OF BLOCKS   ########\n");

    //Prompt for pyramid height
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

    //Loop for building the pyramid
    for (i = 1; i <= h; i++)
    {
        for (k = h; k > i; k--)
        {
            printf(" ");
        }

        for (j = 1; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}