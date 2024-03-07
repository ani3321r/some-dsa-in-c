#include <stdio.h>
#include <stdlib.h>
#define size 10

int stack[size];
int top = -1;

int isEmpty()
{
    return top == -1;
}

int isFull()
{
    return top == size - 1;
}

void push(int item)
{
    if (isFull())
    {
        printf("Stack overflow");
        return;
    }
    stack[++top] = item;
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack underflow");
        return -1;
    }
    printf("%d popped from the stack. \n", stack[top]);
    top--;
}

void display()
{
    if (top == -1)
    {
        printf("stack is empty.\n");
        return;
    }
    printf("elements of the stack are: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    int option, value;
    while (1)
    {
        printf("\nChoose from the following:\n");
        printf("1.push an element\n");
        printf("2.pop an element\n");
        printf("3.display stack\n");
        printf("4.exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\nEnter the value of the element: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program.");
            exit(0);
            break;
        default:
            printf("\nPlease enter a valid input");
        }
    }

    return 0;
}
