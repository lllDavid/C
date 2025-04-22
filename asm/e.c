#include <stdio.h>

int main() {
    int a = 10, b = 20, result;

    asm (
        "movl %1, %%eax;"   
        "addl %2, %%eax;"  
        "movl %%eax, %0;"   
        : "=r" (result)     
        : "r" (a), "r" (b)  
        : "%eax"           
    );

    printf("Result: %d\n", result);
    return 0;
}
