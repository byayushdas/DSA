#include <stdio.h>
#define MAX 100

int main() {
    int n, m, A[MAX][MAX], x;

    printf("Enter rows and columns: ");
    scanf("%d %d", &n, &m);

    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &A[i][j]);

    printf("Enter element to search: ");
    scanf("%d", &x);

    int low = 0, high = n*m - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        int row = mid / m;
        int col = mid % m;

        if (A[row][col] == x) {
            printf("Found at (%d,%d)\n", row, col);
            return 0;
        } 
        else if (A[row][col] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("Not found\n");
    return 0;
}