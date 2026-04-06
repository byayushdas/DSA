#include <stdio.h>

#define MAX 20

int board[MAX];
int n;

// -------- Check if safe --------
int isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        // same column or diagonal
        if (board[i] == col || 
            board[i] - i == col - row || 
            board[i] + i == col + row)
            return 0;
    }
    return 1;
}

// -------- Print solution --------
void printSolution() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

// -------- Solve N-Queen --------
void solve(int row) {
    if (row == n) {
        printSolution();
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solve(row + 1);
        }
    }
}

// -------- MAIN --------
int main() {
    printf("Enter number of queens: ");
    scanf("%d", &n);

    solve(0);

    return 0;
}