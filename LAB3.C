#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;


void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow");
    } else if (front == -1 && rear==-1){
            front = rear=0;
            queue[rear]=value;
    }
       else{
        rear++;
        queue[rear] = value;
        }
}


void dequeue() {
    if (front ==-1 && rear==-1) {
        printf("Queue Underflow");
    } else if(front == rear){
        front=rear=-1;
    }
    else{
         printf("Deleted element: %d\n", queue[front]);
        front++;
    }
 }



void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
