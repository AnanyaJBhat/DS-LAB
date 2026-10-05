// VALID PARENTHESIS
#include<stdbool.h>
#include<string.h>
#include<stdio.h>
bool ValidParenthesis(char*s)
{
    char stack[strlen(s)];
    int top=-1;
    for(int i=0;s[i]!='\0';i++){
        char ch=s[i];
        if(ch=='('||ch=='{'||ch=='['){
            stack[++top]=ch;
        }
        else if (ch=='}'||ch==']'||ch==')'){
            if(top==-1){
                return false;
            }
            else{
                char top_char=stack[top--];
                if (ch=='}'&& top_char!='{') return false;
                if (ch==']'&& top_char!='[') return false;
                if (ch==')'&& top_char!='(') return false;
            }
        }

    }
    return top==-1;

}
int main()
{
    char s[100];
    printf("enter a parenthesis string:");
    scanf("%s",s);
    bool result =ValidParenthesis(s);
    printf("Valid parenthesis:%s",result?"true":"false");
    return 0;
}
