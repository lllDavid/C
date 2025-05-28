#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int queue[SIZE];
int front = -1, rear = -1;

int isFull() {
    return rear == SIZE - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("Inserted %d\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Deleted %d\n", queue[front]);
    front++;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    enqueue(40);
    display();

    return 0;
}
