#include <stdio.h>
#include <time.h>

extern void fibonacci(int n);

void print_int(int x) {
    printf("%d\n", x);
}

int main() {
    clock_t start, end;
    double time;

    start = clock();
    fibonacci(10); 
    end = clock();

    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", time);

    return 0;
}