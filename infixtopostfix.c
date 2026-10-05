#include<stdio.h>
#include<ctype.h>
# define MAX 100
char stack[MAX];
int top=-1;
void push(char ch)
{
    stack[++top]=ch;
}
int pop()
{
    return stack[top--];
}
int precedence(char ch)
{
    if (ch=='*'||ch=='/'||ch=='%'){
        return 2;
    }
    else if (ch=='+'||ch=='-'){
        return 1;
    }
    else {
            return 0;}
}
void infix_to_postfix(char infix[])
{
    char postfix[MAX];
    char ch;
    int i=0,j=0;
    for(int i=0;infix[i]!='\0';i++){
        ch=infix[i];
        if(ch=='('){
            push(ch);
        }
        else if (isalnum(ch)){
            postfix[j++]=ch;
        }
        else if (ch==')'){
            while(top!=-1 && stack[top]!='('){
                    postfix[j++]=pop();

               }
            pop();
        }
        else{
                while(top!=-1&& stack[top]!='('&& precedence(stack[top])>=precedence(ch)){
                        postfix[j++]=pop();

                }
                push(ch);


        }
    }
    while(top!=-1){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    printf("postfix expression is %s\n",postfix);

}
void main()
{
    char infix[100];
    printf("enter an infix expression:");
    scanf("%s",infix);
    infix_to_postfix(infix);
}
