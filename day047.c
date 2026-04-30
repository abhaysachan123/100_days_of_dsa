#include <stdio.h>
#include <stdlib.h>

/*
Problem: Height of Binary Tree

Input:
- First line: integer N
- Second line: level-order traversal (-1 represents NULL)

Output:
- Print height of the binary tree
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

int height(struct Node* root) {
    if(root == NULL) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return (l > r ? l : r) + 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if(n == 0 || arr[0] == -1) {
        printf("0");
        return 0;
    }

    struct Node* nodes[n];

    for(int i = 0; i < n; i++) {
        if(arr[i] != -1)
            nodes[i] = newNode(arr[i]);
        else
            nodes[i] = NULL;
    }

    for(int i = 0; i < n; i++) {
        if(nodes[i]) {
            int l = 2*i + 1;
            int r = 2*i + 2;
            if(l < n) nodes[i]->left = nodes[l];
            if(r < n) nodes[i]->right = nodes[r];
        }
    }

    printf("%d", height(nodes[0]));

    return 0;
}