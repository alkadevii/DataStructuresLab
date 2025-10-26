#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* link;
}Node;

Node* createNode(){
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->link=NULL;
    return newnode;
}

Node* createHead(){
    Node* head=(Node*)malloc(sizeof(Node));
    head->link=NULL;
    return head;
}

void insertFirst(Node* head, int data){
    Node* newnode=createNode();
    newnode->data=data;
    newnode->link=head->link;
    head->link=newnode;
}

void sortList(Node* head){
    if (head->link==NULL || head->link->link==NULL){
        printf("List Empty or Too Short. Sorting not Possible");
        return;
    }
    while(1){
        int flag=0;
        Node* current=head->link;
        while(current->link!=NULL){
        if (current->data>current->link->data){
            int temp=current->data;
            current->data=current->link->data;
            current->link->data=temp;
            flag=1;
        }
        current=current->link;
        }

        if (flag==0){
            break;
        }
    }
}


void display(Node* head){
    if (head->link==NULL){
        printf("List Empty\n");
        return;
    }
    Node* current=head->link;
    while (current!=NULL){
        printf("%d ->",current->data);
        current=current->link;
    }
    printf("NULL\n");
}

void main(){
    Node* head=createHead();
    int ch,n;

    while(1){
        printf("enter your choice\n");
        printf("1.Insert\n");
        printf("2.Sort\n");
        printf("3.Display\n");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("enter value to insert");
                scanf("%d",&n);
                insertFirst(head,n);
                break;
            case 2:
                sortList(head);
                break;
            case 3:
                display(head);
                break;
            default:
                printf("Invalid Choice");
        
        }
    }
}