#include <stdio.h>

unsigned long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int num = 10;
    printf("Factorial of %d is %llu\n", num, factorial(num));
    return 0;
}
