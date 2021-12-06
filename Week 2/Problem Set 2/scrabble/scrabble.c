#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int LETTERS[] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!");
    }
    else
    {
        //For the same scores
        printf("Tie!");
    }
    printf("\n");
}

int compute_score(string word)
{
    //Sum of word scores
    int sum = 0;

    // Compute and return score for string
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
    return sum;
}