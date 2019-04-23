%include "./inc/libftasm.s"
section	.text
global	ft_lstpush

ft_lstpush:

	push    rbp
	mov     rbp, rsp

	test	rdi, rdi
	jz		.ft_lstpush__end

	test	rsi, rsi
	jz		.ft_lstpush__end

	mov QWORD	rax, [rdi]
	test	rax, rax
	jz		.ft_lstpush__null_root

	mov QWORD	rbx, [rax + OFFSET_LIST_LAST]
	mov QWORD	[rsi + OFFSET_LIST_LAST], rbx

	mov QWORD	rbx, [rax + OFFSET_LIST_FIRST]
	mov QWORD	[rsi + OFFSET_LIST_FIRST], rbx

	mov QWORD	[rsi + OFFSET_LIST_NEXT], rax
	mov QWORD	[rdi], rsi

.ft_lstpush__end:

	mov		rsp, rbp
	pop		rbp
	ret

.ft_lstpush__null_root:

	mov QWORD	[rsi + OFFSET_LIST_FIRST], rsi
	mov QWORD	[rdi], rsi

	jmp		.ft_lstpush__end
