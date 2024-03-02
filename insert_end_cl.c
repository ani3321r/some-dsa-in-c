#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to insert a node at the end of a circular linked list
void insertAtEnd(struct Node **head, int data)
{
    // Create a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the list is empty, make the new node as the head
    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = *head; // Point to itself to make it circular
    }
    else
    {
        struct Node *temp = *head;

        // Traverse to the last node
        while (temp->next != *head)
        {
            temp = temp->next;
        }

        // Insert the new node at the end
        temp->next = newNode;
        newNode->next = *head; // Make it circular
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
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;

    // Insert elements into the circular linked list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);

    // Print the circular linked list
    printf("Circular Linked List: ");
    printList(head);

    return 0;
}
