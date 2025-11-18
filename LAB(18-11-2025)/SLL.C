#include <stdio.h>
#include<stdlib.h>       
struct Node{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

//creating list
void createList(int n) 
{
    struct Node *newNode, *temp;
    int data, i;
    if (n <= 0) {
        printf("Number of nodes should be greater than 0. \n");
        return;
    }
    for (i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed. \n");
            return;
        }
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode; 
    }
    printf("\nLinked list created successfully \n");
}

//inserting at beginning
void insertAtBeginning(int data) 
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("Node inserted at the beginning. \n");
}

//inserting at end
void insertAtEnd(int data) 
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Node inserted at the end. \n");
}

//inserting at any position
void insertAtPosition(int data, int pos) {
    int i;
    struct Node *newNode, *temp = head;
    if (pos < 1) {
        printf("Invalid position. \n");
        return;
    }
    if (pos == 1) {
        insertAtBeginning(data);
        return;
    }
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Position out of range. \n");
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Node inserted at position %d. \n", pos);
    }
}

//deletion at beginning
void deleteAtBeginning() {
    struct Node *temp;
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
}

//deletin at end
void deleteAtEnd() {
    struct Node *temp, *prev;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    if(head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    temp = head;
    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

//deletion at specific position
void deleteAtPosition(int pos) {
    struct Node *temp, *del;
    int i;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;

    if(pos == 1) {
        head = head->next;
        free(temp);
        return;
    }

    for(i = 1; i < pos-1; i++) {
        temp = temp->next;
        if(temp == NULL) {
            printf("Invalid Position\n");
            return;
        }
    }

    del = temp->next;
    temp->next = del->next;
    free(del);
}


//display function
void displayList() {
    struct Node *temp = head;
    if (head == NULL) {
        printf("List is empty. \n");
        return;
    }
    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//mainfunction
int main()
{
    int choice,n,data,pos;
    while(1)
    {
        printf("--singly linked list--\n");
        printf("1.create a linked list\n");
        printf("2.insert at the beginning\n");
        printf("3.insert at the any positin\n ");
        printf("4.insert at the end\n");
        printf("5.delete at beginning\n");
        printf("6.delete at end\n");
        printf("7.delete at specific position\n");
        printf("8.display all the elments\n");
        printf("9.exit\n");
        printf("Enter urs choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("enter the number of nodes");
                    scanf("%d",&n);
                    createList(n);
                    break;
            case 2: printf("enter the data to insert");
                    scanf("%d",&data);
                    insertAtBeginning(data);
                    break;
            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                insertAtPosition(data, pos);
                break;
            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 5:
                deleteAtBeginning();
                break;
            case 6:
                deleteAtEnd();
                break;
            case 7:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 8:
                displayList();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}


        


    

    

