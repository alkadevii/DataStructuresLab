#include <stdio.h>
#include <stdlib.h>

int *queue;      // Dynamically allocated array
int front = -1, rear = -1;
int size;        // Size of the queue set by user

// Function to set queue size dynamically
void setQueueSize() {
    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    queue = (int *)malloc(size * sizeof(int));
    if (queue == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Queue of size %d created.\n", size);
}

// Enqueue function
void enqueue(int value) {
    if (front==(rear+1)%size) {
        printf("Queue Overflow!\n");
    }else if(front==-1){
        front=rear=0;
    }else{
        rear=(rear+1)%size;
    }
    queue[rear]=value;
    printf("inserted value");
    
}

// Dequeue function
void dequeue() {
    if (front==-1)
        printf("queue underflow");
    else{
        printf("%d deleted",queue[front]);
        if (front==rear)
            front=rear=-1;
        else
            front=(front+1)%size;
    }
}

// Display function
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, val;

    setQueueSize(); // Call function to set size and allocate memory

    while (1) {
        printf("\n--- Simple Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                free(queue); // Free allocated memory before exit
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}
