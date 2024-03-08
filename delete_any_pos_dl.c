#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Function to delete a node with a given key value from the doubly linked list
void deleteNode(struct Node **head_ref, int key)
{
    if (*head_ref == NULL)
        return;

    struct Node *temp = *head_ref;

    // Find the node with the given key
    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    // If the key is not found
    if (temp == NULL)
        return;

    // Adjust the pointers to remove the node
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *head_ref = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

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

    deleteNode(&head, 3);

    printf("Doubly Linked List after deleting node with key value 3: ");
    printList(head);

    return 0;
}
