#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(){
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->next=newnode->prev=NULL;
    return newnode;
}

void insertFirst(Node* head,int data){
    Node* newnode=createNode();
    newnode->data=data;
    newnode->next=head->next;
    newnode->prev=head;
    if (head->next!=NULL){
        newnode->next->prev=newnode;
    }
    head->next=newnode;
}

void insertLast(Node* head,int data){
    Node* newnode=createNode();
    newnode->data=data;
    if (head->next==NULL){
        head->next=newnode;
        newnode->prev=head;
    }else{
        Node* current=head->next;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=newnode;
        newnode->prev=current;
    }
    newnode->next=NULL;
}

void insertAfter(Node* head,int data,int key){
    if (head->next==NULL){
        printf("list empty.\n");
        return;
    }else{
        int flag=0;
        Node* current=head->next;
        while (current!=NULL){
            if (current->data==key){
                flag=1;
                break;
            }
            current=current->next;
        }

        if (flag==1){
            Node* newnode=createNode();
            newnode->data=data;
            newnode->next=current->next;
            newnode->prev=current;
            if (current->next!=NULL){
                current->next->prev=newnode;
            }
            current->next=newnode;
        }
        else{
            printf("element not found\n");
        }
    }
}

void insertBefore(Node* head,int data,int key){
    if (head->next==NULL){
        printf("List Empty");
        return;
    }else{
        int flag=0;
        Node* current=head;
        while (current!=NULL){
            if (current->data==key){
                flag=1;
                break;
            }
            current=current->next;
        }

        if (flag==1){
            Node* newnode=createNode();
            newnode->data=data;
            newnode->next=current;
            newnode->prev=current->prev;
            newnode->prev->next=newnode;
            current->prev=newnode;
        }else{
            printf("Element not to be found");
        }
    }
}

void display(Node* head){
    if (head->next==NULL){
        printf("List empty\n");
        return;
    }
    Node* current=head->next;
    while (current!=NULL){
        printf("%d ->",current->data);
        current=current->next;
    }printf("NULL\n");
}

void main(){
    int ch,data,key;
    Node* head=createNode();

    while(1){
        printf("Enter your choice\n");
        printf("1.Insert First\n");
        printf("2.Insert Last\n");
        printf("3.Insert After\n");
        printf("4.Insert Before\n");
        printf("10. Display\n");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                 printf("enter value to insert");
                 scanf("%d",&data);
                 insertFirst(head,data);
                 break;
            case 2:
                 printf("enter value to insert");
                 scanf("%d",&data);
                 insertLast(head,data);
                 break;
            case 3:
                 printf("enter value to insert");
                 scanf("%d",&data);
                 printf("enter key to insert after");
                 scanf("%d",&key);
                 insertAfter(head,data,key);
                 break;
            case 4:
                 printf("enter value to insert");
                 scanf("%d",&data);
                 printf("enter key to insert before");
                 scanf("%d",&key);
                 insertBefore(head,data,key);
                 break;
            case 10:
                 display(head);
                 break;
            default:
                 printf("Invalid Choice");
        }
    }
}