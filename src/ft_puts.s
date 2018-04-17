section .text

ft_puts:

	enter	0, 0
	push	rdi
	push	rdx
	mov		rdx, 0

ft_puts__loop:

	mov		rcx, 0
	not		rcx
	mov		al, 0
	cld

	repne	scasb

	; rcx == -1 - rcx
	not		rcx
	dec		rcx

ft_puts__end:

	mov		rax, 1
	mov		rsi, rdi
	mov		rdi, 1
	mov		rdx, rcx
	syscall

	pop		rdx
	pop		rdi

	leave
	ret
