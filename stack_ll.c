#include <stdio.h>
#include <stdlib.h>

// Node structure for the stack
struct Node {
    int data;
    struct Node *next;
};

// Pointer to the top of the stack
struct Node *top = NULL;

// Push an element onto the stack
void push(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Element %d pushed onto the stack.\n", value);
}

// Pop an element from the stack
void pop() {
    if (top == NULL) {
        printf("Stack Underflow!\n");
    } else {
        struct Node *temp = top;
        top = top->next;
        printf("Element %d popped from the stack.\n", temp->data);
        free(temp);
    }
}

// Display the contents of the stack
void printStack() {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        struct Node *temp = top;
        printf("Stack contents: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                printStack();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}