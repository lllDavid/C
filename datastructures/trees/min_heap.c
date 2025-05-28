#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int heap[MAX_SIZE];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int value) {
    if (size >= MAX_SIZE) {
        printf("Heap overflow!\n");
        return;
    }

    int i = size++;
    heap[i] = value;

    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapify(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

int extractMin() {
    if (size <= 0) {
        printf("Heap underflow!\n");
        return -1;
    }

    int root = heap[0];
    heap[0] = heap[--size];
    heapify(0);
    return root;
}

void displayHeap() {
    printf("Heap array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(5);
    insert(30);
    insert(1);

    displayHeap();

    printf("Extracted min: %d\n", extractMin());
    displayHeap();

    return 0;
}
