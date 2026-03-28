#include <stdio.h>
#include <string.h>

// ---------------- 1. Recursive ----------------
int knapsackRecursive(int wt[], int val[], int n, int W) {
    if (n == 0 || W == 0)
        return 0;

    if (wt[n-1] > W)
        return knapsackRecursive(wt, val, n-1, W);

    int include = val[n-1] + knapsackRecursive(wt, val, n-1, W - wt[n-1]);
    int exclude = knapsackRecursive(wt, val, n-1, W);

    return (include > exclude) ? include : exclude;
}

// ---------------- 2. Memoization ----------------
int dp[100][100];

int knapsackMemo(int wt[], int val[], int n, int W) {
    if (n == 0 || W == 0)
        return 0;

    if (dp[n][W] != -1)
        return dp[n][W];

    if (wt[n-1] > W)
        return dp[n][W] = knapsackMemo(wt, val, n-1, W);

    int include = val[n-1] + knapsackMemo(wt, val, n-1, W - wt[n-1]);
    int exclude = knapsackMemo(wt, val, n-1, W);

    return dp[n][W] = (include > exclude) ? include : exclude;
}

// ---------------- 3. Tabulation ----------------
int knapsackDP(int wt[], int val[], int n, int W) {
    int dp[n+1][W+1];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (wt[i-1] <= j) {
                int include = val[i-1] + dp[i-1][j - wt[i-1]];
                int exclude = dp[i-1][j];
                dp[i][j] = (include > exclude) ? include : exclude;
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }

    return dp[n][W];
}

// ---------------- 4. Backtracking (Print chosen items) ----------------
void printItems(int wt[], int val[], int n, int W) {
    int dp[n+1][W+1];

    // Build DP table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (wt[i-1] <= j) {
                int include = val[i-1] + dp[i-1][j - wt[i-1]];
                int exclude = dp[i-1][j];
                dp[i][j] = (include > exclude) ? include : exclude;
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    printf("Items selected (wt, val):\n");

    int i = n, j = W;

    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i-1][j]) {
            printf("(%d, %d)\n", wt[i-1], val[i-1]);
            j -= wt[i-1];
        }
        i--;
    }
}

// ---------------- MAIN ----------------
int main() {
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int n = 4;
    int W = 7;

    printf("Recursive: %d\n", knapsackRecursive(wt, val, n, W));

    memset(dp, -1, sizeof(dp));
    printf("Memoization: %d\n", knapsackMemo(wt, val, n, W));

    printf("Tabulation: %d\n", knapsackDP(wt, val, n, W));

    printf("\nBacktracking:\n");
    printItems(wt, val, n, W);

    return 0;
}