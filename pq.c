#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct Customer{
    char name[50];
    char category[30];
    int priority;
}

struct Customer *queue;

int front=-1,rear=-1,MAX;

int getPriority(char category[]){
    if (strcasecmp(category,"DifferentlyAbled")==0)
        return 1;
    else if (strcasecmp(category,"Senior")==0)
        return 2;
    else if (strcasecmp(category,"Defence")==0)
         return 3;
    else 
        return 4;
}

void enqueue(char name[],char category[]){
    struct customer newCustomer;
    strcpy(newCustomer.name,name);
    strcpy(newCustomer.category,category);
    newCustomer.priority=getPriority(category);

    if (rear==MAX-1){
        printf("\nQueue is full! Cannot add more customers.\n");
        return;
    }

    if (front==-1) front=0;

    int i=rear;
    while (i>=front && quene[i].priority>newCustomer.priority){
        queue[i+1]=quene[i];
        i--;
    }
    queue[i+1]=newCustomer;
    rear++;
    printf("\nCustomer %s (%s) added successfully.\n",name,category);
}

void dequeue(){
    if (front==-1){
        printf("\nNo customers to serve!\n");
        return;
    }

    if (front==rear){
        front=rear=-1;
    }
    else
        front++;
}

void display(){
    if (front==-1){
        printf("\nNo customers in the queue.\n");
        return;
    }

    printf("\n--- Current Queue ---\n");
    for (int i=front;i<=rear;i++){
        printf("%d. %-15s | %-17s | Priority: %d\n",i-front+1,queue[i].name,queue[i].category,queue[i].priority);
    }
    printf("----------------------\n");
}

void main(){
    int ch;
    char name[50],category[50];

    printf("enter the size of the queue:");
    scanf("%d",&MAX);

    queue=(struct Customer*)malloc(MAX*sizeof(struct Customer));

    

}