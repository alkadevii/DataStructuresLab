#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Expression tree node
typedef struct Node {
    char data[10];              // store operand or operator as string
    struct Node *left, *right;
} Node;

// Stack node (linked list)
typedef struct StackNode {
    Node *treeNode;
    struct StackNode *next;
} StackNode;

// Create a new expression tree node
Node* newNode(char *data) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->data, data);
    node->left = node->right = NULL;
    return node;
}

// Push a tree node onto stack
void push(StackNode **top, Node *t) {
    StackNode *temp = (StackNode*)malloc(sizeof(StackNode));
    temp->treeNode = t;
    temp->next = *top;
    *top = temp;
}

// Pop a tree node from stack
Node* pop(StackNode **top) {
    if (*top == NULL) return NULL;
    StackNode *temp = *top;
    Node *res = temp->treeNode;
    *top = temp->next;
    free(temp);
    return res;
}

// Check if operator
int isOperator(char *c) {
    return (strcmp(c, "+") == 0 || strcmp(c, "-") == 0 ||
            strcmp(c, "*") == 0 || strcmp(c, "/") == 0 ||
            strcmp(c, "^") == 0);
}

// Build expression tree from postfix string
Node* buildExpressionTree(char postfix[]) {
    StackNode *stack = NULL;
    char token[10];
    int i = 0, j = 0;

    while (postfix[i] != '\0') {
        // Skip spaces
        if (isspace(postfix[i])) {
            i++;
            continue;
        }

        j = 0;
        // Extract token (number or operator)
        while (postfix[i] != '\0' && !isspace(postfix[i])) {
            token[j++] = postfix[i++];
        }
        token[j] = '\0';

        if (!isOperator(token)) {
            // Operand
            push(&stack, newNode(token));
        } else {
            // Operator
            Node *t = newNode(token);
            t->right = pop(&stack);
            t->left = pop(&stack);
            push(&stack, t);
        }
    }

    return pop(&stack);
}

// Inorder (Infix)
void inorder(Node *root) {
    if (root) {
        if (isOperator(root->data)) printf("(");
        inorder(root->left);
        printf("%s", root->data);
        inorder(root->right);
        if (isOperator(root->data)) printf(")");
    }
}

// Preorder (Prefix)
void preorder(Node *root) {
    if (root) {
        printf("%s ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder (Postfix)
void postorder(Node *root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%s ", root->data);
    }
}

int main() {
    char postfix[200];

    printf("Enter postfix expression (space-separated): ");
    fgets(postfix, sizeof(postfix), stdin);
    postfix[strcspn(postfix, "\n")] = 0; // remove newline

    Node *root = buildExpressionTree(postfix);

    printf("\nInfix   : ");
    inorder(root);
    printf("\nPrefix  : ");
    preorder(root);
    printf("\nPostfix : ");
    postorder(root);
    printf("\n");

    return 0;
}
