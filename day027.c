#include <stdio.h>
#include <stdlib.h>

/*
Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously.
First common node is intersection.
*/

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;

    for(int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if(head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Get length of list
int getLength(struct Node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Find intersection by value (as per given input style)
int findIntersection(struct Node* h1, struct Node* h2) {
    int len1 = getLength(h1);
    int len2 = getLength(h2);

    int diff = abs(len1 - len2);

    // Move pointer of longer list
    if(len1 > len2) {
        for(int i = 0; i < diff; i++)
            h1 = h1->next;
    } else {
        for(int i = 0; i < diff; i++)
            h2 = h2->next;
    }

    // Traverse together
    while(h1 != NULL && h2 != NULL) {
        if(h1->data == h2->data) {
            return h1->data;
        }
        h1 = h1->next;
        h2 = h2->next;
    }

    return -1; // No intersection
}

int main() {
    int n, m;

    // Input lists
    scanf("%d", &n);
    struct Node* list1 = createList(n);

    scanf("%d", &m);
    struct Node* list2 = createList(m);

    int result = findIntersection(list1, list2);

    if(result != -1)
        printf("%d", result);
    else
        printf("No Intersection");

    return 0;
}