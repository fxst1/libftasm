%include "./inc/libftasm.s"
section	.text
global	ft_lstpop

ft_lstpop:

	push    rbp
	mov     rbp, rsp

	test	rdi, rdi
	jz		.ft_lstpop__null_root

	mov QWORD	rax, [rdi]
	test		rax, rax
	jz			.ft_lstpop__null_root

	; node->last->next = node->next
	mov QWORD	rbx, [rax + OFFSET_LIST_LAST]
	mov QWORD	rcx, [rax + OFFSET_LIST_NEXT]
	mov QWORD	[rdi], rcx
	test		rbx, rbx
	jz			.ft_lstpop__set_next
	mov QWORD	[rbx + OFFSET_LIST_NEXT], rcx

.ft_lstpop__set_next:

	; node->next->last = node->last
	mov QWORD	rbx, [rax + OFFSET_LIST_NEXT]
	mov QWORD	rcx, [rax + OFFSET_LIST_LAST]
	test		rbx, rbx
	jz			.ft_lstpop__end
	mov QWORD	[rbx + OFFSET_LIST_NEXT], rcx

.ft_lstpop__set_first:

	; node->next->first = node->last->first
	mov QWORD	rbx, [rax + OFFSET_LIST_NEXT]
	mov QWORD	rcx, [rax + OFFSET_LIST_LAST]

	test		rbx, rbx
	jz			.ft_lstpop__end
	test		rcx, rcx
	jz			.ft_lstpop__end

	mov QWORD	rcx, [rcx + OFFSET_LIST_FIRST]
	mov QWORD	[rbx + OFFSET_LIST_FIRST], rcx

.ft_lstpop__end:

	mov		rsp, rbp
	pop		rbp
	ret

.ft_lstpop__null_root:

	jmp		.ft_lstpop__end
