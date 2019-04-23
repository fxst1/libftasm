
;
;	@PARAMS
;	RDI : const void*	buf
;	RSI : size_t		bufsize
;

%include "./inc/libftasm.s"
section .text

global	ft_lstnew_noalloc
extern	ft_memdup
extern	malloc

ft_lstnew_noalloc:

	push    rbp
	mov     rbp, rsp

	push	rdi
	push	rsi

	test	rdi, rdi
	jz		.ft_lstnew__error_nul

	mov		rdi, SIZEOF_LIST
	call	malloc
	test	rax, rax
	jz		.ft_lstnewnoa__error_malloc

	mov QWORD	rcx, [rsp + 0x8]
	mov QWORD	[rax + OFFSET_LIST_CONTENT], rcx
	mov	QWORD	[rax + OFFSET_LIST_NEXT], 0
	mov	QWORD	[rax + OFFSET_LIST_LAST], 0
	mov	QWORD	[rax + OFFSET_LIST_FIRST], 0
	mov QWORD	rcx, [rsp]
	mov	QWORD	[rax + OFFSET_LIST_CONTENTS], rcx

	pop			rsi
	pop			rdi

	mov		rsp, rbp
	pop		rbp
	ret

.ft_lstnewnoa__error_malloc:

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
