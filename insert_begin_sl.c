#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *add_beg(struct node *head, int d)
{
    struct node *ptr = malloc(sizeof(struct node));

    ptr->data = d;

    ptr->link = head;

    head = ptr;
    return head;
};
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
    head = add_beg(head, data);
    ptr = head;
    while (ptr != NULL)
    {

        printf("%d\n", ptr->data);

        ptr = ptr->link;
    }
    return 0;
}