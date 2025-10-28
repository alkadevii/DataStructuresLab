#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int top = -1;
char *stack;
int size;

// Stack for characters
void createCharStack(int s) {
    size = s;
    stack = (char *)malloc(sizeof(char) * size);
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

int isEmpty() { return top == -1; }
int isFull() { return top == size - 1; }

void push(char ch) {
    if (isFull()) printf("Stack overflow\n");
    else stack[++top] = ch;
}

char pop() {
    if (isEmpty()) return '\0';
    else return stack[top--];
}

char peek() {
    if (isEmpty()) return '\0';
    else return stack[top];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Infix → Postfix conversion
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {
        if (isdigit(ch)) {
            while (isdigit(ch)) {
                postfix[j++] = ch;
                ch = infix[i++];
            }
            postfix[j++] = ' ';
            i--;
        }
        else if (ch == '(') push(ch);
        else if (ch == ')') {
            while (!isEmpty() && peek() != '(')
                postfix[j++] = pop();
            pop(); // remove '('
        }
        else { // operator
            while (!isEmpty() &&((precedence(peek()) > precedence(ch)) ||
            (precedence(peek()) == precedence(ch) && ch != '^')))
             postfix[j++] = pop();
            
            push(ch);
        }
    }

    while (!isEmpty())
        postfix[j++] = pop();

    postfix[j] = '\0';
}

// Evaluate postfix expression
int evaluatePostfix(char postfix[]) {
    int numStack[100];
    int numTop = -1;
    char token[20];
    int i = 0, k;

    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            k = 0;
            while (isdigit(postfix[i]))
                token[k++] = postfix[i++];
            token[k] = '\0';
            numStack[++numTop] = atoi(token);
        } else if (postfix[i] != ' ') {
            int op2 = numStack[numTop--];
            int op1 = numStack[numTop--];
            switch (postfix[i]) {
                case '+': numStack[++numTop] = op1 + op2; break;
                case '-': numStack[++numTop] = op1 - op2; break;
                case '*': numStack[++numTop] = op1 * op2; break;
                case '/': numStack[++numTop] = op1 / op2; break;
                case '^': numStack[++numTop] = pow(op1, op2); break;
            }
        }
        i++;
    }

    return numStack[numTop];
}

int main() {
    char infix[100], postfix[100];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    createCharStack(strlen(infix));
    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);
    printf("Result: %d\n", evaluatePostfix(postfix));

    free(stack);
    return 0;
}
