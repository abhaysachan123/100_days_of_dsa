#include <stdio.h>
#include <stdlib.h>

/*
Problem: BST Search

Input:
- First line: integer N
- Second line: N space-separated integers (BST insertion order)
- Third line: key to search

Output:
- Print "Found" if key exists, otherwise "Not Found"
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

struct Node* insert(struct Node* root, int val) {
    if(root == NULL) return newNode(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

int search(struct Node* root, int key) {
    if(root == NULL) return 0;
    if(root->data == key) return 1;

    if(key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* root = NULL;

    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    int key;
    scanf("%d", &key);

    if(search(root, key))
        printf("Found");
    else
        printf("Not Found");

    return 0;
}