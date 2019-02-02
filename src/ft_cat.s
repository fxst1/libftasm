
;
;	@PARAMS
;	RDI : file descriptor
;

%define RESERVE_SIZE 2048

section .text
global	ft_cat

ft_cat:

	enter		0, 0
	push		rax
	push		rbx

	mov			rbx, rdi
	sub			rsp, RESERVE_SIZE

	cmp DWORD	edi, 0
	jl			ft_cat__end

ft_cat__rw:

	mov			rdi, rbx
	mov			rsi, rsp
	mov			rdx, RESERVE_SIZE
	mov			rax, 0x2000003
	syscall

	jc			ft_cat__end
	cmp			rax, 0
	jle			ft_cat__end

	mov			rdi, 1
	mov			rsi, rsp
	mov			rdx, rax
	mov			rax, 0x2000004
	syscall

	jmp			ft_cat__rw

ft_cat__end:

	add			rsp, RESERVE_SIZE
	pop			rbx
	pop			rax
	leave
	ret
