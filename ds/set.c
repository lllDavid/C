#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int elements[MAX_SIZE];
    int size;
} Set;

void initSet(Set* set) {
    set->size = 0;
}

bool contains(Set* set, int value) {
    for (int i = 0; i < set->size; i++) {
        if (set->elements[i] == value)
            return true;
    }
    return false;
}

bool add(Set* set, int value) {
    if (set->size >= MAX_SIZE) {
        printf("Set is full.\n");
        return false;
    }
    if (!contains(set, value)) {
        set->elements[set->size++] = value;
        return true;
    }
    return false;
}

bool removeElement(Set* set, int value) {
    for (int i = 0; i < set->size; i++) {
        if (set->elements[i] == value) {
            for (int j = i; j < set->size - 1; j++) {
                set->elements[j] = set->elements[j + 1];
            }
            set->size--;
            return true;
        }
    }
    return false;
}

void printSet(Set* set) {
    printf("{ ");
    for (int i = 0; i < set->size; i++) {
        printf("%d ", set->elements[i]);
    }
    printf("}\n");
}

int main() {
    Set mySet;
    initSet(&mySet);

    add(&mySet, 10);
    add(&mySet, 20);
    add(&mySet, 30);
    add(&mySet, 20);  

    printSet(&mySet);

    removeElement(&mySet, 10);
    printSet(&mySet);

    if (contains(&mySet, 30))
        printf("30 is in the set.\n");

    return 0;
}
