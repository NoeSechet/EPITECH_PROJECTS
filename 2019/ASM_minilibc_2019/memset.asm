BITS 64

section .text
    global memset

memset:
    xor r8, r8

_loopCopy:
    cmp r8, rdx
    jge _ret

    mov byte [rdi + r8], sil

    inc r8
    jmp _loopCopy

_ret:
    mov rax, rdi
    ret