#include <stdio.h>

int a[10][10], visited[10], queue[10];
int n;

void broadcast(int root);

int main() {
    int i, j, root;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter root node (source): ");
    scanf("%d", &root);

    broadcast(root);

    return 0;
}

void broadcast(int root) {
    int front = 0, rear = 0, i;

    queue[rear++] = root;
    visited[root] = 1;

    printf("\nBroadcast Tree Edges:\n");

    while(front < rear) {
        int node = queue[front++];

        for(i = 1; i <= n; i++) {
            if(a[node][i] == 1 && visited[i] == 0) {
                printf("%d -> %d\n", node, i);
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}
