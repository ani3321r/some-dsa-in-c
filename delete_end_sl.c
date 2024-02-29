#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to delete the end node of a linked list
void deleteEndNode(struct Node **head)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        // If the list is empty or has only one node
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *temp = *head;
    struct Node *prev = NULL;

    // Traverse to the end of the list
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    // Delete the end node
    free(temp);
    prev->next = NULL;
}

// Function to print the linked list
void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original linked list: ");
    printList(head);

    // Delete the end node
    deleteEndNode(&head);

    printf("Linked list after deleting the end node: ");
    printList(head);

    // Free the memory allocated for the linked list
    while (head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
