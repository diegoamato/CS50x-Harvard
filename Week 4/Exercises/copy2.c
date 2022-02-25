#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");

    char *t = malloc(strlen(s) + 1);

    for (int i = 0, n = strlen(s); i < n + 1; i++)
    {
        t[i] = s[i];
        /* same that
        *(t+i) = *(s+i);
        */
    }

    t[0] = toupper(t[0]);
    // *t = toupper(*t);

    printf("%s\n", s);
    printf("%s\n", t);
}