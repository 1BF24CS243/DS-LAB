#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;


void enqueue() {
    int item;
    if ((front == 0 && rear == SIZE - 1) || (rear + 1 == front)) {
        printf("Queue Overflow");
    } else {
        printf("Enter the element to insert: ");
        scanf("%d", &item);

        if (front == -1)
            front = rear = 0;
        else
            rear = (rear + 1) % SIZE;

        queue[rear] = item;
    }
}


void dequeue() {
    if (front == -1) {
        printf("Queue Underflow");
    } else {
        int item = queue[front];
        printf("Deleted element: %d\n", item);

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }
}


void display() {
    if (front == -1) {
        printf("\nQueue is empty.\n");
    } else {
        printf("\nQueue elements are: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}


