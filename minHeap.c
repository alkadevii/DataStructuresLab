#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int heap[MAX];
int size = 0;

// Swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insert an element into min heap
void insert(int value) {
    if (size == MAX) {
        printf("Heap Overflow! Cannot insert %d\n", value);
        return;
    }

    int i = size;
    heap[size++] = value;

    // Bubble up (reheapify)
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }

    printf("%d inserted into heap.\n", value);
}

// Heapify down (after deletion)
void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Delete minimum element (root)
int deleteMin() {
    if (size <= 0) {
        printf("Heap Underflow! Nothing to delete.\n");
        return -1;
    }

    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);

    printf("%d deleted from heap.\n", root);
    return root;
}

// Display heap elements
void printHeap() {
    if (size == 0) {
        printf("Heap is empty.\n");
        return;
    }

    printf("Heap elements: ");
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

// Main driver function
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Min Heap Menu ---\n");
        printf("1. Insert Element\n");
        printf("2. Delete Minimum\n");
        printf("3. Display Heap\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                deleteMin();
                break;

            case 3:
                printHeap();
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
