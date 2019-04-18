%include "./inc/libftasm.s"

global	ft_puts

section .text

ft_puts:

	test	rdi, rdi
	jz		.ft_puts__error
	push	rdx
	push	rdi
	mov		rdx, 0

.ft_puts__processed:

	mov			rdi, [rsp]
	call		.ft_puts__compute_length

	mov		rdx, rax
	mov		rax, SYSCALL_WRITE
	mov		rsi, rdi
	mov		rdi, STDOUT_FILENO
	syscall

	push		NEWLINE
	mov			rdi, rsp
	call		.ft_puts__compute_length

	mov			rdx, rax
	mov			rax, SYSCALL_WRITE
	mov			rsi, rsp
	mov			rdi, STDOUT_FILENO
	syscall

	; Reset registers, clear stack and return
	pop		rdi
	pop		rdi
	pop		rdx

	mov		rax, 1
	ret

.ft_puts__error

	mov		rax, 0
	ret

.ft_puts__compute_length:

	push	rdi

	; rcx = -1 (max value)
	mov		rcx, 0
	not		rcx
	mov		al, 0
	cld

	repnz	scasb

	; rcx ~= rcx (deduct real size)
	not		rcx
	dec		rcx
	mov		rax, rcx

	pop		rdi
	ret
