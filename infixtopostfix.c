#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int top = -1;
char *stack;
int size;

// Stack for characters (used in infix to postfix)
void createCharStack(int s) {
    size = s;
    stack = (char *)malloc(sizeof(char) * size);
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == size - 1;
}

void push(char ch) {
    if (isFull()) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = ch;
    }
}

char pop() {
    if (isEmpty()) {
        return '\0';
    } else {
        return stack[top--];
    }
}

char peek() {
    if (isEmpty()) {
        return '\0';
    } else {
        return stack[top];
    }
}

// Precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Infix to Postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isdigit(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        } else { // operator
            while (!isEmpty() && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

// Evaluate Postfix
int evaluatePostfix(char postfix[]) {
    int *numStack = (int *)malloc(sizeof(int) * size);
    int numTop = -1;
    char ch;
    int i, op1, op2;

    for (i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];

        if (isdigit(ch)) {
            numStack[++numTop] = ch - '0';
        } else {
            op2 = numStack[numTop--];
            op1 = numStack[numTop--];

            switch (ch) {
                case '+': numStack[++numTop] = op1 + op2; break;
                case '-': numStack[++numTop] = op1 - op2; break;
                case '*': numStack[++numTop] = op1 * op2; break;
                case '/': numStack[++numTop] = op1 / op2; break;
            }
        }
    }

    int result = numStack[numTop];
    free(numStack);
    return result;
}

int main() {
    char infix[100], postfix[100];

    printf("Enter the maximum size for stack: ");
    scanf("%d", &size);
    createCharStack(size);

    printf("Enter infix expression (single digit numbers, no spaces): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Evaluation Result: %d\n", result);

    free(stack);
    return 0;
}