#include <stdio.h>
#include <stdlib.h>

/*
Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list (given as edges: m followed by m pairs u v)
- starting vertex s

Output:
- DFS traversal order
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

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* temp = newNode(v);
    temp->next = adj[u];
    adj[u] = temp;

    temp = newNode(u);
    temp->next = adj[v];
    adj[v] = temp;
}

void dfs(int v, struct Node* adj[], int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];
    while(temp) {
        if(!visited[temp->data]) {
            dfs(temp->data, adj, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    for(int i = 0; i < n; i++) adj[i] = NULL;

    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int s;
    scanf("%d", &s);

    int visited[n];
    for(int i = 0; i < n; i++) visited[i] = 0;

    dfs(s, adj, visited);

    return 0;
}