#include <stdio.h>
#include <string.h>

#define MAX 1000

/*
Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear.

Operations supported:
push_front x
push_back x
pop_front
pop_back
front
back
empty
size

Input:
- First line: integer n (number of operations)
- Next n lines: operations

Output:
- Print results of front, back, pop, empty, size operations
*/

int dq[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int getSize() {
    if (isEmpty()) return 0;
    return rear - front + 1;
}

void push_front(int x) {
    if (front == -1) {
        front = rear = MAX / 2;
        dq[front] = x;
    } else if (front > 0) {
        dq[--front] = x;
    }
}

void push_back(int x) {
    if (front == -1) {
        front = rear = MAX / 2;
        dq[rear] = x;
    } else if (rear < MAX - 1) {
        dq[++rear] = x;
    }
}

void pop_front() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }
    printf("%d\n", dq[front]);
    if (front == rear) front = rear = -1;
    else front++;
}

void pop_back() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }
    printf("%d\n", dq[rear]);
    if (front == rear) front = rear = -1;
    else rear--;
}

void getFront() {
    if (isEmpty()) printf("-1\n");
    else printf("%d\n", dq[front]);
}

void getBack() {
    if (isEmpty()) printf("-1\n");
    else printf("%d\n", dq[rear]);
}

int main() {
    int n;
    scanf("%d", &n);

    char op[20];

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (strcmp(op, "push_front") == 0) {
            int x;
            scanf("%d", &x);
            push_front(x);
        } else if (strcmp(op, "push_back") == 0) {
            int x;
            scanf("%d", &x);
            push_back(x);
        } else if (strcmp(op, "pop_front") == 0) {
            pop_front();
        } else if (strcmp(op, "pop_back") == 0) {
            pop_back();
        } else if (strcmp(op, "front") == 0) {
            getFront();
        } else if (strcmp(op, "back") == 0) {
            getBack();
        } else if (strcmp(op, "empty") == 0) {
            printf("%d\n", isEmpty());
        } else if (strcmp(op, "size") == 0) {
            printf("%d\n", getSize());
        }
    }

    return 0;
}