#include <cs50.h>
#include <stdio.h>

//Prototype
int get_negative_int(void);

int main(void)
{
    //Get negative integer from user
    int i = get_negative_int();
    printf("%i\n", i);
}

int get_negative_int(void)
{
    int n;
    do
    {
        n = get_int("Negative Integer: ");
    }
    //The logic is wrong, it needs to be >=
    while (n < 0);
    return n;
}