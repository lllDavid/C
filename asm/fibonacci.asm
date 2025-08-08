; fibonacci.asm
EXTERN print_int:PROC
.code

fibonacci PROC
    push rbx             ; Save non-volatile register

    xor rax, rax         ; a = 0
    mov rbx, 1           ; b = 1
    xor rdx, rdx         ; i = 0

loop_start:
    cmp rdx, rcx         ; if i >= n
    jge done

    ; Call print_int(a)
    mov edi, eax         ; move a into first arg
    call print_int

    ; Fibonacci: t = a + b
    mov r8, rbx
    add r8, rax
    mov rax, rbx
    mov rbx, r8

    inc rdx              ; i++
    jmp loop_start

done:
    pop rbx
    ret
fibonacci ENDP

END