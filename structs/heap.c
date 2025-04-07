#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent the heap
typedef struct {
    int arr[MAX_SIZE];
    int size;
} MinHeap;

// Function to initialize the heap
void initHeap(MinHeap* heap) {
    heap->size = 0;
}

// Function to get the index of the parent
int parent(int i) {
    return (i - 1) / 2;
}

// Function to get the index of the left child
int leftChild(int i) {
    return 2 * i + 1;
}

// Function to get the index of the right child
int rightChild(int i) {
    return 2 * i + 2;
}

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the subtree rooted at index i
void heapify(MinHeap* heap, int i) {
    int left = leftChild(i);
    int right = rightChild(i);
    int smallest = i;

    // If left child is smaller than root
    if (left < heap->size && heap->arr[left] < heap->arr[smallest]) {
        smallest = left;
    }

    // If right child is smaller than smallest so far
    if (right < heap->size && heap->arr[right] < heap->arr[smallest]) {
        smallest = right;
    }

    // If smallest is not root
    if (smallest != i) {
        swap(&heap->arr[i], &heap->arr[smallest]);
        heapify(heap, smallest);  // Recursively heapify the affected sub-tree
    }
}

// Function to insert a new key into the heap
void insert(MinHeap* heap, int key) {
    if (heap->size == MAX_SIZE) {
        printf("Heap overflow\n");
        return;
    }

    // Insert the new key at the end
    int i = heap->size++;
    heap->arr[i] = key;

    // Fix the min-heap property if it is violated
    while (i != 0 && heap->arr[parent(i)] > heap->arr[i]) {
        swap(&heap->arr[i], &heap->arr[parent(i)]);
        i = parent(i);
    }
}

// Function to extract the minimum element from the heap
int extractMin(MinHeap* heap) {
    if (heap->size <= 0) {
        printf("Heap underflow\n");
        return -1;  // Indicates heap underflow
    }

    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0];
    }

    // Store the minimum value, and remove it from the heap
    int root = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->size];
    heapify(heap, 0);

    return root;
}

// Function to get the minimum element
int getMin(MinHeap* heap) {
    if (heap->size <= 0) {
        printf("Heap is empty\n");
        return -1;
    }
    return heap->arr[0];
}

// Function to print the heap elements
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
