#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data[MAX_SIZE];
    int size;
} PriorityQueue;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void initQueue(PriorityQueue* pq) {
    pq->size = 0;
}

void heapifyUp(PriorityQueue* pq, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (pq->data[parent] > pq->data[index]) {
            swap(&pq->data[parent], &pq->data[index]);
            index = parent;
        } else break;
    }
}

void heapifyDown(PriorityQueue* pq, int index) {
    int left, right, smallest;
    while (1) {
        left = 2 * index + 1;
        right = 2 * index + 2;
        smallest = index;

        if (left < pq->size && pq->data[left] < pq->data[smallest])
            smallest = left;
        if (right < pq->size && pq->data[right] < pq->data[smallest])
            smallest = right;
        if (smallest != index) {
            swap(&pq->data[smallest], &pq->data[index]);
            index = smallest;
        } else break;
    }
}

void push(PriorityQueue* pq, int value) {
    if (pq->size >= MAX_SIZE) return;
    pq->data[pq->size] = value;
    heapifyUp(pq, pq->size);
    pq->size++;
}

int pop(PriorityQueue* pq) {
    if (pq->size == 0) return -1;
    int top = pq->data[0];
    pq->data[0] = pq->data[--pq->size];
    heapifyDown(pq, 0);
    return top;
}

int peek(PriorityQueue* pq) {
    if (pq->size == 0) return -1;
    return pq->data[0];
}

int isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

int main() {
    PriorityQueue pq;
    initQueue(&pq);

    push(&pq, 5);
    push(&pq, 2);
    push(&pq, 8);
    push(&pq, 1);

    while (!isEmpty(&pq)) {
        printf("%d\n", pop(&pq));
    }

    return 0;
}
