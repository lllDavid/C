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

    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapify(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;

    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(largest);
    }
}

int extractMax() {
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
    insert(15);
    insert(10);
    insert(30);
    insert(40);
    insert(20);

    displayHeap();

    printf("Extracted max: %d\n", extractMax());
    displayHeap();

    return 0;
}
