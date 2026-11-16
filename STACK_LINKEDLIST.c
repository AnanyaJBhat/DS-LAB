

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int value) {
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Stack Overflow\n");
        return;
    }

    newnode->data = value;
    newnode->next = top;
    top = newnode;

    printf("%d inserted\n", value);
}

void pop() {
    struct node *temp;

    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    temp = top;
    printf("Deleted element: %d\n", top->data);

    top = top->next;
    free(temp);
}

void peek() {
    if (top == NULL) {
        printf("Stack is Empty\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}

void display() {
    struct node *temp;

    if (top == NULL) {
        printf("Stack is Empty\n");
        return;
    }

    temp = top;

    printf("Stack elements:\n");

    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}



