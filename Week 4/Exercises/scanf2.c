#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //or "char s[4];" without "free"
    char *s = malloc(4);

    printf("S: ");
    scanf("%s", s);
    printf("S: %s\n", s);
    free(s);
}