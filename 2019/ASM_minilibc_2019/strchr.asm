BITS 64

section	.text
	global strchr

strchr:
	xor	rax, rax

_loop:
	cmp	byte [rdi], sil
	je	_endofloop
	cmp	byte [rdi], 0x00
	je	ret_null
	inc rdi
	jmp	_loop

_endofloop:
	mov	rax, rdi
	jmp	end

ret_null:
	mov rax, 0x00
	ret

end:
	ret