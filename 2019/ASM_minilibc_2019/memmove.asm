BITS 64

section .text
    global memmove

memmove:
    xor r8, r8
    xor r10, r10
    xor r12, r12
    cmp rdi, 0
    je _retNULL
    cmp rsi, 0
    je _retNULL

    cmp rdi, rsi
    je _retMove
    jg _loopMoveBACK

_loopMoveFOR:
    cmp r8, rdx
    jge _retMove

    mov r9b, byte [rsi + r8]
    mov byte [rdi + r8], r9b

    inc r8
    jmp _loopMoveFOR

_loopMoveBACK:
    cmp rdx, 0
    jl _retMove

    mov r9b, byte [rsi + rdx]
    mov byte [rdi + rdx], r9b

    dec rdx
    jmp _loopMoveBACK

_retMove:
    mov rax, rdi
    ret

_retNULL:
    mov rax, 0x00
    ret