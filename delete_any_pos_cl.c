#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *next;
};

// Function to delete a node by key value
void deleteNode(struct Node **head_ref, int key)
{
    // If the list is empty, return
    if (*head_ref == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct Node *current = *head_ref, *prev = NULL;

    // Search for the node with the given key
    do
    {
        if (current->key == key)
        {
            // If the node to be deleted is the only node in the list
            if (current->next == *head_ref)
            {
                *head_ref = NULL;
                free(current);
                return;
            }

            // If the node to be deleted is the head node
            if (current == *head_ref)
            {
                prev = *head_ref;
                while (prev->next != *head_ref)
                    prev = prev->next;
                *head_ref = current->next;
                prev->next = *head_ref;
                free(current);
            }
            else
            {
                // If the node to be deleted is not the head node
                prev->next = current->next;
                free(current);
            }
            return;
        }
        prev = current;
        current = current->next;
    } while (current != *head_ref);

    // If the node with the given key is not found
    printf("Key not found in the list!\n");
}

// Function to insert a new node at the end of the circular linked list
void insertNode(struct Node **head_ref, int key)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;

    new_node->key = key;
    new_node->next = *head_ref;

    if (*head_ref == NULL)
    {
        new_node->next = new_node;
        *head_ref = new_node;
    }
    else
    {
        while (last->next != *head_ref)
            last = last->next;
        last->next = new_node;
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
            printf("%d ", temp->key);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;

    // Insert some nodes into the circular linked list
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);

    printf("Original Circular Linked List: ");
    printList(head);

    // Delete a node with key value 3
    deleteNode(&head, 3);
    printf("Circular Linked List after deleting node with key value 3: ");
    printList(head);

    // Delete a node with key value 1
    deleteNode(&head, 1);
    printf("Circular Linked List after deleting node with key value 1: ");
    printList(head);

    // Delete a node with key value 5
    deleteNode(&head, 5);
    printf("Circular Linked List after deleting node with key value 5: ");
    printList(head);

    return 0;
}
