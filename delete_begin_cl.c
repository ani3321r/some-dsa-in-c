#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to delete the first node of a circular linked list
void deleteFirstNode(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    // Find the last node
    struct Node *last = *head;
    while (last->next != *head)
        last = last->next;

    // If there's only one node
    if (*head == last)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        // Move head pointer to the second node
        struct Node *temp = *head;
        *head = (*head)->next;

        // Update the last node's next pointer
        last->next = *head;

        // Free memory of the first node
        free(temp);
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

struct Node *newNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main()
{
    struct Node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = head; // Make it circular

    printf("Original list: ");
    printList(head);

    // Delete the first node
    deleteFirstNode(&head);
    printf("After deleting first node: ");
    printList(head);

    return 0;
}
