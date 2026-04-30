#include <stdio.h>
#include <stdlib.h>

/*
Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6
*/

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

struct Node* buildTree(int arr[], int n) {
    struct Node* nodes[n];
    for(int i = 0; i < n; i++)
        nodes[i] = (arr[i] == -1) ? NULL : newNode(arr[i]);

    for(int i = 0; i < n; i++) {
        if(nodes[i]) {
            int l = 2*i + 1;
            int r = 2*i + 2;
            if(l < n) nodes[i]->left = nodes[l];
            if(r < n) nodes[i]->right = nodes[r];
        }
    }
    return nodes[0];
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    if(!root) return 0;

    struct Node* queue[1000];
    int front = 0, rear = -1;

    queue[++rear] = root;

    while(front <= rear) {
        int size = rear - front + 1;

        for(int i = 0; i < size; i++) {
            struct Node* curr = queue[front++];

            if(i == size - 1)
                printf("%d ", curr->data);

            if(curr->left) queue[++rear] = curr->left;
            if(curr->right) queue[++rear] = curr->right;
        }
    }

    return 0;
}