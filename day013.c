#include <stdio.h>

/*
Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, 
traverse the matrix in a clockwise manner and continue moving inward layer by layer 
until all elements are visited.

Input:
- First line: two integers r and c representing the number of rows and columns
- Next r lines: c integers each representing the matrix elements

Output:
- Print all visited elements in the order of traversal, separated by spaces

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
1 2 3 6 9 8 7 4 5

Explanation:
The traversal begins along the top row, proceeds down the rightmost column, 
then moves across the bottom row in reverse, and finally goes up the leftmost column. 
The same pattern repeats for the inner submatrix.
*/

int main() {
    int r, c;

    // Input dimensions
    scanf("%d %d", &r, &c);

    int arr[r][c];

    // Input matrix
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    // Spiral traversal
    while(top <= bottom && left <= right) {

        // Top row
        for(int i = left; i <= right; i++) {
            printf("%d ", arr[top][i]);
        }
        top++;

        // Right column
        for(int i = top; i <= bottom; i++) {
            printf("%d ", arr[i][right]);
        }
        right--;

        // Bottom row
        if(top <= bottom) {
            for(int i = right; i >= left; i--) {
                printf("%d ", arr[bottom][i]);
            }
            bottom--;
        }

        // Left column
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                printf("%d ", arr[i][left]);
            }
            left++;
        }
    }

    return 0;
}