#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};

struct node *add_end(struct node *head, struct node *end, int d)
{
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = d;
    ptr->link = NULL;

    if (head == NULL)
    {
        head = ptr;
        end = ptr;
    }
    else
    {
        end->link = ptr;
        end = ptr;
    }

    return end;
};

int main()
{
    struct node *head = NULL;
    struct node *ptr = NULL;
    struct node *end = NULL;
    int data = 10;

    end = add_end(head, end, data);
    if (head == NULL)
        head = end;

    data = 50;
    end = add_end(head, end, data);

    data = 60;
    end = add_end(head, end, data);

    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    return 0;
}
