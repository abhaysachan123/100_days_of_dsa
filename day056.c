#include <stdio.h>
#include <stdlib.h>

/*
Problem Statement:
Check whether a given binary tree is symmetric around its center.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print YES if symmetric, otherwise NO

Example:
Input:
7
1 2 2 3 4 4 3

Output:
YES
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

    for(int i = 0; i < n; i++) {
        nodes[i] = (arr[i] == -1) ? NULL : newNode(arr[i]);
    }

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

int isMirror(struct Node* a, struct Node* b) {
    if(a == NULL && b == NULL) return 1;
    if(a == NULL || b == NULL) return 0;

    return (a->data == b->data) &&
           isMirror(a->left, b->right) &&
           isMirror(a->right, b->left);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    if(isMirror(root, root))
        printf("YES");
    else
        printf("NO");

    return 0;
}