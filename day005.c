// Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

// Input:
// - First line: integer p (number of entries in server log 1)
// - Second line: p sorted integers representing arrival times from server 1
// - Third line: integer q (number of entries in server log 2)
// - Fourth line: q sorted integers representing arrival times from server 2)

// Output:
// - Print a single line containing all arrival times in chronological order, separated by spaces

// Example:
// Input:
// 5
// 10 20 30 50 70
// 4
// 15 25 40 60

// Output:
// 10 15 20 25 30 40 50 60 70

// Explanation: Compare the next unprocessed arrival time from both logs and append the earlier one to the final log until all entries are processed

# Input
p = int(input())
log1 = list(map(int, input().split()))

q = int(input())
log2 = list(map(int, input().split()))

# Merge process
i, j = 0, 0
merged_log = []

while i < p and j < q:
    if log1[i] <= log2[j]:
        merged_log.append(log1[i])
        i += 1
    else:
        merged_log.append(log2[j])
        j += 1

# Add remaining elements
while i < p:
    merged_log.append(log1[i])
    i += 1

while j < q:
    merged_log.append(log2[j])
    j += 1

# Output
print(*merged_log)