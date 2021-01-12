BITS 64

section .text:
    global rindex

rindex:
    xor rax, rax
    xor r8, r8

_loopRindex:
    cmp byte [rdi + r8], 0
	je _endofloop

    cmp byte [rdi + r8], sil
    je _saveIntoR8
    inc r8
    jmp _loopRindex

_saveIntoR8:
    mov rax, [rdi + r8]
    inc r8
    jmp _loopRindex

_endofloop:
	ret