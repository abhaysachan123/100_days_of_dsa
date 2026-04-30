#include <stdio.h>

/*
Problem: Given a sorted array of n integers, remove duplicates in-place. 
Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated

Example:
Input:
6
1 1 2 2 3 3

Output:
1 2 3

Explanation: Keep first occurrence of each element: 1, 2, 3
*/

int main() {
    int n;

    // Input size
    scanf("%d", &n);
    int arr[n];

    // Input array
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Edge case
    if(n == 0) return 0;

    // First element is always unique
    printf("%d ", arr[0]);

    // Traverse and print unique elements
    for(int i = 1; i < n; i++) {
        if(arr[i] != arr[i - 1]) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}