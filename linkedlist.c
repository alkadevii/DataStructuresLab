#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *link;
} node;

node* createhead() {
    node *head;
    head = malloc(sizeof(node));
    head->link = NULL;
    return head;
}

node* createnode() {
    node *newnode;
    newnode = malloc(sizeof(node));
    return newnode;
}

void insertfirst(node *head, int data) {
    node *newnode = createnode();
    newnode->value = data;
    newnode->link = head->link;
    head->link = newnode;
}

void insertlast(node *head, int data) {
    node *newnode = createnode();
    newnode->value = data;
    newnode->link = NULL;

    node *current = head;
    while (current->link != NULL) {
        current = current->link;
    }
    current->link = newnode;
}

void deletefirst(node *head) {
    if (head->link == NULL) {
        printf("List is empty.\n");
        return;
    }
    node *temp = head->link;
    head->link = temp->link;
    free(temp);
    printf("First node deleted.\n");
}

void deletelast(node *head) {
    if (head->link == NULL) {
        printf("List is empty.\n");
        return;
    }
    node *current = head->link;
    node *prev = head;
    while (current->link != NULL) {
        prev = current;
        current = current->link;
    }
    prev->link = NULL;
    free(current);
    printf("Last node deleted.\n");
}

void display(node *head) {
    node *current = head->link;
    if (current == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->link;
    }
    printf("NULL\n");
}

int main() {
    node *head = createhead();
    int choice, value;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at First\n");
        printf("2. Insert at Last\n");
        printf("3. Delete First\n");
        printf("4. Delete Last\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertfirst(head, value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertlast(head, value);
            break;
        case 3:
            deletefirst(head);
            break;
        case 4:
            deletelast(head);
            break;
        case 5:
            display(head);
            break;
        case 6:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
