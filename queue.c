#include <stdio.h>
#include <stdlib.h>

int *queue;       // Pointer for dynamic array
int front = -1, rear = -1;
int maxSize = 0;  // Will be set by user

// Function to set queue size
void setQueueSize() {
    printf("Enter the size of the queue: ");
    scanf("%d", &maxSize);

    queue = (int *)malloc(maxSize * sizeof(int));
    if (queue == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Queue size set to %d.\n", maxSize);
}

void enqueue(int value) {
    if (rear == maxSize - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = value;
    printf("%d inserted.\n", value);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow!\n");
        return;
    }
    printf("%d removed.\n", queue[front++]);
}

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

    setQueueSize(); // First set size from user

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
                free(queue); // Free allocated memory
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}
