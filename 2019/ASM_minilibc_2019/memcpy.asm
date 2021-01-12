BITS 64

section .text
    global memcpy

memcpy:
    xor r8, r8

_loopCopy:
    cmp r8, rdx
    jge _ret

    mov r9b, byte [rsi + r8]
    mov byte [rdi + r8], r9b

    inc r8
    jmp _loopCopy

_ret:
    mov rax, rdi
    ret