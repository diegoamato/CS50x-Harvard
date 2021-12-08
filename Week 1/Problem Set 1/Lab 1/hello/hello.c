#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Prompt user for name
    string n = get_string("Whats's your name? ");
    
    //Say hello to user
    printf("Hello, %s!\n", n);
}