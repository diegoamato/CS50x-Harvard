#include <stdio.h>
#include <cs50.h>

int h = 10;

int main (void)
{
    printf("######## SUPER MARIO BROTHERS ########\n");
    printf("########  PYRAMID OF BLOCKS   ########\n");

    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

    
    printf ("Height: %i", h);
}