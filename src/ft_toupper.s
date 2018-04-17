
;
;	@PARAMS
;	RDI : value
;

section .text

global	ft_toupper

ft_toupper:

	enter	0, 0
	mov		rax, rdi
	cmp		rdi, 96
	jle		ft_toupper__end
	cmp		rdi, 123
	jge		ft_toupper__end

	sub		rdi, 32

ft_toupper__end:

	leave
	ret
