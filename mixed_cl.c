#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node
struct Node
{
    int data;
    struct Node *next;
};

// Function to add a node at the beginning of the circular linked list
void addNodeAtBeginning(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = *head_ref;

    // If the list is empty, then make the new node as head
    if (*head_ref == NULL)
    {
        new_node->next = new_node;
    }
    else
    {
        // Otherwise, find the last node and link it to the new node
        while (last->next != *head_ref)
            last = last->next;
        last->next = new_node;
    }

    // Update head pointer
    *head_ref = new_node;
}

// Function to add a node at any position in the circular linked list
void addNodeAtPosition(struct Node **head_ref, int new_data, int position)
{
    if (position <= 0)
    {
        printf("Invalid position!\n");
        return;
    }

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;

    if (*head_ref == NULL)
    {
        if (position == 1)
        {
            new_node->next = new_node;
            *head_ref = new_node;
        }
        else
        {
            printf("Invalid position!\n");
            free(new_node);
        }
        return;
    }

    struct Node *temp = *head_ref;

    // Traverse to the node just before the desired position
    for (int i = 1; i < position - 1; i++)
    {
        temp = temp->next;
        if (temp == *head_ref)
        {
            printf("Invalid position!\n");
            free(new_node);
            return;
        }
    }

    // Update pointers to insert the new node
    new_node->next = temp->next;
    temp->next = new_node;
}

// Function to delete a node at any position in the circular linked list
void deleteNodeAtPosition(struct Node **head_ref, int position)
{
    if (*head_ref == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = *head_ref, *prev;

    // If the node to be deleted is the head node
    if (position == 1)
    {
        while (temp->next != *head_ref)
            temp = temp->next;
        if (temp == *head_ref)
        {
            free(temp);
            *head_ref = NULL;
        }
        else
        {
            temp->next = (*head_ref)->next;
            free(*head_ref);
            *head_ref = temp->next;
        }
        return;
    }

    // Find the node to be deleted
    for (int i = 1; i < position && temp->next != *head_ref; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp->next == *head_ref && position > 1)
    {
        printf("Invalid position!\n");
        return;
    }

    // Remove the node
    prev->next = temp->next;
    free(temp);
}

// Function to print the circular linked list
void printList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
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
        printf("4. Print the circular linked list\n");
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
            printf("Circular Linked List: ");
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
