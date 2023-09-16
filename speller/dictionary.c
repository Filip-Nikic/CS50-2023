// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26 * 26;

// Hash table
node *table[N];

// Dictionary size
int dict_size = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int index = hash(word);
    node *ptr = table[index];
    while (ptr != NULL)
    {
        int result = strcasecmp(ptr->word, word);
        if (!result)
        {
            return true;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int sum = 0;
    for (int j = 0; tolower(word[j]) != '\0'; j++)
    {
        sum += tolower(word[j]);
    }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            free(n);
            return false;
        }

        strcpy(n->word, word);
        n->next = NULL;
        unsigned int index = hash(n->word);
        if (table[index] == NULL)
        {
            table[index] = n;
            dict_size++;
        }
        else
        {
            n->next = table[index];
            table[index] = n;
            dict_size++;
        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dict_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        node *tmp = table[i];
        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    // TODO
    return true;
}
