#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

//Prototypes
int count_letters(string text);
int count_words(string text);

int main(void)
{
    //Get the text with user
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);

    printf("%i letter(s)\n", letters);
    printf("%i word(s)\n", words);
}


//Count the letters of the text
int count_letters(string text)
{
    int cl = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //Set the count using only the uppercase or lowercase
        if (isupper(text[i]) || islower(text[i]))
        {
            cl++;
        }
    }
    return cl;
}

//Count the words of the text
int count_words(string text)
{
    //Every sentence has one word more than spaces
    int cw = 1;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //Sum spaces in the sentence
        if ((text[i] - ' ') == 0)
        {
            cw++;
        }
    }
    return cw;
}