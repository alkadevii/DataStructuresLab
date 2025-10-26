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

int getLength(Node* head){
    int count=1;
    Node* current=head->link;
    while (current!=NULL){
        current=current->link;
        count++;
    }
    return count;
}

int getMiddleNode(Node* head){
    int length=getLength(head);
    int mid=length/2;
    Node* current=head->link;
    for (int i=mid;i>0;i--){
        current=current->link;
    }
    return current->data;
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
        printf("2.Find Middle Node\n");
        printf("3.Display\n");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("enter value to insert");
                scanf("%d",&n);
                insertFirst(head,n);
                break;
            case 2:
                printf("The middle node is %d\n",getMiddleNode(head));
                break;
            case 3:
                display(head);
                break;
            default:
                printf("Invalid Choice");
        
        }
    }
}