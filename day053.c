#include <stdio.h>
#include <stdlib.h>

/*
Problem Statement:
Given a binary tree, print its vertical order traversal.

Input Format:
- First line: integer N
- Second line: level-order traversal (-1 represents NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line
*/

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Pair {
    struct Node* node;
    int hd;
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

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    if(!root) return 0;

    struct Pair queue[1000];
    int front = 0, rear = -1;

    int hdArr[1000];
    int valArr[1000];
    int idx = 0;

    queue[++rear] = (struct Pair){root, 0};

    while(front <= rear) {
        struct Pair p = queue[front++];

        hdArr[idx] = p.hd;
        valArr[idx] = p.node->data;
        idx++;

        if(p.node->left)
            queue[++rear] = (struct Pair){p.node->left, p.hd - 1};

        if(p.node->right)
            queue[++rear] = (struct Pair){p.node->right, p.hd + 1};
    }

    for(int i = 0; i < idx - 1; i++) {
        for(int j = i + 1; j < idx; j++) {
            if(hdArr[i] > hdArr[j]) {
                int t = hdArr[i]; hdArr[i] = hdArr[j]; hdArr[j] = t;
                t = valArr[i]; valArr[i] = valArr[j]; valArr[j] = t;
            }
        }
    }

    int prev = hdArr[0];

    for(int i = 0; i < idx; i++) {
        if(i == 0 || hdArr[i] != prev) {
            if(i != 0) printf("\n");
            printf("%d", valArr[i]);
            prev = hdArr[i];
        } else {
            printf(" %d", valArr[i]);
        }
    }

    return 0;
}