#include <stdio.h>

/*
Problem Statement:
Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO

Example:
Input:
7
1 3 5 7 9 8 10

Output:
YES
*/

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < n && arr[i] > arr[left]) {
            printf("NO");
            return 0;
        }

        if(right < n && arr[i] > arr[right]) {
            printf("NO");
            return 0;
        }
    }

    printf("YES");
    return 0;
}