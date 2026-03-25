#include <stdio.h>
#define MAX 100
#define INF 99999

int minDist(int dist[], int spt[], int n) {
    int min = 1e9, idx = -1;
    for (int i = 0; i < n; i++)
        if (!spt[i] && dist[i] < min)
            min = dist[i], idx = i;
    return idx;
}

void printPath(int parent[], int v) {
    if (parent[v] == -1) {
        printf("%d ", v);
        return;
    }
    printPath(parent, parent[v]);
    printf("%d ", v);
}

int main() {
    int n, src;
    printf("Vertices: ");
    scanf("%d", &n);

    int g[MAX][MAX];

    printf("Matrix (99999=INF):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &g[i][j]);
            if (g[i][j] == 99999) g[i][j] = INF;
        }

    printf("Source: ");
    scanf("%d", &src);

    int dist[MAX], spt[MAX] = {0}, parent[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;   
    }

    dist[src] = 0;

    for (int c = 0; c < n-1; c++) {
        int u = minDist(dist, spt, n);
        if (u == -1) break;

        spt[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!spt[v] && g[u][v] < INF &&
                dist[u] + g[u][v] < dist[v]) {

                dist[v] = dist[u] + g[u][v];
                parent[v] = u;  
            }
        }
    }

    printf("\nVertex\tDistance\tPath\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t", i);

        if (dist[i] == INF) {
            printf("INF\t\tNo Path\n");
        } else {
            printf("%d\t\t", dist[i]);
            printPath(parent, i);   
            printf("\n");
        }
    }

    return 0;
}
