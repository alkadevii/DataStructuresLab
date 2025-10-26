#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int size, top=-1, *a;

void createstack(int s){
    size=s;
    a=(int *)malloc(sizeof(int)*size);
    if (a==NULL){
        printf("Memmory allocation falied\n");
        exit(1);
    }
}

bool isEmpty(){
    return top==-1;
}

bool isFull(){
    return top==size-1;
}

void push(int item){
    if (isFull()){
        printf("stact is full. Cannot push %d\n",item);
    }else{
        a[++top]=item;
        printf("Pushed: %d\n",item);
    }
}

int pop(){
    if (isEmpty()){
        printf("stack is empty. cannot pop. \n");
        return -1;
    }else{
        return a[top--];
    }
}

int peek(){
    if (isEmpty()){
        printf("stack is empty.\n");
        return -1;
    }else{
        return a[top];
    }
}

void main(){
    int choice, item, s;
    printf("Enter the sixe of the stack: ");
    scanf("%d", &s);
    createstack(s);
    while(1){
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter item to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                item = pop();
                if (item != -1) {
                    printf("Popped: %d\n", item);
                }
                break;
            case 3:
                item = peek();
                if (item != -1) {
                    printf("Top element: %d\n", item);
                }
                break;
            case 4:
                free(a);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }           
    }
}