
section .text

global	ft_memset

ft_memset:

	enter		0, 0
	push		rdi

	mov			rcx, rdx
	mov			rax, rsi

	cld
	rep stosb

	pop			rax

	leave
	ret
