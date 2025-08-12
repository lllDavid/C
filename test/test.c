#include <stdio.h>
#include <limits.h>  

int main(void) {
    int max = INT_MAX;
    printf("Max int: %d\n", max);
    printf("After overflow: %d\n", max + 1);
    return 0;
}