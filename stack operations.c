#include <stdio.h>
#include<stdlib.h>
#define MAX 5

int stack[MAX], top = -1;

void push()
{
    int item;

    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
    {
        printf("Enter element: ");
        scanf("%d", &item);
        stack[++top] = item;
    }
}

void pop()
{
    if (top == -1)
        printf("Stack Underflow\n");
    else
        printf("Deleted element = %d\n", stack[top--]);
}

void display()
{
    int i;

    if (top == -1)
        printf("Stack is Empty\n");
    else
    {
        printf("Stack elements are:\n");
        for (i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: push();
                    break;

            case 2: pop();
                    break;

            case 3: display();
                    break;

            case 4: exit(0);

            default: printf("Invalid choice\n");
        }
    }

    return 0;
}
