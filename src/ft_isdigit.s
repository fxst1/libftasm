
;
;	@PARAMS
;	RDI : value
;
;	@RETURN
;	if is digit return 1 else return 0
;


section .text
global	ft_isdigit

ft_isdigit:

	enter	0, 0
	mov		rax, 0
	cmp		rdi, 47
	jle		ft_isdigit__end
	cmp		rdi, 58
	jge		ft_isdigit__end
	mov		rax, 1

ft_isdigit__end:

	leave
	ret
