#include <stdio.h>
#include <string.h>
#include <ctype.h>

unsigned long hash(const char *word)
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
    return hash % 1000;
}

int main(void)
{
    printf("String: ");
    char string[100];
    scanf("%s", string);

    printf("Hash: %li\n", hash(string));
}