
;
;	@PARAMS
;	RDI : value
;
;	@RETURN
;	if is ascii return 1 else return 0
;


section .text
global	ft_isascii

ft_isascii:

	enter	0, 0
	mov		rax, 0
	cmp		rdi, 0
	jl		ft_isascii__end
	cmp		rdi, 127
	jg		ft_isascii__end
	mov		rax, 1

ft_isascii__end:

	leave
	ret
