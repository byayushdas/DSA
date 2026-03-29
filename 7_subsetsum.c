#include <stdio.h>
#include <string.h>

// ---------------- 1. Recursive ----------------
int subsetRecursive(int arr[], int n, int sum) {
    if (sum == 0) return 1;
    if (n == 0) return 0;

    if (arr[n-1] > sum)
        return subsetRecursive(arr, n-1, sum);

    return subsetRecursive(arr, n-1, sum) ||
           subsetRecursive(arr, n-1, sum - arr[n-1]);
}

// ---------------- 2. Memoization ----------------
int dp[100][100];

int subsetMemo(int arr[], int n, int sum) {
    if (sum == 0) return 1;
    if (n == 0) return 0;

    if (dp[n][sum] != -1)
        return dp[n][sum];

    if (arr[n-1] > sum)
        return dp[n][sum] = subsetMemo(arr, n-1, sum);

    return dp[n][sum] =
        subsetMemo(arr, n-1, sum) ||
        subsetMemo(arr, n-1, sum - arr[n-1]);
}

// ---------------- 3. Tabulation ----------------
int subsetDP(int arr[], int n, int sum) {
    int dp[n+1][sum+1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int j = 1; j <= sum; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
        }
    }

    return dp[n][sum];
}

// ---------------- 4. Backtracking (Print subsets) ----------------
void printSubset(int subset[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++)
        printf("%d ", subset[i]);
    printf("}\n");
}

void subsetBacktrack(int arr[], int n, int sum, int index, int subset[], int size) {
    if (sum == 0) {
        printSubset(subset, size);
        return;
    }

    if (index == n || sum < 0)
        return;

    // Include
    subset[size] = arr[index];
    subsetBacktrack(arr, n, sum - arr[index], index + 1, subset, size + 1);

    // Exclude
    subsetBacktrack(arr, n, sum, index + 1, subset, size);
}

// ---------------- MAIN ----------------
int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int n = 6, sum = 9;

    printf("Recursive: ");
    if (subsetRecursive(arr, n, sum))
        printf("Subset exists\n");
    else
        printf("No subset\n");

    printf("Memoization: ");
    memset(dp, -1, sizeof(dp));
    if (subsetMemo(arr, n, sum))
        printf("Subset exists\n");
    else
        printf("No subset\n");

    printf("Tabulation: ");
    if (subsetDP(arr, n, sum))
        printf("Subset exists\n");
    else
        printf("No subset\n");

    printf("\nBacktracking (All subsets):\n");
    int subset[100];
    subsetBacktrack(arr, n, sum, 0, subset, 0);

    return 0;
}