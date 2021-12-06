#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int LETTERS[] = {97, 98, 99, 100 , 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};
int sum = 0;

int main(void)
{
    string word = get_string("digite uma palavra: ");
    printf ("Pontuação: ");
    
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (islower(word[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if (word[i] == LETTERS[j])
                {
                    sum = sum + POINTS[j];
                }
            }
        }
        else if (isupper(word[i]))
        {
            word[i] = tolower(word[i]);
            
            for (int j = 0; j < 26; j++)
            {
                if (word[i] == LETTERS[j])
                {
                    sum = sum + POINTS[j];
                }
            }
        }
        else
        {
            sum = sum + 0;
        }
    }
    
    printf ("%i\n", sum);
    
}