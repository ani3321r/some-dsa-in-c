#include <stdio.h>
#define max_size 5

int queue[max_size];
int front = -1, rear = -1;

void enqueue(int data)
{
    if ((rear + 1) % max_size == front)
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear = (rear + 1) % max_size;
    queue[rear] = data;
}
int dequeue()
{
    if (front == -1)
    {
        printf("queue is empty");
        return -1;
    }
    int data = queue[front];
    if (front == rear)
        front = rear - 1;
    else
        front = (front + 1) % max_size;
    return data;
}
void display()
{
    if (front == -1)
    {
        printf("queue is empty\n");
        return;
    }
    printf("queue elements: ");
    int i = front;
    while (i != rear)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % max_size;
    }
    printf("%d\n", queue[rear]);
}
int main()
{
    int choice, item;
    while (1)
    {
        printf("\n1.enqueue\n2.dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            enqueue(item);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("exiting program...");
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}