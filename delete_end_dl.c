#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Function to delete the last node of the doubly linked list
void deleteLastNode(struct Node **head_ref)
{
    if (*head_ref == NULL)
        return;

    struct Node *temp = *head_ref;

    // Traverse to the last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        *head_ref = NULL;

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

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    new_node->prev = last;
}

int main()
{
    struct Node *head = NULL;

    // Insert some elements into the doubly linked list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("Original Doubly Linked List: ");
    printList(head);

    deleteLastNode(&head);

    printf("Doubly Linked List after deleting last node: ");
    printList(head);

    return 0;
}
