#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

char stack[MAX];
int top=-1;

void push(char ch){
    if (top==MAX-1){
        printf("stack overflow\n");
    }else{
        stack[++top]=ch;
    }
}

char pop(){
    if (top==-1){
        printf("stack overflow\n");
        return '\0';
    }else{
        return stack[top--];
    }
}

int isBalanced(char exp[]){
    for (int i=0;exp[i]!='\0';i++){
        char ch=exp[i];
        if (ch=='(' || ch=='{' || ch=='['){
            push(ch);
        }else if (ch==')' || ch=='}' || ch==']'){
            char popped=pop();
            if ((ch==')' && popped!='(') || (ch=='}' && popped!='{') || (ch==']' && popped!='[')){
                return 0;
        }
    }
}
     return (top==-1);
}

void main(){
    char exp[MAX];
    printf("enter the expression: ");
    scanf("%s",exp);
    if (isBalanced(exp)){
        printf("The expression is balanced\n");
    }else{
        printf("The expression is not balanced\n");
    }
}