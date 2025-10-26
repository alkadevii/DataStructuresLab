#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Customer structure
struct Customer {
    char name[50];
    char category[30];
    int priority; // Lower number = higher priority
};

struct Customer queue[MAX];
int front = -1, rear = -1;

// Function to determine priority based on category
int getPriority(char category[]) {
    if (strcasecmp(category, "DifferentlyAbled") == 0)
        return 1;
    else if (strcasecmp(category, "Senior") == 0)
        return 2;
    else if (strcasecmp(category, "Defence") == 0)
        return 3;
    else
        return 4; // Normal
}

// Enqueue customer by priority
void enqueue(char name[], char category[]) {
    struct Customer newCustomer;
    strcpy(newCustomer.name, name);
    strcpy(newCustomer.category, category);
    newCustomer.priority = getPriority(category);

    if (rear == MAX - 1) {
        printf("\nQueue is full! Cannot add more customers.\n");
        return;
    }

    if (front == -1) front = 0;

    int i;
    // Find position to insert (keep ascending priority)
    for (i = rear; i >= front && queue[i].priority > newCustomer.priority; i--) {
        queue[i + 1] = queue[i];
    }

    queue[i + 1] = newCustomer;
    rear++;
    printf("\nCustomer %s (%s) added successfully.\n", name, category);
}

// Dequeue (serve) the highest priority customer
void dequeue() {
    if (front == -1) {
        printf("\nNo customers to serve!\n");
        return;
    }

    printf("\nServing customer: %s (%s)\n", queue[front].name, queue[front].category);

    if (front == rear)
        front = rear = -1;
    else
        front++;
}

// Display queue
void display() {
    if (front == -1) {
        printf("\nNo customers in the queue.\n");
        return;
    }

    printf("\n--- Current Queue ---\n");
    for (int i = front; i <= rear; i++) {
        printf("%d. %-15s | %-17s | Priority: %d\n", 
               i - front + 1, queue[i].name, queue[i].category, queue[i].priority);
    }
    printf("----------------------\n");
}

// Main function
int main() {
    int choice;
    char name[50], category[30];

    printf("\n=== Priority Queue Simulation ===\n");
    printf("Priority Order: DifferentlyAbled > Senior > Defence > Normal\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Customer\n");
        printf("2. Serve Customer\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to clear newline

        switch (choice) {
            case 1:
                printf("\nEnter customer name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;

                printf("Enter category (DifferentlyAbled / Senior / Defence / Normal): ");
                fgets(category, sizeof(category), stdin);
                category[strcspn(category, "\n")] = 0;

                enqueue(name, category);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nExiting simulation. Goodbye!\n");
                return 0;

            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
}
