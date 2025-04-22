#include <stdio.h>

int main() {
    char vendor[13]; /^^
    unsigned int eax, ebx, ecx, edx;

    asm volatile (
        "cpuid"
        : "=b" (ebx), "=d" (edx), "=c" (ecx)
        : "a" (0)
    );

    *(unsigned int*)&vendor[0] = ebx;
    *(unsigned int*)&vendor[4] = edx;
    *(unsigned int*)&vendor[8] = ecx;
    vendor[12] = '\0'; 

    printf("CPU Vendor: %s\n", vendor);
    return 0;
}
