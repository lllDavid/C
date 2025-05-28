#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;  
} TrieNode;

TrieNode* getNode(void) {
    TrieNode *node = (TrieNode*)malloc(sizeof(TrieNode));
    if (node) {
        node->isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            node->children[i] = NULL;
    }
    return node;
}

void insert(TrieNode *root, const char *key) {
    TrieNode *crawler = root;

    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a';
        if (!crawler->children[index])
            crawler->children[index] = getNode();
        crawler = crawler->children[index];
    }
    crawler->isEndOfWord = true;
}

bool search(TrieNode *root, const char *key) {
    TrieNode *crawler = root;

    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a';
        if (!crawler->children[index])
            return false;
        crawler = crawler->children[index];
    }
    return (crawler != NULL && crawler->isEndOfWord);
}

void freeTrie(TrieNode *root) {
    if (!root) return;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        freeTrie(root->children[i]);
    free(root);
}

int main() {
    char keys[][10] = {"hello", "world", "trie", "tree", "algo", "algorithms"};
    int n = sizeof(keys) / sizeof(keys[0]);

    TrieNode *root = getNode();

    for (int i = 0; i < n; i++)
        insert(root, keys[i]);
    
    printf("Search results:\n");
    printf("hello: %s\n", search(root, "hello") ? "Found" : "Not Found");
    printf("world: %s\n", search(root, "world") ? "Found" : "Not Found");
    printf("tree: %s\n", search(root, "tree") ? "Found" : "Not Found");
    printf("algo: %s\n", search(root, "algo") ? "Found" : "Not Found");
    printf("algorithm: %s\n", search(root, "algorithm") ? "Found" : "Not Found");
    printf("algorithms: %s\n", search(root, "algorithms") ? "Found" : "Not Found");

    freeTrie(root);

    return 0;
}
