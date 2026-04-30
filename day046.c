#include <stdio.h>
#include <stdlib.h>

/*
Problem: Level Order Traversal

Input:
- First line: integer N
- Second line: level-order traversal (-1 represents NULL)

Output:
- Print level order traversal of the tree
*/

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* queue[1000];
int front = 0, rear = -1;

void enqueue(struct Node* node) {
    queue[++rear] = node;
}

struct Node* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if(n == 0 || arr[0] == -1) return 0;

    struct Node* nodes[n];

    for(int i = 0; i < n; i++) {
        if(arr[i] != -1)
            nodes[i] = newNode(arr[i]);
        else
            nodes[i] = NULL;
    }

    for(int i = 0; i < n; i++) {
        if(nodes[i] != NULL) {
            int left = 2*i + 1;
            int right = 2*i + 2;

            if(left < n) nodes[i]->left = nodes[left];
            if(right < n) nodes[i]->right = nodes[right];
        }
    }

    struct Node* root = nodes[0];

    enqueue(root);

    while(!isEmpty()) {
        struct Node* curr = dequeue();
        printf("%d ", curr->data);

        if(curr->left) enqueue(curr->left);
        if(curr->right) enqueue(curr->right);
    }

    return 0;
}