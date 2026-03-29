#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF 99999

int graph[MAX][MAX];
int V;

// ---------------- DIJKSTRA ----------------
void dijkstra(int src) {
    int dist[MAX], visited[MAX] = {0};

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int min = INT_MAX, u = -1;

        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] <= min) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("\nDijkstra Result:\n");
    for (int i = 0; i < V; i++)
        printf("Distance from %d to %d = %d\n", src, i, dist[i]);
}

// ---------------- BELLMAN FORD ----------------
void bellmanFord(int src) {
    int dist[MAX];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    // Relax edges V-1 times
    for (int k = 0; k < V - 1; k++) {
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (graph[u][v] != 0 && dist[u] != INT_MAX &&
                    dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    // Check negative cycle
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                printf("\nGraph contains negative weight cycle!\n");
                return;
            }
        }
    }

    printf("\nBellman-Ford Result:\n");
    for (int i = 0; i < V; i++)
        printf("Distance from %d to %d = %d\n", src, i, dist[i]);
}

// ---------------- FLOYD WARSHALL ----------------
void floydWarshall() {
    int dist[MAX][MAX];

    // Initialize
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j)
                dist[i][j] = 0;
            else if (graph[i][j] != 0)
                dist[i][j] = graph[i][j];
            else
                dist[i][j] = INF;
        }
    }

    // Algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("\nFloyd-Warshall Result:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

// ---------------- MAIN ----------------
int main() {
    int choice, src;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    do {
        printf("\n--- MENU ---\n");
        printf("1. Dijkstra\n");
        printf("2. Bellman-Ford\n");
        printf("3. Floyd-Warshall\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter source vertex: ");
                scanf("%d", &src);
                dijkstra(src);
                break;

            case 2:
                printf("Enter source vertex: ");
                scanf("%d", &src);
                bellmanFord(src);
                break;

            case 3:
                floydWarshall();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}