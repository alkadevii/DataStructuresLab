#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char page[50];
    struct node* next;
    struct node* prev;
}node;

node* createnode(char *pagename){
    node *newnode=(node*)malloc(sizeof(node));
    strcpy(newnode->page,pagename);
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

node* visitNewPage(node* current,char* pagename){
    node *newnode=createnode(pagename);
    if (current!=NULL){
        newnode->prev=current;
        current->next=newnode;
    }
    current=newnode;
    return current;
}

node* goBack(node* current){
    if (current!=NULL && current->prev!=NULL){
        current=current->prev;
    }else{
        printf("No previous page to go back to.\n");
    }
    return current;
}

node* goForward(node* current){
    if (current!=NULL && current->next!=NULL){
        current=current->next;
    }else{
        printf("No forward page to go to.\n");
    }
    return current;
}

void showcurrent(node* current){
    if (current==NULL){
        printf("No page currently open.\n");
    }else{
        printf("Current page: %s\n",current->page);
    }
}

void main(){
    node* current=NULL;
    int choice;
    char pagename[50];

    while(1){
        printf("Browser Navigation Menu:\n");
        printf("1. Visit New Page\n");
        printf("2. Go Back\n");
        printf("3. Go Forward\n");
        printf("4. Show Current Page\n");
        printf("5. Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter page name to visit: ");
                scanf("%s",pagename);
                current=visitNewPage(current,pagename);
                showcurrent(current);
                break;
            case 2:
                current=goBack(current);
                showcurrent(current);
                break; 
            case 3:
                current=goForward(current);
                showcurrent(current);
                break; 
            case 4:
                showcurrent(current);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");

        }
    }
}

