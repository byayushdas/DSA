#include <stdio.h>
#include <limits.h>

#define MAX 100

int dp[MAX][MAX];  // for memoization

// ---------------- PURE RECURSION ----------------
int mcm_recursive(int arr[], int i, int j) {
    if (i == j)
        return 0;

    int min = INT_MAX;

    for (int k = i; k < j; k++) {
        int cost = mcm_recursive(arr, i, k)
                 + mcm_recursive(arr, k + 1, j)
                 + arr[i - 1] * arr[k] * arr[j];

        if (cost < min)
            min = cost;
    }

    return min;
}

// ---------------- MEMOIZATION ----------------
int mcm_memo(int arr[], int i, int j) {
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int min = INT_MAX;

    for (int k = i; k < j; k++) {
        int cost = mcm_memo(arr, i, k)
                 + mcm_memo(arr, k + 1, j)
                 + arr[i - 1] * arr[k] * arr[j];

        if (cost < min)
            min = cost;
    }

    return dp[i][j] = min;
}

// ---------------- TABULATION ----------------
int mcm_tabulation(int arr[], int n) {
    int m[MAX][MAX];

    // cost is 0 when multiplying one matrix
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // L = chain length
    for (int L = 2; L < n; L++) {
        // i, j formula for indexes above diagonal
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j]
                         + arr[i - 1] * arr[k] * arr[j];

                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }
    //cost of multiplying from A₁ to Aₙ
    return m[1][n - 1];
}

// ---------------- MAIN ----------------
int main() {
    int n, arr[MAX];

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter dimensions array (size %d):\n", n + 1);
    for (int i = 0; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize dp array for memoization
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            dp[i][j] = -1;
        }
    }

    printf("\nMinimum Cost (Recursion): %d\n",
           mcm_recursive(arr, 1, n));

    printf("Minimum Cost (Memoization): %d\n",
           mcm_memo(arr, 1, n));

    printf("Minimum Cost (Tabulation): %d\n",
           mcm_tabulation(arr, n + 1));

    return 0;
}