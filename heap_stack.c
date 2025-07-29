#include <stdio.h>
#include <stdlib.h>

void stackExample() {
    int a = 5;           
    int b = 10;           
    int arr[3] = {1, 2, 3};  

    printf("Stack variables:\n");
    printf("Address of a: %p, value: %d\n", (void*)&a, a);
    printf("Address of b: %p, value: %d\n", (void*)&b, b);
    printf("Address of arr: %p, values: %d, %d, %d\n", (void*)arr, arr[0], arr[1], arr[2]);
}

void heapExample() {
    int *p = (int*)malloc(sizeof(int));  
    int *arr = (int*)malloc(3 * sizeof(int));  

    if (p == NULL || arr == NULL) {
        printf("Heap allocation failed\n");
        free(p);
        free(arr);
        return;
    }

    *p = 100;
    arr[0] = 10; arr[1] = 20; arr[2] = 30;

    printf("Heap variables:\n");
    printf("Address of *p: %p, value: %d\n", (void*)p, *p);
    printf("Address of arr: %p, values: %d, %d, %d\n", (void*)arr, arr[0], arr[1], arr[2]);

    free(p);
    free(arr);
}

int main() {
    stackExample();
    heapExample();
    return 0;
}