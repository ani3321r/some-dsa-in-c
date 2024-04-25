#include <stdio.h>
#include <stdlib.h>
#define max_size 5
int deque[max_size];
int front = -1, rear = -1;

void insert(int data)
{
    if ((rear + 1) % max_size == front)
    {
        printf("deque overflow\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == max_size - 1)
    {
        rear = 0;
    }
    else
    {
        rear = rear + 1;
    }
    deque[rear] = data;
}

int deleteFront()
{
    if (front == -1)
    {
        printf("deque is empty\n");
        return -1;
    }
    int temp = deque[front];

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % max_size;
    }
    printf("The deleted element is %d", temp);
    return temp;
}

int deleteRear()
{
    if (front == -1)
    {
        printf("deque is empty\n");
        return -1;
    }
    int temp = deque[rear];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
    {
        rear = max_size - 1;
    }
    else
    {
        rear = rear - 1;
    }
    printf("The deleted element is %d", temp);
    return temp;
}

void display()
{
    if (front == -1)
    {
        printf("deque is empty\n");
        return;
    }
    int i = front;
    printf("deque elements: ");
    while (1)
    {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % max_size;
    }
    printf("\n");
}

int main()
{
    int choice, data;
    while (1)
    {
        printf("\n1.insert\n2.delete front\n3.delete rear\n4.display\n5.exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d", &data);
            insert(data);
            break;
        case 2:
            deleteFront();
            break;
        case 3:
            deleteRear();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("exiting program...");
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}