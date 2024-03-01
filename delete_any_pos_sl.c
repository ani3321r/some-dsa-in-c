#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node
{
    int data;
    struct Node *next;
};

// Function to delete a node with a given key value
void deleteNode(struct Node **head_ref, int key)
{
    // Store head node
    struct Node *temp = *head_ref, *prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; // Changed head
        free(temp);             // free old head
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL)
        return;

    // Unlink the node from linked list
    prev->next = temp->next;

    // Free memory
    free(temp);
}

// Function to insert a new node at the beginning
void push(struct Node **head_ref, int new_data)
{
    // Allocate memory for new node
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    // Put data into the new node
    new_node->data = new_data;

    // Make next of new node as head
    new_node->next = (*head_ref);

    // Move the head to point to the new node
    (*head_ref) = new_node;
}

// Function to print the linked list
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main()
{
    // Start with the empty list
    struct Node *head = NULL;

    // Insert 6, 7, 8, 9 at the beginning
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);

    printf("Original Linked list: ");
    printList(head);

    // Delete node with value 7
    deleteNode(&head, 7);
    printf("Linked list after deletion of node with value 7: ");
    printList(head);

    // Delete node with value 9
    deleteNode(&head, 9);
    printf("Linked list after deletion of node with value 9: ");
    printList(head);

    return 0;
}
