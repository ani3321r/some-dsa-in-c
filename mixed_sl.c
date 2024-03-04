#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *newNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to add a node at the beginning of the linked list
void addNodeAtBeginning(struct Node **head_ref, int new_data)
{
    struct Node *new_node = newNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to add a node at any position in the linked list
void addNodeAtPosition(struct Node **head_ref, int new_data, int position)
{
    struct Node *new_node = newNode(new_data);

    if (position <= 0)
    {
        printf("Invalid position!\n");
        free(new_node);
        return;
    }

    if (position == 1)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    struct Node *temp = *head_ref;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position!\n");
        free(new_node);
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

// Function to delete a node at any position in the linked list
void deleteNodeAtPosition(struct Node **head_ref, int position)
{
    if (*head_ref == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = *head_ref;
    if (position == 1)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    // Find the previous node of the node to be deleted
    for (int i = 1; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }

    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL)
    {
        printf("Invalid position!\n");
        return;
    }

    // Node temp->next is the node to be deleted
    struct Node *next = temp->next->next;

    // Unlink the node from the linked list
    free(temp->next);
    temp->next = next;
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
        printf("3. Delete node at any position\n");
        printf("4. Print the linked list\n");
        printf("5. Exit\n");
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
            printf("Enter the position of the node to delete: ");
            scanf("%d", &position);
            deleteNodeAtPosition(&head, position);
            break;
        case 4:
            printf("Linked List: ");
            printList(head);
            break;
        case 5:
            printf("Exiting the program.\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
