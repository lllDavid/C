#include <stdio.h>

int main() {
    unsigned int a = 5;   
    unsigned int b = 3;   

    unsigned int andResult = a & b;   
    unsigned int orResult = a | b;   
    unsigned int xorResult = a ^ b;   
    unsigned int notResult = ~a;     

    printf("a = %u\n", a);
    printf("b = %u\n", b);
    printf("a & b (AND): %u\n", andResult);
    printf("a | b (OR): %u\n", orResult);
    printf("a ^ b (XOR): %u\n", xorResult);
    printf("~a (NOT): %u\n", notResult);

    return 0;
}