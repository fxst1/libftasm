
;
;	@PARAMS
;	RDI : value
;
;	@RETURN
;	if is digit or alpha return 1 else return 0
;


section .text
global	ft_isalnum
extern	ft_isalpha

ft_isalnum:

	enter	0, 0
	mov		rax, 0
	cmp		rdi, 47
	jle		ft_alnum__end
	cmp		rdi, 58
	jge		ft_alnum__test_alpha
	mov		rax, 1
	jmp		ft_alnum__end

ft_alnum__test_alpha:

	call	ft_isalpha

ft_alnum__end:

	leave
	ret
