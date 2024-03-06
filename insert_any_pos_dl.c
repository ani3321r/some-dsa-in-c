#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at a specific position using key value
void addNodeByKey(struct Node **head_ref, int key, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *current = *head_ref;

    while (current != NULL && current->data != key)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Key not found in the list\n");
        return;
    }

    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL)
    {
        current->next->prev = newNode;
    }
    current->next = newNode;
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

int main()
{
    struct Node *head = NULL;

    // Appending nodes to create the doubly linked list
    head = createNode(1);
    head->next = createNode(2);
    head->next->prev = head;
    head->next->next = createNode(3);
    head->next->next->prev = head->next;

    // Printing the original doubly linked list
    printf("Original doubly linked list: ");
    printList(head);

    // Adding a node with key value 2 after it
    addNodeByKey(&head, 2, 4);

    // Printing the updated doubly linked list
    printf("Doubly linked list after adding node with key 2: ");
    printList(head);

    return 0;
}
