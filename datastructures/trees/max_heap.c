#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct MaxHeap {
    int *arr;
    int capacity;
    int size;
} MaxHeap;

MaxHeap* createMaxHeap(int capacity) {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
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

void maxHeapify(MaxHeap* heap, int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l < heap->size && heap->arr[l] > heap->arr[largest])
        largest = l;

    if (r < heap->size && heap->arr[r] > heap->arr[largest])
        largest = r;

    if (largest != i) {
        swap(&heap->arr[i], &heap->arr[largest]);
        maxHeapify(heap, largest);
    }
}

void insertKey(MaxHeap* heap, int k) {
    if (heap->size == heap->capacity)
        return;
    heap->size++;
    int i = heap->size - 1;
    heap->arr[i] = k;
    while (i != 0 && heap->arr[parent(i)] < heap->arr[i]) {
        swap(&heap->arr[i], &heap->arr[parent(i)]);
        i = parent(i);
    }
}

int extractMax(MaxHeap* heap) {
    if (heap->size <= 0)
        return INT_MIN;
    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0];
    }
    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    maxHeapify(heap, 0);
    return root;
}

int getMax(MaxHeap* heap) {
    if (heap->size <= 0)
        return INT_MIN;
    return heap->arr[0];
}

int main() {
    MaxHeap* heap = createMaxHeap(10);
    insertKey(heap, 3);
    insertKey(heap, 2);
    insertKey(heap, 15);
    insertKey(heap, 5);
    insertKey(heap, 4);
    insertKey(heap, 45);
    printf("%d\n", extractMax(heap));
    printf("%d\n", getMax(heap));
    free(heap->arr);
    free(heap);
    return 0;
}
