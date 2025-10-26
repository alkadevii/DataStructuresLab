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

void insertFirst(Node* head,int data){
    Node* newnode=createNode();
    newnode->data=data;
    newnode->link=head->link;
    head->link=newnode;
}

void countNodes(Node* head){
    if (head->link==NULL){
         printf("list empty");
    }else{
        int i=0;
        Node* current=head->link;
        while (current->link!=NULL){
            current=current->link;
            i++;
        }
        printf("there are %d nodes\n",i);
    }
}

void display(Node* head){
    if (head->link==NULL){
        printf("list is empty");
    }else{
        Node* current=head->link;
        while (current->link!=NULL){
            printf("%d -> ",current->data);
            current=current->link;
        }printf("NULL\n");
    }
}

void main(){
    int ch,n;
    Node* head=createHead();

    while(1){
        printf("enter choice\n");
        printf("1.Insert\n");
        printf("2.Count Nodes\n");
        printf("3.Display\n");
        scanf("%d",&ch);
        
        switch(ch){
            case 1:
                printf("enter value to insert");
                scanf("%d",&n);
                insertFirst(head,n);
                break;
            case 2:
                 countNodes(head);
                 break;
            case 3:
                 display(head);
                 break;
            default:
                 printf("Invalid Choice");
        }
    }
}