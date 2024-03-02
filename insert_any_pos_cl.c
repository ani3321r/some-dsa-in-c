#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to insert a node after a node with given key value
void insertAfterKey(struct Node **head, int key, int data)
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
        // Find the node with the key value
        while (temp->data != key)
        {
            temp = temp->next;
            // If key not found and back to the start, break to avoid infinite loop
            if (temp == *head)
            {
                printf("Key not found in the list.\n");
                return;
            }
        }
        // Insert the new node after the node with the key value
        newNode->next = temp->next;
        temp->next = newNode;
    }
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
    printf("\n");
}

int main()
{
    struct Node *head = NULL;

    // Insert elements into the circular linked list
    insertAfterKey(&head, 2, 1); // insert 1 after 2
    insertAfterKey(&head, 1, 3); // insert 3 after 1
    insertAfterKey(&head, 3, 2); // insert 2 after 3

    // Print the circular linked list
    printf("Circular Linked List: ");
    printList(head);

    return 0;
}
