#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct MinHeap {
    int *arr;
    int capacity;
    int size;
} MinHeap;

MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->arr = (int*)malloc(capacity * sizeof(int));
    return heap;
}

int parent(int i) { return (i - 1) / 2; }
int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void minHeapify(MinHeap* heap, int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < heap->size && heap->arr[l] < heap->arr[smallest])
        smallest = l;

    if (r < heap->size && heap->arr[r] < heap->arr[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&heap->arr[i], &heap->arr[smallest]);
        minHeapify(heap, smallest);
    }
}

void insertKey(MinHeap* heap, int k) {
    if (heap->size == heap->capacity)
        return;
    heap->size++;
    int i = heap->size - 1;
    heap->arr[i] = k;
    while (i != 0 && heap->arr[parent(i)] > heap->arr[i]) {
        swap(&heap->arr[i], &heap->arr[parent(i)]);
        i = parent(i);
    }
}

int extractMin(MinHeap* heap) {
    if (heap->size <= 0)
        return INT_MAX;
    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0];
    }
    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);
    return root;
}

int getMin(MinHeap* heap) {
    if (heap->size <= 0)
        return INT_MAX;
    return heap->arr[0];
}

int main() {
    MinHeap* heap = createMinHeap(10);
    insertKey(heap, 3);
    insertKey(heap, 2);
    insertKey(heap, 15);
    insertKey(heap, 5);
    insertKey(heap, 4);
    insertKey(heap, 45);
    printf("%d\n", extractMin(heap));
    printf("%d\n", getMin(heap));
    free(heap->arr);
    free(heap);
    return 0;
}
