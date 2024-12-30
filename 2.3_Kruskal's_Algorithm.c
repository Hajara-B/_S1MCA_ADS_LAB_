#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define INF 999
struct Edge {
    int u, v, weight;
};
int parent[MAX], rank[MAX];
void initialize(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}
int find(int i) {
    if (parent[i] != i)
        parent[i] = find(parent[i]);
    return parent[i];
}
void union_sets(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    
    if (root_u != root_v) {
        if (rank[root_u] > rank[root_v]) {
            parent[root_v] = root_u;
        } else if (rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
        } else {
            parent[root_v] = root_u;
            rank[root_u]++;
        }
    }
}
int compare_edges(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}
void kruskal(int n, struct Edge edges[], int m) {
    int mst_weight = 0;
    qsort(edges, m, sizeof(struct Edge), compare_edges);
    initialize(n);
    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;
        if (find(u) != find(v)) {
            printf("%d - %d : %d\n", u, v, weight);
            mst_weight += weight;
            union_sets(u, v);
        }
    }
    printf("Total weight of MST: %d\n", mst_weight);
}
int main() {
    int n, m;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);
    struct Edge edges[m];
    printf("___Enter u , v , weight___");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }.
    kruskal(n, edges, m);
    return 0;
}
       