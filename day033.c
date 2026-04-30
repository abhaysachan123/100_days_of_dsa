#include <stdio.h>
#include <ctype.h>

#define MAX 100

/*
Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity
*/

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char c) {
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    if(c == '^') return 3;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, k = 0;

    scanf("%s", infix);

    for(i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if(isalnum(c)) {
            postfix[k++] = c;
        }
        else if(c == '(') {
            push(c);
        }
        else if(c == ')') {
            while(top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop();
        }
        else {
            while(top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    while(top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("%s", postfix);

    return 0;
}