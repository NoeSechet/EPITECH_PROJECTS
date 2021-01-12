BITS 64

section .text
    global strlen

strlen:
    mov rbx, 0

_loopStrlen:
    cmp byte [rdi], 0
    je _ret
    inc rdi
    inc rbx
    jmp _loopStrlen

_ret:
    mov rax, rbx
    ret