
;
;	@PARAMS
;	RDI : const void*	src
;	RSI : size_t		size
;

%include "./inc/libftasm.s"
section .text

global	ft_memdup
extern	malloc

ft_memdup:

	push    rbp
    mov     rbp, rsp

	test	rdi, rdi
	jz		.ft_memdup__error_nul

	push	rdi
	push	rsi

;	mov		rbp, rsp
;	and		rsp, ALIGNSTACK
	mov		rdi, rsi
	call	malloc
;	mov		rsp, rbp
	test	rax, rax
	jz		.ft_memdup__error_oom	; malloc(size) returned null

	pop		rcx
	pop		rsi
	mov		rdi, rax
	cld
	rep		movsb

	mov		rsp, rbp
	pop		rbp
	ret

.ft_memdup__error_oom:

	pop		rsi
	pop		rdi

.ft_memdup__error_nul:

	pop		rsi

	mov		rax, 0

	mov		rsp, rbp
	pop		rbp
	ret
