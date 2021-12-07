#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//Prototypes
int substitution_cipher(string ciphertext);
bool test_letters(string text);
bool all_alphabetics (string text);

int main(int argc, string argv[])
{
    //Delimits that the program must start with only 1 argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //Delimits that the key must be 26 characters
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    //Test if all characters are alphabetics
    else if (all_alphabetics(argv[1]))
    {
        printf("Only 26 alphabetic characters are accepted in the key\n");
        return 1;
    }
    //Test if all letter are differents
    else if (test_letters(argv[1]))
    {
        printf("The key must containing each letter exactly once\n");
        return 1;
    }
    else
    {
        substitution_cipher(argv[1]);
    }
}

bool all_alphabetics (string text)
{
    int k = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (toupper(text[i]) >= 65 && toupper(text[i]) <= 90)
        {
            k += 0;
        }
        else
        {
            k++;
        }
    }

    if (k > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int substitution_cipher(string text)
{
    printf("implement\n");
    return 0;
}

bool test_letters(string text)
{
    int k = 0;
    for (int i = 0, n = strlen(text) - 1; i < n; i++)
    {
        for (int j = i + 1, z = strlen(text); j < z; j++)
        {
            if (toupper(text[i]) == toupper(text[j]))
            {
                k++;
            }
            else
            {
                k += 0;
            }
        }
    }

    if (k == 0)
    {
        printf("%i\n", k);
        return false;
    }
    else if (k > 0)
    {
        printf("%i\n", k);
        return true;
    }
    else
    {
        printf("ERROR!\n");
        return false;
    }
}