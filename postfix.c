#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

// Stack for characters (used in infix to postfix)
char opStack[MAX];
int opTop = -1;

// Stack for integers (used in evaluation)
int valStack[MAX];
int valTop = -1;

// Operator stack functions
void pushChar(char c) {
    opStack[++opTop] = c;
}

char popChar() {
    return opStack[opTop--];
}

char peekChar() {
    return opStack[opTop];
}

int isOpStackEmpty() {
    return opTop == -1;
}

// Value stack functions
void pushInt(int val) {
    valStack[++valTop] = val;
}

int popInt() {
    return valStack[valTop--];
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Convert infix to postfix and store in `postfix`
void infixToPostfix(char *infix, char *postfix) {
    int i = 0, j = 0;
    char c;

    while ((c = infix[i++]) != '\0') {
        if (isdigit(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            pushChar(c);
        } else if (c == ')') {
            while (!isOpStackEmpty() && peekChar() != '(') {
                postfix[j++] = popChar();
            }
            popChar(); // Remove '('
        } else if (isOperator(c)) {
            while (!isOpStackEmpty() && precedence(peekChar()) >= precedence(c) && peekChar() != '(') {
                postfix[j++] = popChar();
            }
            pushChar(c);
        }
    }

    while (!isOpStackEmpty()) {
        postfix[j++] = popChar();
    }

    postfix[j] = '\0';
}

// Evaluate postfix expression
int evaluatePostfix(char *postfix) {
    int i = 0;
    char c;
    int a, b, result;

    while ((c = postfix[i++]) != '\0') {
        if (isdigit(c)) {
            pushInt(c - '0');  // convert char digit to int
        } else {
            b = popInt();
            a = popInt();
            switch (c) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                case '^': result = pow(a, b); break;
            }
            pushInt(result);
        }
    }

    return popInt();
}

int main() {
    char infix[100], postfix[100];

    printf("Enter infix expression (e.g., 3+(4*2)): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
