#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to insert a node at the beginning of a circular linked list
void insertAtBeginning(struct Node **head_ref, int new_data)
{
    // Allocate memory for new node
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;

    // Put data into the new node
    new_node->data = new_data;

    // If the list is empty, make the new node as head and point its next to itself
    if (*head_ref == NULL)
    {
        new_node->next = new_node;
        *head_ref = new_node;
        return;
    }

    // Otherwise, traverse to the last node
    while (last->next != *head_ref)
    {
        last = last->next;
    }

    // Make the new node's next point to the current head
    new_node->next = *head_ref;

    // Make the last node's next point to the new node
    last->next = new_node;

    // Make the new node as the new head
    *head_ref = new_node;
}

// Function to print the circular linked list
void printList(struct Node *head)
{
    struct Node *temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}

int main()
{
    // Start with an empty list
    struct Node *head = NULL;

    insertAtBeginning(&head, 9);
    insertAtBeginning(&head, 8);
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 6);

    printf("Original Circular Linked list: ");
    printList(head);
    printf("\n");

    return 0;
}
