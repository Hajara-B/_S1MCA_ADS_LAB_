#include <stdio.h>

void main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    int adj[n][n], visited[n];
    
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter adjacency matrix: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("\nTopological Sorting: \n");
    
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            for (int j = 0; j < n; j++) {
                if (adj[j][i] != 0) {
                    visited[i] = 1;
                    printf("%d ", i);
                    break;
                }
            }
        }
    }
}