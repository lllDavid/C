#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26
#define MAX_WORD_LENGTH 100

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool is_end_of_word;
} TrieNode;

TrieNode* create_node() {
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
    if (node) {
        node->is_end_of_word = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            node->children[i] = NULL;
    }
    return node;
}

void insert(TrieNode *root, const char *word) {
    TrieNode *current = root;
    while (*word) {
        int index = *word - 'a';
        if (index < 0 || index >= ALPHABET_SIZE) {
            word++;
            continue; 
        }
        if (!current->children[index])
            current->children[index] = create_node();
        current = current->children[index];
        word++;
    }
    current->is_end_of_word = true;
}

bool search(TrieNode *root, const char *word) {
    TrieNode *current = root;
    while (*word) {
        int index = *word - 'a';
        if (index < 0 || index >= ALPHABET_SIZE)
            return false;
        if (!current->children[index])
            return false;
        current = current->children[index];
        word++;
    }
    return current->is_end_of_word;
}

void collect_suggestions(TrieNode *node, char *prefix, int depth) {
    if (node->is_end_of_word) {
        prefix[depth] = '\0';
        printf("%s\n", prefix);
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            prefix[depth] = 'a' + i;
            collect_suggestions(node->children[i], prefix, depth + 1);
        }
    }
}

void autocomplete(TrieNode *root, const char *prefix) {
    TrieNode *current = root;
    while (*prefix) {
        int index = *prefix - 'a';
        if (index < 0 || index >= ALPHABET_SIZE || !current->children[index]) {
            printf("No suggestions found.\n");
            return;
        }
        current = current->children[index];
        prefix++;
    }

    char buffer[MAX_WORD_LENGTH];
    strncpy_s(buffer, MAX_WORD_LENGTH, prefix, _TRUNCATE);
    collect_suggestions(current, buffer, strlen(prefix));
}

void free_trie(TrieNode *node) {
    if (!node) return;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        free_trie(node->children[i]);
    free(node);
}

int main() {
    TrieNode *root = create_node();

    insert(root, "hello");
    insert(root, "hell");
    insert(root, "helicopter");
    insert(root, "hero");
    insert(root, "heat");
    insert(root, "heap");

    printf("Search for 'hero': %s\n", search(root, "hero") ? "Found" : "Not found");
    printf("Search for 'heron': %s\n", search(root, "heron") ? "Found" : "Not found");

    printf("\nAutocomplete suggestions for 'he':\n");
    autocomplete(root, "he");

    free_trie(root);
    return 0;
}