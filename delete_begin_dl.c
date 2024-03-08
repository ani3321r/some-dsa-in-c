#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Function to delete the first node of the doubly linked list
void deleteFirstNode(struct Node **head_ref)
{
    if (*head_ref == NULL)
        return;

    struct Node *temp = *head_ref;
    *head_ref = temp->next;

    if (*head_ref != NULL)
        (*head_ref)->prev = NULL;

    free(temp);
}

// Function to print the doubly linked list
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning of the doubly linked list
void insertAtBeginning(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}

int main()
{
    struct Node *head = NULL;

    // Insert some elements into the doubly linked list
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    printf("Original Doubly Linked List: ");
    printList(head);

    deleteFirstNode(&head);

    printf("Doubly Linked List after deleting first node: ");
    printList(head);

    return 0;
}
