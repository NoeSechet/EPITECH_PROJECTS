BITS 64

section .text
    global strcasecmp

strcasecmp:
    xor rax, rax
    mov r8, rdi
    mov r9, rsi

_loopComp:
    mov r10b, byte [r8]
    cmp r10b, 65
    jl _checkSecChar
    cmp r10b, 90
    jg _checkSecChar
    add r10b, 32

_checkSecChar:
    mov r11b, byte [r9]
    cmp r11b, 65
    jl _compChar
    cmp r11b, 90
    jg _compChar
    add r11b, 32

_compChar:
    cmp r10b, r11b
    jl _retCompMinus
    jg _retCompPlus

    cmp r10b, 0
    je _retCompEqual

    inc r8
    inc r9

    jmp _loopComp

_retCompEqual:
    mov rax, 0
    ret

_retCompPlus:
    mov rax, 1
    ret

_retCompMinus:
    mov rax, -1
    ret
