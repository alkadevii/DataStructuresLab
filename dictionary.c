#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char word[50];
    char meaning[200];
    struct node *lchild, *rchild;
};

struct node *root = NULL;

// Function to create a new node
struct node* createNode(char *word, char *meaning) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    strcpy(newNode->word, word);
    strcpy(newNode->meaning, meaning);
    newNode->lchild = newNode->rchild = NULL;
    return newNode;
}

// Function to insert a word-meaning pair
struct node* insert(struct node *root, char *word, char *meaning) {
    if (root == NULL)
        return createNode(word, meaning);

    if (strcmp(word, root->word) < 0)
        root->lchild = insert(root->lchild, word, meaning);
    else if (strcmp(word, root->word) > 0)
        root->rchild = insert(root->rchild, word, meaning);
    else
        printf("\nWord already exists in the dictionary!\n");

    return root;
}

// Function to search for a word
void search(struct node *root, char *word) {
    if (root == NULL) {
        printf("\nWord not found in dictionary.\n");
        return;
    }

    if (strcmp(word, root->word) == 0) {
        printf("\nMeaning of '%s' : %s\n", root->word, root->meaning);
        return;
    }

    if (strcmp(word, root->word) < 0)
        search(root->lchild, word);
    else
        search(root->rchild, word);
}

// Function to display dictionary (in alphabetical order)
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->lchild);
        printf("\nWord: %s\nMeaning: %s\n", root->word, root->meaning);
        inorder(root->rchild);
    }
}

int main() {
    int ch;
    char word[50], meaning[200];

    while (1) {
        printf("\n---- DICTIONARY MENU ----");
        printf("\n1. Insert a Word");
        printf("\n2. Search a Word");
        printf("\n3. Display Dictionary (Inorder)");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        getchar(); // clear newline

        switch (ch) {
            case 1:
                printf("\nEnter Word: ");
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = 0;

                printf("Enter Meaning: ");
                fgets(meaning, sizeof(meaning), stdin);
                meaning[strcspn(meaning, "\n")] = 0;

                root = insert(root, word, meaning);
                break;

            case 2:
                printf("\nEnter Word to Search: ");
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = 0;
                search(root, word);
                break;

            case 3:
                printf("\n--- Dictionary Contents ---\n");
                inorder(root);
                break;

            case 4:
                printf("\nExiting the program.\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
