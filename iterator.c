#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int *array;
    int size;
    int index;
} IntIterator;

void init_iterator(IntIterator *it, int *array, int size) {
    it->array = array;
    it->size = size;
    it->index = 0;
}

bool has_next(IntIterator *it) {
    return it->index < it->size;
}

int next(IntIterator *it) {
    if (has_next(it)) {
        return it->array[it->index++];
    } else {
        return -1;
    }
}

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    IntIterator it;

    init_iterator(&it, numbers, 5);

    while (has_next(&it)) {
        int value = next(&it);
        printf("%d\n", value);
    }

    return 0;
}
