#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct Node {
    uint32_t hash;
    struct Node *left, *right;
} Node;

uint32_t fnv1a(const unsigned char *data, size_t len) {
    uint32_t hash = 2166136261u;
    for (size_t i = 0; i < len; i++) {
        hash ^= data[i];
        hash *= 16777619;
    }
    return hash;
}

Node* make_leaf(const unsigned char *data, size_t len) {
    Node *n = malloc(sizeof(Node));
    n->hash = fnv1a(data, len);
    n->left = n->right = NULL;
    return n;
}

Node* make_parent(Node *left, Node *right) {
    Node *n = malloc(sizeof(Node));
    unsigned char combined[8];
    memcpy(combined, &left->hash, 4);
    memcpy(combined + 4, &right->hash, 4);
    n->hash = fnv1a(combined, 8);
    n->left = left;
    n->right = right;
    return n;
}

Node* build_tree(Node **nodes, int count) {
    if (count == 1) return nodes[0];
    int new_count = (count + 1) / 2;
    Node **parents = malloc(new_count * sizeof(Node*));
    for (int i = 0; i < new_count; i++) {
        Node *left = nodes[i*2];
        Node *right = (i*2+1 < count) ? nodes[i*2+1] : left;
        parents[i] = make_parent(left, right);
    }
    Node *root = build_tree(parents, new_count);
    free(parents);
    return root;
}

void free_tree(Node *n) {
    if (!n) return;
    free_tree(n->left);
    free_tree(n->right);
    free(n);
}

void print_hash(uint32_t h) {
    printf("%08x\n", h);
}

int main() {
    const char *blocks[] = {"Block1", "Block2", "Block3", "Block4"};
    int count = 4;
    Node **leaves = malloc(count * sizeof(Node*));

    for (int i = 0; i < count; i++) {
        leaves[i] = make_leaf((const unsigned char*)blocks[i], strlen(blocks[i]));
        printf("Leaf %d: ", i);
        print_hash(leaves[i]->hash);
    }

    Node *root = build_tree(leaves, count);
    printf("Merkle Root: ");
    print_hash(root->hash);

    free_tree(root);
    free(leaves);
    return 0;
}