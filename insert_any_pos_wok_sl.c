#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node
struct Node
{
    int data;
    struct Node *next;
};

// Function to add a node at the beginning of the linked list
void addNodeAtBeginning(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to add a node at any position in the linked list
void addNodeAtPosition(struct Node **head_ref, int new_data, int position)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    struct Node *temp = *head_ref;

    if (position == 1)
    {
        new_node->next = temp;
        *head_ref = new_node;
        return;
    }

    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position!\n");
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

// Function to print the linked list
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
    int choice, data, position;

    while (1)
    {
        printf("\nChoose an option:\n");
        printf("1. Add node at the beginning\n");
        printf("2. Add node at any position\n");
        printf("3. Print the linked list\n");
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
            printf("Linked List: ");
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
