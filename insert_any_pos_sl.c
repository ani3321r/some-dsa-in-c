#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *add_any(struct node *head, int d, int key)
{
    struct node *ptr = malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("Memory allocation failed\n");
        return head;
    }
    ptr->data = d;
    ptr->link = NULL;

    struct node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            ptr->link = temp->link;
            temp->link = ptr;
            break;
        }
        temp = temp->link;
    }
    return head;
}
int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->data = 50;
    head->link = NULL;
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = 70;
    head->link = ptr;
    ptr->link = NULL;
    int data = 10;
    int key = 70;
    head = add_any(head, data, key);
    ptr = head;
    while (ptr != NULL)
    {

        printf("%d\n", ptr->data);

        ptr = ptr->link;
    }
    return 0;
}