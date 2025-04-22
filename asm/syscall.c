#include <stdio.h>

int main() {
    asm (
        "movl $1, %%eax;"   
        "xorl %%ebx, %%ebx;" 
        "int $0x80;"         
        :                   
        :                    
        : "%eax", "%ebx"     
    );

    return 0; 
}
