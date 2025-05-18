#include <stdio.h>

#define N 100

int parent[N];
int rank[N];

void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY) return;
    if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

int main() {
    makeSet(10);

    unionSets(1, 2);
    unionSets(2, 3);
    unionSets(4, 5);

    printf("%d\n", find(1)); 
    printf("%d\n", find(3));
    printf("%d\n", find(4));
    printf("%d\n", find(5));
    printf("%d\n", find(6)); 

    return 0;
}
