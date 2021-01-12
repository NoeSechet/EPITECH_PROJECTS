BITS 64

section .text:
    global strpbrk

strpbrk:
    xor rax, rax
    xor r8, r8      ;iterator in rdi
    xor r10, r10
    cmp rdi, 0
    je _retNULL
    cmp rsi, 0
    je _retNULL

_loopSPN:
    cmp byte [rsi], 0x0
    jne _parseRDI
    jmp _retNULL
_incRSI:
    mov r8, 0x0
    inc rsi
    jmp _loopSPN

_parseRDI:
    cmp byte [rdi + r8], 0x0
    je _incRSI
    mov r10b, byte [rsi]
    cmp byte [rdi + r8], r10b
    jne _incParser
    jmp _ret
_incParser:
    inc r8
    jmp _parseRDI

_ret:
    add rdi, r8
    mov rax, rdi
    ret

_retNULL:
    mov rax, 0x00
    ret