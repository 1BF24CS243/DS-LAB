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

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sortList(struct Node* head) {
    struct Node *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void reverseList(struct Node** head) {
    struct Node *prev = NULL, *curr = *head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

struct Node* concatenate(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) return list2;
    struct Node* temp = list1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = list2;
    return list1;
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL;
    int choice, val;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert in List1\n2. Insert in List2\n3. Display List1\n4. Display List2\n");
        printf("5. Sort List1\n6. Reverse List1\n7. Concatenate List1 & List2\n8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertEnd(&list1, val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertEnd(&list2, val);
                break;
            case 3:
                display(list1);
                break;
            case 4:
                display(list2);
                break;
            case 5:
                sortList(list1);
                printf("List1 Sorted.\n");
                break;
            case 6:
                reverseList(&list1);
                printf("List1 Reversed.\n");
                break;
            case 7:
                list1 = concatenate(list1, list2);
                printf("Concatenated List: ");
                display(list1);
                break;
            case 8:
                exit(0);
            default:
                printf("invalid choice");
        }
    }
    return 0;
}