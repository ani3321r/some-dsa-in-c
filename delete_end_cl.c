#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to delete the last node of a circular linked list
void deleteEndNode(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = *head;
    struct Node *prev = NULL;

    // Traverse the list to find the last and second-to-last nodes
    while (temp->next != *head)
    {
        prev = temp;
        temp = temp->next;
    }

    // If there's only one node in the list
    if (prev == NULL)
    {
        free(temp);
        *head = NULL;
    }
    else
    {
        prev->next = temp->next; // Update the next pointer of the second-to-last node
        free(temp);              // Free the memory of the last node
    }
}

// Function to insert a new node at the end of a circular linked list
void insertEnd(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = *head;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

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
        printf("\n");
    }
}

int main()
{
    struct Node *head = NULL;

    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 5);

    printf("Original List: ");
    printList(head);

    deleteEndNode(&head);

    printf("List after deleting the end node: ");
    printList(head);

    return 0;
}
