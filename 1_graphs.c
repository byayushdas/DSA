#include <stdio.h>

#define MAX 100
#define INF 9999

int adj[MAX][MAX], cost[MAX][MAX];
int visited[MAX], parent[MAX];
int n;

// ---------------- DFS ----------------
void DFS(int v) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            DFS(i);
        }
    }
}

// ---------------- BFS ----------------
void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (adj[v][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

// ---------------- Prim ----------------
void prim() {
    int visited[MAX] = {0};
    int edges = 0, minCost = 0;

    visited[0] = 1;

    printf("\nPrim's MST:\n");

    while (edges < n - 1) {
        int min = INF, a = -1, b = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if (a != -1 && b != -1) {
            printf("Edge %d - %d : %d\n", a, b, min);
            minCost += min;
            visited[b] = 1;
            edges++;
        }
    }

    printf("Total Cost = %d\n", minCost);
}

// ---------------- Find (Kruskal) ----------------
int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

// ---------------- Union ----------------
void union_set(int i, int j) {
    parent[j] = i;
}

// ---------------- Kruskal ----------------
void kruskal() {
    int edges = 0, minCost = 0;

    printf("\nKruskal's MST:\n");

    while (edges < n - 1) {
        int min = INF, a = -1, b = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        int u = find(a);
        int v = find(b);

        if (u != v) {
            printf("Edge %d - %d : %d\n", a, b, min);
            minCost += min;
            union_set(u, v);
            edges++;
        }

        cost[a][b] = cost[b][a] = INF;
    }

    printf("Total Cost = %d\n", minCost);
}

// ---------------- MAIN ----------------
int main() {
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter adjacency matrix (0/1 for BFS & DFS):\n");
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("\nEnter cost matrix (9999 for no edge):\n");
    for (int i = 0; i < n; i++) {
        parent[i] = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("\nEnter starting vertex: ");
    scanf("%d", &start);

    // DFS
    printf("\nDFS Traversal: ");
    DFS(start);

    // Reset visited
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // BFS
    printf("\nBFS Traversal: ");
    BFS(start);

    // Prim
    prim();

    // Re-input cost matrix for Kruskal (since Prim modified it)
    printf("\nRe-enter cost matrix for Kruskal:\n");
    for (int i = 0; i < n; i++) {
        parent[i] = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Kruskal
    kruskal();

    return 0;
}