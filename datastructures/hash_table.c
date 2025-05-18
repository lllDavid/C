#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Node {
    char* key;
    int value;
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];

unsigned int hash(char* key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash + *key++) % TABLE_SIZE;
    }
    return hash;
}

void insert(char* key, int value) {
    unsigned int idx = hash(key);
    Node* newNode = malloc(sizeof(Node));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = hashTable[idx];
    hashTable[idx] = newNode;
}

int* search(char* key) {
    unsigned int idx = hash(key);
    Node* current = hashTable[idx];
    while (current) {
        if (strcmp(current->key, key) == 0)
            return &current->value;
        current = current->next;
    }
    return NULL;
}

void freeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = hashTable[i];
        while (current) {
            Node* tmp = current;
            current = current->next;
            free(tmp->key);
            free(tmp);
        }
        hashTable[i] = NULL;
    }
}

int main() {
    insert("apple", 100);
    insert("banana", 200);
    insert("orange", 300);

    int* val = search("banana");
    if (val) printf("%d\n", *val);
    else printf("Not found\n");

    val = search("grape");
    if (val) printf("%d\n", *val);
    else printf("Not found\n");

    freeTable();
    return 0;
}
