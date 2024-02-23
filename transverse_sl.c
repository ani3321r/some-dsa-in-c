#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Function to insert a node at the end of the linked list
void append(struct Node **head_ref, int new_data)
{
    // Allocate memory for new node
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;

    // Assign data to new node
    new_node->data = new_data;

    // This new node is going to be the last node, so make next of it as NULL
    new_node->next = NULL;

    // If the linked list is empty, then make the new node as head
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    // Else traverse till the last node
    while (last->next != NULL)
        last = last->next;

    // Change the next of last node
    last->next = new_node;
    return;
}

// Function to traverse and print the linked list
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}

// Main program
int main()
{
    // Initialize an empty linked list
    struct Node *head = NULL;

    // Append some elements
    append(&head, 6);
    append(&head, 2);
    append(&head, 8);
    append(&head, 4);
    append(&head, 1);

    // Print the linked list
    printf("Linked list elements: ");
    printList(head);
    printf("\n");

    return 0;
}
