#include <math.h>
#include <cs50.h>
#include <stdio.h>

int coins = 0;
float dollars = 0;
int change = 0;

int main(void)
{
    // Prompt for change
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);

    //Round the cents and x100
    change = round(dollars * 100);

    //Counting the coins
    if (change == 0)
    {
        coins = 0;
    }
    else
    {
        while (change >= 25)
        {
            change = change - 25;
            coins++;
        }
        while (change >= 10)
        {
            change = change - 10;
            coins++;
        }
        while (change >= 5)
        {
            change = change - 5;
            coins++;
        }
        while (change >= 1)
        {
            change = change - 1;
            coins++;
        }
    }

    //Print the result
    printf("%i\n", coins);
}