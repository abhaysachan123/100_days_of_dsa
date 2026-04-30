#include <stdio.h>
#include <stdlib.h>

/*
Problem: Build a graph with adjacency list representation.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- Adjacency list of each vertex
*/

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->next = NULL;
    return node;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    for(int i = 0; i < n; i++)
        adj[i] = NULL;

    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* temp = newNode(v);
        temp->next = adj[u];
        adj[u] = temp;

        temp = newNode(u);
        temp->next = adj[v];
        adj[v] = temp;
    }

    for(int i = 0; i < n; i++) {
        printf("%d:", i);
        struct Node* temp = adj[i];
        while(temp) {
            printf(" %d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}