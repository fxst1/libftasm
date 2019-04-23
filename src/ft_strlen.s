
;
;	@PARAMS
;	RDI : buffer
;

section .text
global	ft_strlen

ft_strlen:

	push    rbp
	mov     rbp, rsp
	push		rdi

	mov			rax, 0
	test		rdi, rdi
	jz			.ft_strlen__end

	mov			rcx, 0
	not			rcx
	mov			al, 0
	cld

	repne		scasb

	; rcx == -1 - rcx
	not			rcx
	dec			rcx
	mov			rax, rcx

.ft_strlen__end:

	pop		rdi
	mov		rsp, rbp
	pop		rbp
	ret
