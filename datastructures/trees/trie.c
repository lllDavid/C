#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

void insert(TrieNode* root, const char* key) {
    TrieNode* current = root;
    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a';
        if (!current->children[index])
            current->children[index] = createNode();
        current = current->children[index];
    }
    current->isEndOfWord = true;
}

bool search(TrieNode* root, const char* key) {
    TrieNode* current = root;
    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a';
        if (!current->children[index])
            return false;
        current = current->children[index];
    }
    return current != NULL && current->isEndOfWord;
}

int main() {
    TrieNode* root = createNode();

    insert(root, "hello");
    insert(root, "world");

    printf("%s\n", search(root, "hello") ? "Found" : "Not found");
    printf("%s\n", search(root, "hell") ? "Found" : "Not found");
    printf("%s\n", search(root, "world") ? "Found" : "Not found");

    return 0;
}
