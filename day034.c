#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.
*/

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    struct Node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

int main() {
    char expr[200];
    fgets(expr, sizeof(expr), stdin);

    struct Node* stack = NULL;

    char* token = strtok(expr, " \n");

    while(token != NULL) {
        if(isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&stack, atoi(token));
        } else {
            int b = pop(&stack);
            int a = pop(&stack);
            int res;

            switch(token[0]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }

            push(&stack, res);
        }
        token = strtok(NULL, " \n");
    }

    printf("%d", pop(&stack));

    return 0;
}