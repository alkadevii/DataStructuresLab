#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int size, top = -1, *a;

// Function to create the stack
void createStack(int s) {
    size = s;
    a = (int *)malloc(sizeof(int) * size);
    if (a == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

// Function to check if the stack is empty
bool isEmpty() {
    return top == -1;
}

// Function to check if the stack is full
bool isFull() {
    return top == size - 1;
}

// Function to push an element onto the stack
void push(int item) {
    if (isFull()) {
        printf("Stack is full. Cannot push %d\n", item);
    } else {
        a[++top] = item;
        printf("Pushed: %d\n", item);
    }
}

// Function to pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    } else {
        return a[top--];
    }
}

// Function to peek at the top element of the stack
int peek() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return -1;
    } else {
        return a[top];
    }
}

int main() {
    int choice, item, s;

    printf("Enter the size of the stack: ");
    scanf("%d", &s);
    createStack(s);

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to push: ");
                scanf("%d", &item);
                push(item);
                break;

            case 2:
                item = pop();
                if (item != -1)
                    printf("Popped: %d\n", item);
                break;

            case 3:
                item = peek();
                if (item != -1)
                    printf("Top element: %d\n", item);
                break;

            case 4:
                printf("Exiting...\n");
                free(a);  // Free dynamically allocated memory
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}