#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node * next;
};
void createList(struct Node ** head,int n)
{
    struct Node *temp,*newnode;
    for(int i=1;i<=n;i++){
        int val;
        printf("enter the value of node %d:",i);
        scanf("%d",&val);
        newnode=(struct Node*)malloc(sizeof(struct Node));
        if(newnode==NULL){
           printf("memory allocation failed!\n");
           return;
        }
        newnode->data=val;
        newnode->next=NULL;
        if(*head==NULL){
            *head=newnode;

        }
        else{
        temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        }
    }


}
void display(struct Node*head)
{
    if(head==NULL){
        printf("empty!");
        return;
    }
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
void SortList(struct Node*head)
{
    struct Node*i;
    struct Node*j;
    printf("original list !\n");
    display(head);

    for(i=head;i->next!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next)
        {
            if(i->data>=j->data){
                int temp=i->data;
                i->data=j->data;
                j->data=temp;

            }
        }

    }
    printf("sorted list:\n");
    display(head);
}
struct Node* reverse(struct Node *head)

{   printf("original list !\n");
    display(head);
    struct Node*prev=NULL;
    struct Node*curr=head;
    struct Node*next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    printf("reversed list!\n");
    display(head);

    return head;
}
struct Node* concate(struct Node*head1,struct Node*head2)
{
    if(head1==NULL){
        return head2;
    }
    struct Node * temp;
    temp=head1;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head2;
    return head1;
}
void main()
{
    struct Node * head1=NULL;
    struct Node * head2=NULL;
    printf("LIST1:\n");
    createList(&head1,3);
    printf("LIST2:\n");
    createList(&head2,5);
    printf("\nREVERSE\n ");
    head1=reverse(head1);
    printf("\nSORTING\n");
    SortList(head2);

    struct Node*head3=concate(head1,head2);
    printf("\nCONCATENATION\n");
    printf("concatinated list:\n");
    display(head3);

}






