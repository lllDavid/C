#include <stdio.h>
#include <stdlib.h>

void process_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 3;             
        printf("%d ", arr[i]);   
    }
    printf("\n");
}

int main() {
    int size = 5;
    int *arr = malloc(size * sizeof(int));
    if (!arr) return 1;

    for (int i = 0; i < size; i++) arr[i] = i + 1;  

    process_array(arr, size);

    free(arr);
    return 0;
}