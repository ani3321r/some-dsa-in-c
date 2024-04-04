#include <stdio.h>
 #include <stdlib.h>
 #define Size 5
 int queue[Size];
 int front =-1, rear =-1;
 void enqueue(int data)
 {
 if (rear == Size- 1)
 {
 printf("Queue Overflow\n");
 }
 else
 {
 if (front ==-1)
 {
 front = 0;
 }
 rear++;
 queue[rear] = data;
 }
 }
 int dequeue()
 {
 if (front ==-1 || front > rear)
 {
 printf("Queue unerflow\n");
 return-1;
 }
 else
 {
 int data = queue[front];
 front++;
 return data;
 }
 }
 void display()
 {
 if (front ==-1 || front > rear)
 {
printf("Queue unerflow\n");
 }
 else
 {
 printf("the queue is: ");
 for (int i = front; i <= rear; i++)
 {
 printf("%d ", queue[i]);
 }
 printf("\n");
 }
 }
 int main()
 {
 int choice, data;
 while (1)
 {
 printf("\nQueue Operations:");
 printf("\n1.enqueue\n2.dequeue\n3.display queue\n4.exit program");
 printf("\nEnter your choice: ");
 scanf("%d", &choice);
 switch (choice)
 {
 case 1:
 printf("Enter the value to enqueue: ");
 scanf("%d", &data);
 enqueue(data);
 break;
 case 2:
 data = dequeue();
 if (data !=-1)
 {
 printf("Dequeued element: %d\n", data);
 }
 break;
 case 3:
 display();
 break;
 case 4:
 printf("Exiting program...");
 exit(0);
}
 }
 return 0;
 }