BITS 64

section .text:
    global strcspn

strcspn:
    xor rax, rax
    xor rcx, rcx      ;iterator in rdi
    xor r10, r10
    cmp rdi, 0
    je _retNULL
    cmp rsi, 0
    je _retNULL

_loopSPN:
    cmp byte [rdi + rcx], 0
    je _ret_strcspn
    jmp _parseRSI

_parseRSI:
    mov r8b, [rdi + rcx]
    mov r9b, [rsi + r10]
    cmp r8b, r9b
    je _ret_strcspn

    cmp r9b, 0
    je _endParseRSI
    inc r10
    jmp _parseRSI

_endParseRSI:
    mov r10, r10
    inc rcx
    jmp _loopSPN

_ret_strcspn:
    mov rax, rcx
    ret

_retNULL:
    mov rax, 0x00
    ret