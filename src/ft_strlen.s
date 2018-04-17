
;
;	@PARAMS
;	RDI : buffer
;

section .text
global	ft_strlen

ft_strlen:

	enter		0, 0
	push		rdi
	mov			rcx, 0
	not			rcx
	mov			al, 0
	cld

	repne		scasb

	; rcx == -1 - rcx
	not			rcx
	dec			rcx
	mov			rax, rcx

ft_strlen__end:

	pop			rdi
	leave
	ret
