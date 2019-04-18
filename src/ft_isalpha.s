
;
;	@PARAMS
;	RDI : value
;
;	@RETURN
;	if is alpha return 1 else return 0
;


section .text
global	ft_isalpha

ft_isalpha:

	enter		0, 0
	mov		rax, 0
	cmp		rdi, 64
	jle		ft_isalpha__end
	cmp		rdi, 123
	jge		ft_isalpha__end
	cmp		rdi, 97
	jge		ft_isalpha__ok
	cmp		rdi, 90
	jle		ft_isalpha__ok
	jmp		ft_isalpha__end

ft_isalpha__ok:

	mov		rax, 1

ft_isalpha__end:

	leave
	ret
