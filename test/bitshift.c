#include <stdio.h>
#include <time.h>

#define ITERATIONS 100000000

int main() {
    clock_t start, end;
    long long sum = 0;

    start = clock();
    for (long long i = 0; i < ITERATIONS; i++) {
        sum += i * 2;
    }
    end = clock();
    printf("Multiply by 2 (arithmetic): %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    sum = 0;
    start = clock();
    for (long long i = 0; i < ITERATIONS; i++) {
        sum += i << 1;
    }
    end = clock();
    printf("Multiply by 2 (bitshift):   %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    sum = 0;
    start = clock();
    for (long long i = 0; i < ITERATIONS; i++) {
        sum += i / 2;
    }
    end = clock();
    printf("Divide by 2 (arithmetic): %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    sum = 0;
    start = clock();
    for (long long i = 0; i < ITERATIONS; i++) {
        sum += i >> 1;
    }
    end = clock();
    printf("Divide by 2 (bitshift):   %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}