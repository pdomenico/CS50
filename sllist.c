#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

void destroy(node *head);
void print_backwards(node *head);
void print_list(node *head);
node *insert_beginning(node *head, int value);
node *insert_end(node *head, int value);
node *insert_spot(node *head, int value, int spot);
node *delete_first(node *head);
node *delete_spot(node *head, int spot);

int main(void)
{
    node *list = malloc(sizeof(node));
    if (list == NULL)
        return 1;

    // Prompt the user
    int n_nodes;
    while (1)
    {
        printf("Input the number of nodes: ");
        scanf("%i", &n_nodes);
        if (n_nodes > 0)
            break;
    }

    // Create the list asking the user for the values of each node
    node *tmp = list;
    for (int i = 0; i < n_nodes; i++)
    {
        // Prompt the user for the value
        printf("Input value for node %i: ", i + 1);
        scanf("%i", &(tmp->value));

        // If it's not the last node, create a new one and link it to the current one
        if (i != n_nodes - 1)
        {
            tmp->next = malloc(sizeof(node));
            if (tmp->next == NULL)
                return 1;

            tmp = tmp->next;
        }
    }

    printf("\nValues in the list are: \n");
    print_list(list);

    // Delete a spot
    int spot;
    printf("\nInsert position to delete: ");
    scanf("%i", &spot);
    list = delete_spot(list, spot);

    // Print out the list again
    printf("\nValues in the list are now: \n");
    print_list(list);
}

void destroy(node *head)
{
    // Base case
    if (head == NULL)
        return;

    // Recursion
    destroy(head->next);

    //Destroy
    free(head);
}

void print_list(node *head)
{
    // Base case
    if (head == NULL)
        return;

    // Print
    printf("Value: %i\n", head->value);

    // Recursion
    print_list(head->next);
}

void print_backwards(node *head)
{
    // Base case
    if (head == NULL)
        return;

    // Recursion
    print_backwards(head->next);

    // Print
    printf("Data: %i\n", head->value);
}

node *insert_beginning(node *head, int value)
{
    node *new = malloc(sizeof(node));
    if (new == NULL)
    {
        printf("Impossible to add new node!");
        return head;
    }

    new->next = head;
    new->value = value;
    return new;
}

node *insert_end(node *head, int value)
{
    node *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    node *new = malloc(sizeof(node));
    if (new == NULL)
    {
        printf("Impossible to insert new node!\n");
        return head;
    }

    tmp->next = new;
    new->value = value;
    return head;
}

node *insert_spot(node *head, int value, int spot)
{
    node *tmp = head;

    for (int i = 0; i < spot - 2; i++)
    {
        if (tmp == NULL)
        {
            printf("The list is not long enough!\n");
            return head;
        }
        tmp = tmp->next;
    }

    node *tmp2 = tmp->next;
    node *new = malloc(sizeof(node));
    if (new == NULL)
    {
        printf("Cannot insert new node!\n");
        return head;
    }

    new->next = tmp2;
    tmp->next = new;
    new->value = value;

    return head;
}

node *delete_first(node *head)
{
    node *tmp = head->next;
    free(head);
    return tmp;
}

node *delete_spot(node *head, int spot)
{
    node *tmp = head;
    if (spot == 1)
    {
        return delete_first(head);
    }

    for (int i = 0; i < spot - 2; i++)
    {
        tmp = tmp->next;
    }

    node *tmp2 = tmp->next->next;
    tmp->next = tmp2;
    free(tmp->next);
    return head;
}