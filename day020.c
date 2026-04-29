#include <stdio.h>

/*
Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero

Example:
Input:
6
1 -1 2 -2 3 -3

Output:
6

Explanation:
A subarray is a continuous part of the array. 
Subarrays with sum zero:
[1, -1], [2, -2], [3, -3], 
[1, -1, 2, -2], 
[2, -2, 3, -3], 
[1, -1, 2, -2, 3, -3]
*/

// Brute-force approach
int main() {
    int n;

    // Input size
    scanf("%d", &n);
    int arr[n];

    // Input array
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;

    // Check all subarrays
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            if(sum == 0) {
                count++;
            }
        }
    }

    // Output
    printf("%d", count);

    return 0;
}