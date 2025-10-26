#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *link;
} node;

// Create head node
node* createHead() {
    node *head = malloc(sizeof(node));
    head->link = NULL;
    return head;
}

// Create new node
node* createNode(int data) {
    node *newnode = malloc(sizeof(node));
    newnode->value = data;
    newnode->link = NULL;
    return newnode;
}

// Insert at beginning
void insertFirst(node *head, int data) {
    node *newnode = createNode(data);
    newnode->link = head->link;
    head->link = newnode;
    printf("Inserted %d at beginning.\n", data);
}

// Insert at end
void insertLast(node *head, int data) {
    node *newnode = createNode(data);
    node *current = head;

    while (current->link != NULL) {
        current = current->link;
    }
    current->link = newnode;
    printf("Inserted %d at end.\n", data);
}

// Delete first node
void deleteFirst(node *head) {
    if (head->link == NULL) {
        printf("List is empty.\n");
        return;
    }
    node *temp = head->link;
    head->link = temp->link;
    printf("Deleted first node: %d\n", temp->value);
    free(temp);
}

// Delete last node
void deleteLast(node *head) {
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
    printf("Deleted last node: %d\n", current->value);
    free(current);
}

// Display list
void display(node *head) {
    if (head->link == NULL) {
        printf("List is empty.\n");
        return;
    }

    node *current = head->link;
    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->link;
    }
    printf("NULL\n");
}

// Reverse linked list
void reverseList(node *head) {
    node *prev = NULL, *current = head->link, *next = NULL;

    while (current != NULL) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    head->link = prev;
    printf("List reversed successfully.\n");
}

void sortList(node *head){
    if (head->link == NULL || head->link->link == NULL) {
        printf("List is too short to sort.\n");
        return;
    }

    while(1){
        int flag=0;
        node* current=head->link;
        while(current->link!=NULL){
            if (current->value>current->link->value){
                int temp=current->value;
                current->value=current->link->value;
                current->link->value=temp;
                flag=1;
            }
             current=current->link;
        }
        if (flag==0){
                break;
            }
    }
    printf("List sorted in ascending order.\n");
}

// Main function
int main() {
    node* head = createHead();
    int choice, value;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at First\n");
        printf("2. Insert at Last\n");
        printf("3. Delete First\n");
        printf("4. Delete Last\n");
        printf("5. Display\n");
        printf("6. Reverse\n");
        printf("7. Sort\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertFirst(head, value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertLast(head, value);
            break;
        case 3:
            deleteFirst(head);
            break;
        case 4:
            deleteLast(head);
            break;
        case 5:
            display(head);
            break;
        case 6:
            reverseList(head);
            break;
        case 7:
            sortList(head);
            break;
        case 8:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}
