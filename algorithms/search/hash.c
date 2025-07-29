#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* table[SIZE];

int hash(int k) { return k % SIZE; }

void insert(int k) {
    int h = hash(k);
    Node* n = malloc(sizeof(Node));
    n->key = k; n->next = table[h];
    table[h] = n;
}

int search(int k) {
    for (Node* cur = table[hash(k)]; cur; cur = cur->next)
        if (cur->key == k) return 1;
    return 0;
}

int main() {
    for (int i=0; i<SIZE; i++) table[i]=NULL;

    insert(10); insert(20); insert(15);

    printf("%d\n", search(15));
    printf("%d\n", search(30)); 

    return 0;
}