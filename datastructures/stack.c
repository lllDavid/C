#include <stdio.h>
#include <stdlib.h>

#define MAX 100  

typedef struct {
    int items[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int item) {
    if (isFull(s)) {
        printf("Stack overflow! Cannot push %d\n", item);
        return;
    }
    s->items[++(s->top)] = item;
    printf("Pushed %d onto the stack\n", item);
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot pop\n");
        return -1; 
    }
    return s->items[(s->top)--];
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->items[s->top];
}

int main() {
    Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element is %d\n", peek(&s));

    printf("Popped element is %d\n", pop(&s));
    printf("Popped element is %d\n", pop(&s));

    if (isEmpty(&s)) {
        printf("Stack is empty now\n");
    } else {
        printf("Stack is not empty\n");
    }

    return 0;
}
