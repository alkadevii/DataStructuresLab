#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *link;
} node;

node* head = NULL;

node* createHead() {
    node *h = malloc(sizeof(node));
    h->link = NULL;
    return h;
}

node* createNode(int data) {
    node *newnode = malloc(sizeof(node));
    newnode->value = data;
    newnode->link = NULL;
    return newnode;
}

void insertLast(node *head, int data) {
    node *newnode = createNode(data);
    node *current = head;

    while (current->link != NULL) {
        current = current->link;
    }
    current->link = newnode;
    printf("%d pushed onto stack.\n", data);
}

void deleteLast(node *head) {
    if (head->link == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    node *current = head->link;
    node *prev = head;

    while (current->link != NULL) {
        prev = current;
        current = current->link;
    }

    prev->link = NULL;
    printf("%d popped from stack.\n", current->value);
    free(current);
}

void display() {
    if (head == NULL || head->link == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    node *current = head->link;
    printf("Stack (bottom -> top): ");
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->link;
    }
    printf("\n");
}

void push(int item) {
    insertLast(head, item);
}

void pop() {
    deleteLast(head);
}

int main() {
    head = createHead();
    int ch, data;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option!\n");
        }
    }
}
