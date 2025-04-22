#include <stdio.h>

int main() {
    unsigned int a = 5;  

    unsigned int leftShift = a << 1;  

    unsigned int rightShift = a >> 1; 

    printf("Original value: %u\n", a);
    printf("Left Shift (a << 1): %u\n", leftShift);
    printf("Right Shift (a >> 1): %u\n", rightShift);

    return 0;
}
