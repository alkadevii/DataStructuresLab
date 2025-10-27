#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* link;
}Node;

Node* createNode(){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->link=NULL;
    return newnode;
}

void insertFirst(Node* head,int data){
    Node* newnode=createNode();
    newnode->data=data;
    newnode->link=head->link;
    head->link=newnode;
}

void insertLast(Node* head,int data){
    Node* newnode=createNode();
    newnode->data=data;
    if (head->link==NULL){
        head->link=newnode;
    }else{
        Node* current=head->link;
        while (current->link!=NULL){
            current=current->link;
        }current->link=newnode;
    }
    newnode->link=NULL;
}

void insertAfter(Node* head,int data,int key){
    int flag=0;
    if (head->link==NULL){
        printf("Linked List Empty. \n Key not found");
    }else{
        Node* current=head->link;
        while (current!=NULL){
            if (current->data==key){
                flag=1;
                break;
            }else{
                current=current->link;
            }
        }

        if (flag==1){
            Node* newnode=createNode();
            newnode->data=data;
            newnode->link=current->link;
            current->link=newnode;
        }else{
            printf("Key not found");
        }
    }
}

void insertBefore(Node* head,int data,int key){
    int flag=0;
    if(head->link==NULL){
        printf("List Empty, Key not to be found");
    }else{
        Node* prev=head;
        Node* current=head->link;
        while (current!=NULL){
            if (current->data==key){
                flag=1;
                break;
            }prev=current;
            current=current->link;
        }

        if (flag==1){
            Node* newnode=createNode();
            newnode->data=data;
            prev->link=newnode;
            newnode->link=current;
        }else{
            printf("Key not found\n");
        }
    }
}

void deleteFirst(Node* head){
    if (head->link==NULL){
        printf("List Empty. Nothing to Delete");
    }else{
        head->link=head->link->link;
    }
}

void deleteLast(Node* head){
    if (head->link==NULL){
        printf("List Empty. Nothing to Delete");
    }else{
        Node* prev=head;
        Node* current=head->link;
        while (current->link!=NULL){
            prev=current;
            current=current->link;
        }prev->link=NULL;
    }
}

void deleteAfter(Node* head,int key){
    if (head->link==NULL){
        printf("List Empty. Nothing to Delete");
    }else{
        int flag=0;
        Node* current=head->link;
        while (current!=NULL){
            if (current->data==key){
                flag=1;
                break;
            }
            current=current->link;
        }
        if (flag==1){
            current->link=current->link->link;
        }else{
            printf("key not found");
        }
    }
}

void deleteBefore(Node* head,int key){
    if (head->link==NULL){
        printf("List Empty. Nothing to Delete");
    }else{
        int flag=0;
        Node* prevPrev;
        Node* prev=head;
        Node* current=head->link;
        while (current!=NULL){
            if (current->data==key){
                flag=1;
                break;
            }
            prevPrev=prev;
            prev=current;
            current=current->link;
        }
        if (flag==1){
            prevPrev->link=prev->link;
        }else{
            printf("key not found");
        }
    }
}

void search(Node* head,int key){
    if (head->link==NULL){
        printf("list empty\n");
    }else{
        int index=0;
        int flag=0;
        Node* current=head->link;
        while (current!=NULL){
            if (current->data==key){
                flag=1;
                break;
            }
            current=current->link;
            index++;
        }
        if (flag==1){
            printf("key found at index %d\n",index);
        }else{
            printf("key not found\n");
        }
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
    int ch,n,key;
    Node* head=createNode();

    while(1){
        printf("enter your choice\n");
        printf("1. Insert First\n");
        printf("2.Instert Last\n");
        printf("3.Insert After\n");
        printf("4.Insert Before\n");
        printf("5. Delete First\n");
        printf("6. Delete Last\n");
        printf("7. Delete After\n");
        printf("8. Delete Before\n");
        printf("9. Search\n");
        printf("10.Display\n");

        scanf("%d",&ch);

        switch(ch){
            case 1:
                 printf("enter value to insert");
                 scanf("%d",&n);
                 insertFirst(head,n);
                 break;
            case 2:
                 printf("enter value to insert");
                 scanf("%d",&n);
                 insertLast(head,n);
                 break;
            case 3:
                 printf("enter value to insert");
                 scanf("%d",&n);
                 printf("enter value to insert after");
                 scanf("%d",&key);
                 insertAfter(head,n,key);
                 break;
            case 4:
                 printf("enter value to insert");
                 scanf("%d",&n);
                 printf("enter value to insert before");
                 scanf("%d",&key);
                 insertBefore(head,n,key);
                 break;
            case 5:
                 deleteFirst(head);
                 break;
            case 6:
                 deleteLast(head);
                 break;
            case 7:
                 printf("enter the key");
                 scanf("%d",&key);
                 deleteAfter(head,key);
                 break;
            case 8:
                 printf("enter the key");
                 scanf("%d",&key);
                 deleteBefore(head,key);
                 break;
            case 9:
                 printf("enter the key to search");
                 scanf("%d",&key);
                 search(head,key);
                 break;
            case 10:
                 display(head);
                 break;
            default:
                 printf("Invalid choice");
        }
    }
}