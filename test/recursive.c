#include <stdio.h>

int recursiveAdd(int a, int b) {
    if (b == 0)
        return a;
    return recursiveAdd(a + 1, b - 1);
}

int recursiveMultiply(int a, int b) {
    if (b == 0)
        return 0;
    return a + recursiveMultiply(a, b - 1);
}

int main() {
    int x = 5, y = 3;

    int sum = recursiveAdd(x, y);
    int product = recursiveMultiply(x, y);

    printf("Sum of %d and %d is %d\n", x, y, sum);
    printf("Product of %d and %d is %d\n", x, y, product);

    return 0;
}