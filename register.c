#include <stdio.h>
#include <stdint.h>

uint8_t A = 0; 
uint8_t B = 0;  
uint8_t C = 0;  
uint8_t PC = 0; 

uint8_t memory[256];

enum {
    LOAD_A = 1,
    LOAD_B,
    ADD_A_B,
    STORE_A_MEM,
    HALT
};

void execute(uint8_t *program) {
    PC = 0;
    uint8_t running = 1;

    while (running) {
        uint8_t opcode = program[PC++];

        switch (opcode) {
            case LOAD_A:
                A = program[PC++];
                break;
            case LOAD_B:
                B = program[PC++];
                break;
            case ADD_A_B:
                A = A + B;
                break;
            case STORE_A_MEM: {
                uint8_t addr = program[PC++];
                memory[addr] = A;
                break;
            }
            case HALT:
                running = 0;
                break;
            default:
                running = 0;  
                break;
        }
    }
}

int main() {
    uint8_t program[] = {
        LOAD_A, 10,
        LOAD_B, 20,
        ADD_A_B,
        STORE_A_MEM, 0,
        HALT
    };

    execute(program);

    printf("Memory[0] = %d\n", memory[0]);
    return 0;
}