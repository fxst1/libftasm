
;
;	@PARAMS
;	RDI : const void*	buf
;	RSI : size_t		bufsize
;

%include "./inc/libftasm.s"
section .text

global	ft_lstnew
extern	ft_memdup
extern	malloc

ft_lstnew:

	push    rbp
	mov     rbp, rsp

	push	rdi
	push	rsi

	test	rdi, rdi
	jz		.ft_lstnew__error_nul

	mov		rdi, SIZEOF_LIST
	call	malloc
	test	rax, rax
	jz		.ft_lstnew__error_malloc

	mov QWORD	[rax + OFFSET_LIST_CONTENT], 0
	mov	QWORD	[rax + OFFSET_LIST_NEXT], 0
	mov	QWORD	[rax + OFFSET_LIST_LAST], 0
	mov	QWORD	[rax + OFFSET_LIST_FIRST], 0
	mov QWORD	rcx, [rsp]
	mov	QWORD	[rax + OFFSET_LIST_CONTENTS], rcx
	push		rax

	mov QWORD	rdi, [rsp + 0x10]
	mov QWORD	rsi, [rsp + 0x8]
	call		ft_memdup
	mov QWORD	rbx, [rsp]
	mov QWORD	[rbx + OFFSET_LIST_CONTENT], rax
	pop			rax

	pop			rsi
	pop			rdi

	mov		rsp, rbp
	pop		rbp
	ret

.ft_lstnew__error_malloc:

	mov		rax, 0

	pop		rsi
	pop		rdi

	mov		rsp, rbp
	pop		rbp
	ret

.ft_lstnew__error_nul:

	mov		rax, 0

	pop		rsi
	pop		rdi

	mov		rsp, rbp
	pop		rbp
	ret
