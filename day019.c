#include <stdio.h>
#include <stdlib.h>

/*
Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, 
which is the closest to zero compared to other pairs.
*/

// Comparator for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;

    // Input size
    scanf("%d", &n);
    int arr[n];

    // Input array
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort array
    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int min_sum = arr[left] + arr[right];
    int best_l = left, best_r = right;

    // Two-pointer approach
    while(left < right) {
        int sum = arr[left] + arr[right];

        if(abs(sum) < abs(min_sum)) {
            min_sum = sum;
            best_l = left;
            best_r = right;
        }

        if(sum < 0)
            left++;
        else
            right--;
    }

    // Output pair
    printf("%d %d", arr[best_l], arr[best_r]);

    return 0;
}