#include <stdio.h>
#include <stdlib.h>

int *deque;       // dynamic array
int front = -1, rear = -1;
int MAX;          // will be set by user

void setDequeSize() {
    printf("Enter size of deque: ");
    scanf("%d", &MAX);

    deque = (int *)malloc(MAX * sizeof(int));
    if (deque == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Deque size set to %d.\n", MAX);
}

void insertFront(int value) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque Overflow!\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }
    deque[front] = value;
    printf("%d inserted at front.\n", value);
}

void insertRear(int value) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Deque Overflow!\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = value;
    printf("%d inserted at rear.\n", value);
}

void deleteFront() {
    if (front == -1) {
        printf("Deque Underflow!\n");
        return;
    }
    printf("%d deleted from front.\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

void deleteRear() {
    if (front == -1) {
        printf("Deque Underflow!\n");
        return;
    }
    printf("%d deleted from rear.\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

void display() {
    if (front == -1) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, val;

    setDequeSize(); // ask user for size at start

    while (1) {
        printf("\n--- Deque Menu ---\n");
        printf("1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &val); insertFront(val); break;
            case 2: printf("Enter value: "); scanf("%d", &val); insertRear(val); break;
            case 3: deleteFront(); break;
            case 4: deleteRear(); break;
            case 5: display(); break;
            case 6: 
                free(deque); 
                exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}
