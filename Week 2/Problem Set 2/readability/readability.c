#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Prototypes
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //Get the text with user
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    //Coleman-Liau index calculate
    float L = (100 * (float) letters) / (float) words;
    float S = (100 * (float) sentences) / (float) words;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    //Print the result
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

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

//Count the sentences of the text
int count_sentences(string text)
{
    int cs = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //Sum <. ! ?> in the text
        if ((text[i] - '.') == 0 || (text[i] - '?') == 0 || (text[i] - '!') == 0)
        {
            cs++;
        }
    }
    return cs;
}