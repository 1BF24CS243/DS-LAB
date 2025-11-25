#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Stack operations (LIFO)
void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

void pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }
    struct Node* temp = *top;
    printf("Popped: %d\n", temp->data);
    *top = temp->next;
    free(temp);
}

// Queue operations (FIFO)
void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* newNode = createNode(data);
    if (*rear == NULL) {
        *front = *rear = newNode;
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
}

void dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Queue Underflow!\n");
        return;
    }
    struct Node* temp = *front;
    printf("Dequeued: %d\n", temp->data);
    *front = temp->next;
    if (*front == NULL) *rear = NULL;
    free(temp);
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *stack = NULL;
    struct Node *front = NULL, *rear = NULL;
    int choice, val;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Push (Stack)\n2. Pop (Stack)\n3. Display Stack\n");
        printf("4. Enqueue (Queue)\n5. Dequeue (Queue)\n6. Display Queue\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push(&stack, val);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                display(stack);
                break;
            case 4:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(&front, &rear, val);
                break;
            case 5:
                dequeue(&front, &rear);
                break;
            case 6:
                display(front);
                break;
            case 7:
                exit(0);
        }
    }
    return 0;
}