#include <stdio.h>
#include <stdlib.h>

void dfs(int n, int start, int a[n][n], int v[n]) {
    if (v[start] != 1) {
        printf("%d ", start);
        v[start] = 1;
        for (int i = 0; i < n; i++) {
            if (a[start][i] == 1 && v[i] == 0) {
                dfs(n, i, a, v);
            }
        }
    }
}

int main() {
    int n, start;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int a[n][n], v[n];
    
    printf("Enter Adjacency matrix for the graph: \n");
    for (int i = 0; i < n; i++) {
        v[i] = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter starting node (0-%d): ", n - 1);
    scanf("%d", &start);
    
    printf("\nDFS Traversal: ");
    dfs(n, start, a, v);
    
    return 0;
}
