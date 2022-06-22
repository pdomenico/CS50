// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table
const unsigned int N = 100000;

// Hash table
node *table[N];

// Words in the dictionary
int count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Get the head of the ll
    node *head = table[hash(word)];

    // Check through the linked list
    for (node *i = head; i != NULL; i = i->next)
    {
        if (strcasecmp(word, i->word) == 0)
            return true;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *word++))
    {
        if (isupper(c))
        {
            c = tolower(c);
        }
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *f = fopen(dictionary, "r");
    if (f == NULL)
    {
        printf("Could not open dictionary file!");
        return false;
    }

    // Iterate through every word
    char word[LENGTH];
    while (fscanf(f, "%s", word) != EOF)
    {
        count++;
        // Create new node and insert the word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Ran out of memory!");
            return false;
        }
        strcpy(n->word, word);
        n->next = NULL;

        // Get the head of the ll
        node *head = table[hash(word)];

        // Create new list if there isn't already one
        if (head == NULL)
        {
            table[hash(word)] = n;
        }

        // Add the node to the list if there's already one
        else
        {
            n->next = head;
            table[hash(word)] = n;
        }
    }

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Free function
void free_list(node *head)
{
    // Base case
    if (head == NULL)
        return;

    // Recursive case
    free_list(head->next);

    // Free this node
    free(head);
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Iterate trough the hashtable array
    for (int i = 0; i < N; i++)
    {
        free_list(table[i]);
    }

    return true;
}
