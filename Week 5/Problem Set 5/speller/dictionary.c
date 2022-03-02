// Implements a dictionary's functionality
// Diego Martins 03.02.22 - Porto Alegre/RS - Brazil
/*
=====
I finished Speller Problem Set with the help of the own tutorial
in the CS50 course and complemented it with the video from th
Algorithms Illustrator Youtube Channel.
Link Video: https://www.youtube.com/watch?v=HsnjdbHMZO8
=====
*/
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// DONE: Choose number of buckets in hash table
const unsigned int N = (LENGTH + 1) *'Z';

// Hash table
int total_words = 0;
node *table[N];

// DONE: Returns true if word is in dictionary, else false
bool check(const char *word)
{
    //Hash word to obtain a hash value (hash index)
    int i_hash = hash(word);

    //Access linked list at that index in the hash table
    node *cursor = table[i_hash];

    //Traversde linked list, looking for the word
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // DONE: Improve this hash function
    int sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += toupper(word[i]);

    }
    return (sum % N);
}

// DONE: Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    //Read strings from file one at a time
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        //Create a new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n->word, word);
        n->next = NULL;

        //Hash word to obtain a hash value
        int i = hash(word);

        //Insert node into hash table at this location
        if (table[i] == NULL)
        {
            table[i] = n;
        }
        else
        {
            n->next = table[i];
            table[i] = n;
        }
        total_words++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // DONE
    return total_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // DONE: Freeing linked list
    for (int i = 0; i < N; i++)
    {
        node *head = table[i];
        node *cursor = head;
        node *tmp = head;

        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    return true;
}
