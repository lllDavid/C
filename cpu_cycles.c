#include <stdio.h>
#include <stdint.h>

static inline uint64_t get_cpu_cycles() {
    unsigned int lo, hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}

int main() {
    int i = 0;
    const int iterations = 5; 
    uint64_t start_cycles, end_cycles;

    printf("Reading CPU cycles %d times:\n", iterations);

    while (i < iterations) {
        start_cycles = get_cpu_cycles();
        for (volatile int j = 0; j < 1000000; j++);
        end_cycles = get_cpu_cycles();

        printf("Iteration %d: %llu cycles\n", i + 1, end_cycles - start_cycles);
        i++;
    }

    return 0;
}