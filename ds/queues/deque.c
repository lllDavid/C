#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct Deque {
    Node* front;
    Node* rear;
} Deque;

Deque* createDeque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->front = dq->rear = NULL;
    return dq;
}

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->prev = node->next = NULL;
    return node;
}

void pushFront(Deque* dq, int data) {
    Node* node = createNode(data);
    if (!dq->front) {
        dq->front = dq->rear = node;
    } else {
        node->next = dq->front;
        dq->front->prev = node;
        dq->front = node;
    }
}

void pushBack(Deque* dq, int data) {
    Node* node = createNode(data);
    if (!dq->rear) {
        dq->front = dq->rear = node;
    } else {
        node->prev = dq->rear;
        dq->rear->next = node;
        dq->rear = node;
    }
}

int popFront(Deque* dq) {
    if (!dq->front) return -1;
    Node* temp = dq->front;
    int data = temp->data;
    dq->front = dq->front->next;
    if (dq->front) dq->front->prev = NULL;
    else dq->rear = NULL;
    free(temp);
    return data;
}

int popBack(Deque* dq) {
    if (!dq->rear) return -1;
    Node* temp = dq->rear;
    int data = temp->data;
    dq->rear = dq->rear->prev;
    if (dq->rear) dq->rear->next = NULL;
    else dq->front = NULL;
    free(temp);
    return data;
}

int isEmpty(Deque* dq) {
    return dq->front == NULL;
}

int getFront(Deque* dq) {
    return dq->front ? dq->front->data : -1;
}

int getBack(Deque* dq) {
    return dq->rear ? dq->rear->data : -1;
}

int main() {
    Deque* dq = createDeque();

    pushBack(dq, 10);
    pushFront(dq, 20);
    pushBack(dq, 30);

    printf("%d\n", getFront(dq));
    printf("%d\n", getBack(dq));

    printf("%d\n", popFront(dq));
    printf("%d\n", popBack(dq));

    printf("%d\n", isEmpty(dq));

    return 0;
}
