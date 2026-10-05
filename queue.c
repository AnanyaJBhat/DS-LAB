#include<stdio.h>
#include<stdlib.h>
# define MAX 4
int queue[MAX];
int front=-1,rear=-1;
void enqueue(int n)
{
    if(rear==MAX-1){
        printf("queue overflow!\n");
        return;
    }
    else {
        if(front==-1&&rear==-1){
            front=0;
            rear=0;
            queue[rear]=n;
        }
        else{
            rear++;
            queue[rear]=n;
        }
    }
    printf("%d has been inserted\n",n);
}
void dequeue()
{
    if(front==-1)
    {
        printf("queue underflow!\n");
        return ;
    }
    int val=queue[front];
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        front++;
    }
    printf("%d has been deleted\n",val);
}
void display()
{
    if(front==-1){
        printf("queue is empty!\n");

    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
        printf("\n");}
}
int main()
{
    int choice;
    printf("queue menu---\n");
    printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
    while(1){
        printf("enter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            int n;
            printf("enter the value:");
            scanf("%d",&n);
            enqueue(n);
            break;
        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("invalid choice!\n");
        }
    }

}
