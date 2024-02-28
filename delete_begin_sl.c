#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node
struct Node
{
    int data;
    struct Node *next;
};

// Function to delete the first node of a linked list
void deleteFirstNode(struct Node **head_ref)
{
    if (*head_ref == NULL)
    {
        printf("List is empty, deletion not possible\n");
        return;
    }

    struct Node *temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

// Function to insert a node at the beginning of the linked list
void insertFirst(struct Node **head_ref, int new_data)
{
    // Allocate memory for new node
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    // Assign data to the node
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
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function
int main()
{
    // Initialize an empty linked list
    struct Node *head = NULL;

    // Insert elements into the linked list
    insertFirst(&head, 3);
    insertFirst(&head, 2);
    insertFirst(&head, 1);

    // Print the original linked list
    printf("Original linked list: ");
    printList(head);

    // Delete the first node
    deleteFirstNode(&head);

    // Print the linked list after deletion
    printf("Linked list after deleting first node: ");
    printList(head);

    return 0;
}
