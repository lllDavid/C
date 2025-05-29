#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int global_initialized = 42;        
int global_uninitialized;           

void print_message() {              
    printf("Inside function (code segment)\n");
}

int main() {
    int local_var = 10;             
    char *heap_var = malloc(100);   

    strcpy(heap_var, "Hello from heap!");

    printf("Address of function        : %p (Code/Text segment)\n", (void*)print_message);
    printf("Address of global init var: %p (Data segment)\n", (void*)&global_initialized);
    printf("Address of global uninit  : %p (BSS segment)\n", (void*)&global_uninitialized);
    printf("Address of local variable : %p (Stack segment)\n", (void*)&local_var);
    printf("Address of heap variable  : %p (Heap segment)\n", (void*)heap_var);

    free(heap_var); 

    return 0;
}
