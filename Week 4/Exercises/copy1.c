#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");

    //'t' is a alias of 's'. They have same address
    char *t = s;

    t[0] = toupper(t[0]);

    printf("%s\n", s);
    printf("%s\n", t);
}