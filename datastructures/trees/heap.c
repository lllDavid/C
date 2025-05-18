#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int size;
} MinHeap;

void initHeap(MinHeap* heap) {
    heap->size = 0;
}

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return 2 * i + 1;
}

int rightChild(int i) {
    return 2 * i + 2;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(MinHeap* heap, int i) {
    int left = leftChild(i);
    int right = rightChild(i);
    int smallest = i;

    if (left < heap->size && heap->arr[left] < heap->arr[smallest]) {
        smallest = left;
    }

    if (right < heap->size && heap->arr[right] < heap->arr[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(&heap->arr[i], &heap->arr[smallest]);
        heapify(heap, smallest);
    }
}

void insert(MinHeap* heap, int key) {
    if (heap->size == MAX_SIZE) {
        printf("Heap overflow\n");
        return;
    }

    int i = heap->size++;
    heap->arr[i] = key;

    while (i != 0 && heap->arr[parent(i)] > heap->arr[i]) {
        swap(&heap->arr[i], &heap->arr[parent(i)]);
        i = parent(i);
    }
}

int extractMin(MinHeap* heap) {
    if (heap->size <= 0) {
        printf("Heap underflow\n");
        return -1;  
    }

    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0];
    }

    int root = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->size];
    heapify(heap, 0);

    return root;
}

int getMin(MinHeap* heap) {
    if (heap->size <= 0) {
        printf("Heap is empty\n");
        return -1;
    }
    return heap->arr[0];
}

void printHeap(MinHeap* heap) {
    if (heap->size <= 0) {
        printf("Heap is empty\n");
        return;
    }

    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

int main() {
    MinHeap heap;
    initHeap(&heap);

    insert(&heap, 3);
    insert(&heap, 2);
    insert(&heap, 15);
    insert(&heap, 5);
    insert(&heap, 4);
    insert(&heap, 45);

    printf("Min-Heap array: ");
    printHeap(&heap);

    printf("Extracted min: %d\n", extractMin(&heap));
    printf("Min-Heap array after extraction: ");
    printHeap(&heap);

    printf("Current minimum: %d\n", getMin(&heap));

    return 0;
}
