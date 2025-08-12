#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int r_rand() {
    unsigned int r1 = rand();
    unsigned int r2 = rand();
    return (r1 << 16) ^ r2;  
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        printf("%u\n", r_rand());
    }

    return 0;
}