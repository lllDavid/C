#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;      
    size_t size;    
    size_t capacity;
} DynamicArray;

void initArray(DynamicArray *arr, size_t initialCapacity) {
    arr->data = (int *)malloc(initialCapacity * sizeof(int));
    if (arr->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    arr->size = 0;
    arr->capacity = initialCapacity;
}

void append(DynamicArray *arr, int value) {
    if (arr->size == arr->capacity) {
        arr->capacity *= 2; 
        int *newData = (int *)realloc(arr->data, arr->capacity * sizeof(int));
        if (newData == NULL) {
            fprintf(stderr, "Memory reallocation failed\n");
            free(arr->data);
            exit(1);
        }
        arr->data = newData;
    }
    arr->data[arr->size++] = value;
}

void freeArray(DynamicArray *arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

int main() {
    DynamicArray arr;
    initArray(&arr, 4); 

    for (int i = 0; i < 10; i++) {
        append(&arr, i * 10);
        printf("Added %d, size: %zu, capacity: %zu\n", i * 10, arr.size, arr.capacity);
    }

    printf("Array elements: ");
    for (size_t i = 0; i < arr.size; i++) {
        printf("%d ", arr.data[i]);
    }
    printf("\n");

    freeArray(&arr);
    return 0;
}
