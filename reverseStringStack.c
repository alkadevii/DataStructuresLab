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
        printf("stack underflow\n");
        return '\0';
    }else{
        return stack[top--];
    }
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    scanf("%s", str);

    for (int i = 0; i < strlen(str); i++) {
        push(str[i]);
    }

    printf("Reversed string: ");
    while (top != -1) {
        printf("%c", pop());
    }

    printf("\n");
    return 0;
}