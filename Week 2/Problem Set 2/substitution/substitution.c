#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//Prototypes
bool all_alphabetics(string text);
bool test_letters(string text);
string substitution_cipher(string plaintext, string key);
//###############################################

//Implements main program
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
    //Tests if all characters are alphabetics
    else if (all_alphabetics(argv[1]))
    {
        printf("Only alphabetic characters are accepted in the key\n");
        return 1;
    }
    //Tests if all letters are differents
    else if (test_letters(argv[1]))
    {
        printf("Key must containing each letter exactly once\n");
        return 1;
    }

    //Get key and plaintext with user
    else
    {
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        printf("%s\n", substitution_cipher(plaintext, argv[1]));
        return 0;
    }
}
//###############################################

//Implements the test to verify if all characters are letters
bool all_alphabetics(string text)
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
//###############################################

//Implements the test to verify if all letters are differents
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
        return false;
    }
    else if (k > 0)
    {
        return true;
    }
    else
    {
        return true;
    }
}
//###############################################

//Implements the substitution
string substitution_cipher(string plaintext, string key)
{
    int letters[] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};
    string ciphertext = plaintext;

    for (int i = 0, n = strlen(key); i < n; i++)
    {
        key[i] = toupper(key[i]);
    }

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (islower(plaintext[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if ((int) plaintext[i] == letters[j])
                {
                    ciphertext[i] = key[j];
                }
            }
            ciphertext[i] = tolower(ciphertext[i]);
        }
        else if (isupper(plaintext[i]))
        {
            plaintext[i] = tolower(plaintext[i]);

            for (int j = 0; j < 26; j++)
            {
                if ((int) plaintext[i] == letters[j])
                {
                    ciphertext[i] = key[j];
                }
            }
        }
    }
    return ciphertext;
}
//###############################################