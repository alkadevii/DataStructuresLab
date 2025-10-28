#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

typedef struct{
    char name[50];
    int priority;
}customer;

customer heap[MAX];
int size=0;

int getPriority(char type[]){
    if (strcmp(type,"differently_abled")==0)
        return 1;
    else if (strcmp(type,"senior_citizen")==0 )  
        return 2;
    else if (strcmp(type,"defence")==0)    
        return 3;
    else
        return 4;
}

void swap(customer *a,customer *b){
    customer temp=*a;
    *a=*b;
    *b=temp;
}

void insert(char name[],char type[]){
    if (size==MAX){
        printf("Heap Overflow! Cannot insert %s\n",name);
        return;
    }
    customer newCustomer;
    strcpy(newCustomer.name,name);
    newCustomer.priority=getPriority(type);

    int i=size;
    heap[size++]=newCustomer;

    while(i>0 && heap[(i-1)/2].priority>heap[i].priority){
        swap(&heap[i],&heap[(i-1)/2]);
        i=(i-1)/2;
    }
    printf("Customer '%s' (%s) added with priority %d.\n", name, type, newCustomer.priority);
}

void serveCustomer(){
    if (size==0){
        printf("No customers to serve.\n");
        return;
    }
    printf("Serving customer: %s (Priority %d)\n", heap[0].name, heap[0].priority);
    heap[0]=heap[size-1];
    size--;

    int i=0;
    while(1){
        int smallest=i;
        int left=2*1+1;
        int right=2*i+2;

        if (left<size && heap[left].priority<heap[smallest].priority){
            smallest=left;
        }
        if (right<size && heap[right].priority<heap[smallest].priority){
            smallest=right;
        }

         if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else
            break;
    }

}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

typedef struct customer{
    char name[50];
    int priority;
}customer;

customer heap[MAX];
int size=0;

int getPriority(char type[]){
    if (strcmp(type,"differently_abled")==0) return 1;
    else if (strcmp(type,"senior")==0) return 2;
    else if (strcmp(type,"defence")==0) return 3;
    return 4;
}

void swap(customer *a,customer *b){
    customer temp=*a;
    *a=*b;
    *b=temp;
}

void heapifyUp(int i){
    while (i>0 && heap[(i-1)/2].priority>heap[i].priority){
        swap(&heap[i],&heap[(i-1)/2]);
        i=(i-1)/2;
    }
}

void heapifyDown(){
    int i=0;
    while (1){
        int smallest=i;
        int left=(2*i)+1;
        int right=(2*i)+2;

        if (left<size && heap[left].priority<heap[smallest].priority)
            smallest=left;
        if (right<size && heap[right].priority<heap[smallest].priority)
            smallest=right;
        if (smallest!=i){
            swap(&heap[smallest],&heap[i]);
            i=smallest;
        }else{
            break;
        }
    }
}

void insert(char name[],char type[]){
    if (size==MAX-1){
        printf("queue is full\n");
        return;
    }
    customer newCustomer;
    strcpy(newCustomer.name,name);
    newCustomer.priority=getPriority(type);
    int i=size;
    heap[size++]=newCustomer;
    heapifyUp(i);
    printf("customer added");
}

void serveCustomer(){
    if (size==0){
        printf("no customer to serve");
        return;
    }
    printf("serving customer %s with priority %d",heap[0].name,heap[0].priority);
    heap[0]=heap[size-1];
    size--;
    heapifyDown();
}

void display() {
    if (size == 0) {
        printf("Queue is empty.\n");
        return;
    }

    printf("\n--- Customer Queue (Min-Heap Order) ---\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s (Priority %d)\n", i + 1, heap[i].name, heap[i].priority);
    }
}

int main() {
    int choice;
    char name[50], type[20];

    while (1) {
        printf("\n--- Customer Priority Queue (Min Heap) ---\n");
        printf("1. Add Customer\n");
        printf("2. Serve Customer\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter customer name: ");
                scanf("%s", name); 
                printf("Enter type (differently_abled / senior / defence / normal): ");
                scanf("%s", type);
                insert(name, type);
                break;

            case 2:
                serveCustomer();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}