#include <stdio.h>
#include <string.h>

/*
Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards
*/

int main() {
    char str[100];
    
    // Input
    scanf("%s", str);

    int left = 0;
    int right = strlen(str) - 1;
    int isPalindrome = 1;

    // Two-pointer comparison
    while(left < right) {
        if(str[left] != str[right]) {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }

    // Output
    if(isPalindrome)
        printf("YES");
    else
        printf("NO");

    return 0;
}