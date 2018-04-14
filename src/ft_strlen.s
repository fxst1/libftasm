
;
;	@PARAMS
;	RDI : buffer
;

section .text
global	ft_strlen

ft_strlen:

	enter		0, 0
	push		rdi
	mov			rax, 0
	mov			rcx, -1
	cmp			rdi, 0
	je			ft_strlen__end


	repne scasb
	mov			rax, -2
	sub			rax, rcx

ft_strlen__end:

	pop			rdi
	leave
	ret
