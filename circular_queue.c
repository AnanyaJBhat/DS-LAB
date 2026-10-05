#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int c_queue[MAX];
int front=-1,rear=-1;
int isfull()
{
    if(front==0&&rear==MAX-1||front==rear+1){
        return 1;
    }
    return 0;

}
int isempty()
{
    if(front==-1){
        return 1;
    }
    return 0;
}
void enqueue(int n)
{
    if(isfull()){
        printf("overflow!\n");
    }
    else{
        if(front==-1&&rear==-1){
            front=0;
            rear=0;
        }
        else{
            rear=(rear+1)%MAX;

        }
        c_queue[rear]=n;
        printf("%d has been inserted!\n",n);
    }
}
void dequeue()
{
    if(isempty())
    {
        printf("queue underflow!\n");
        return ;
    }
    int val=c_queue[front];
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        front=(front+1)%MAX;
    }
    printf("%d has been deleted\n",val);
}
void display()
{
    int i;
    if(isEmpty){
        printf("queue is empty!\n");
        return;
    }
    for(i=front; ;i=(i+1)%MAX){
        printf("%d ",c_queue[i]);
        if(i==rear){
            break;
        }
    }
    printf("\n");
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
