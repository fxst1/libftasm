
;
;	@PARAMS
;	RDI : value
;
;	@RETURN
;	if is a printable return 1 else return 0
;


section .text
global	ft_isprint

ft_isprint:

	enter	0, 0
	mov		rax, 0
	cmp		rdi, 31
	jle		ft_isprint__end
	cmp		rdi, 127
	jge		ft_isprint__end
	mov		rax, 1

ft_isprint__end:

	leave
	ret
