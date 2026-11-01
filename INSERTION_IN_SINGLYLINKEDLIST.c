#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};


void createList(struct Node **head, int n) {
    struct Node *newNode, *temp;
    int i, value;

    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newNode = (struct Node *)malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }

        newNode->data = value;
        newNode->next = NULL;


        if (*head == NULL) {
            *head = newNode;
        } else {

            temp = *head;

            while (temp->next != NULL) {
                temp = temp->next;
            }


            temp->next = newNode;
        }
    }
}


void insertBeginning(struct Node **head, int value) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
    printf("%d has been inserted in the beginning\n",value);
}


void insertEnd(struct Node **head, int value) {
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;


    if (*head == NULL) {
        *head = newNode;
        return;
    }

    temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    printf("%d has been inserted in the end\n",value);
}


void insertMiddle(struct Node **head, int value, int position) {
    struct Node *newNode, *temp;
    int i;

    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }


    if (position == 1) {
        insertBeginning(head, value);
        return;
    }

    temp = *head;


    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
    printf("%d has been inserted at position %d\n",value,position);
}


void display(struct Node *head) {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int n,choice, value, position;
    printf("enter the number of nodes:");
    scanf("%d",&n);
    createList(&head,n);

    do {
        printf("\n\n1. Insert at Beginning");
        printf("\n2. Insert at Middle/Position");
        printf("\n3. Insert at End");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &value);
                insertBeginning(&head, value);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                insertMiddle(&head, value, position);
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;

            case 4:
                display(head);
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
