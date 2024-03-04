#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to add a node at the beginning of the circular linked list
void addNodeAtBeginning(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;

    if (*head_ref == NULL)
    {
        new_node->next = new_node; // Point to itself to form a circular list
        *head_ref = new_node;
    }
    else
    {
        struct Node *last = *head_ref;
        while (last->next != *head_ref)
        {
            last = last->next;
        }
        new_node->next = *head_ref;
        last->next = new_node;
        *head_ref = new_node;
    }
}

// Function to add a node at any position in the circular linked list
void addNodeAtPosition(struct Node **head_ref, int new_data, int position)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;

    if (*head_ref == NULL)
    {
        new_node->next = new_node; // Point to itself to form a circular list
        *head_ref = new_node;
        return;
    }

    struct Node *temp = *head_ref;
    for (int i = 0; i < position - 1; i++)
    {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
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
        printf("\n");
    }
    else
    {
        printf("Circular linked list is empty.\n");
    }
}

int main()
{
    struct Node *head = NULL;
    int choice, data, position;

    while (1)
    {
        printf("\nChoose an option:\n");
        printf("1. Add node at the beginning\n");
        printf("2. Add node at any position\n");
        printf("3. Print the circular linked list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to be inserted: ");
            scanf("%d", &data);
            addNodeAtBeginning(&head, data);
            break;
        case 2:
            printf("Enter the data to be inserted: ");
            scanf("%d", &data);
            printf("Enter the position where the node should be inserted: ");
            scanf("%d", &position);
            addNodeAtPosition(&head, data, position);
            break;
        case 3:
            printf("Circular Linked List: ");
            printList(head);
            break;
        case 4:
            printf("Exiting the program.\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}