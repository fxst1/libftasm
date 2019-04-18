
;
;	@PARAMS
;	RDI : value
;

section .text

global	ft_tolower

ft_tolower:

	mov		rax, rdi
	cmp		rdi, 64
	jle		ft_tolower__end
	cmp		rdi, 91
	jge		ft_tolower__end

	add		rax, 32

ft_tolower__end:

	ret
