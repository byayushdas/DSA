#include <stdio.h>

#define MAX 10
#define INF 9999

int n;
int cost[MAX][MAX];
int visited[MAX];
int minCost = INF;

// -------- TSP using DP-style recursion --------
void tsp(int city, int count, int currCost) {
    if (count == n && cost[city][0] > 0) {
        int total = currCost + cost[city][0];
        if (total < minCost)
            minCost = total;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && cost[city][i] > 0) {
            visited[i] = 1;
            tsp(i, count + 1, currCost + cost[city][i]);
            visited[i] = 0;  // backtrack
        }
    }
}

// -------- MAIN --------
int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    visited[0] = 1; // start from city 0
    tsp(0, 1, 0);

    printf("Minimum TSP Cost = %d\n", minCost);

    return 0;
}