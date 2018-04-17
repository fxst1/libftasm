section	.text

global	ft_strdup
extern	ft_strlen
extern	ft_memcpy
extern	malloc

ft_strdup:

	enter	0, 0

	push	rdi
	push	rsi

	mov		rax, 0
	cmp		rdi, 0
	je		ft_strdup__end

	call	ft_strlen
	push	rax
	mov		rdi, rax
	call	malloc
	cmp		rax, 0
	je		ft_strdup__error

	mov		rdi, rax
	pop		rdx
	pop		rsi
	call	ft_memcpy
	pop		rsi

	leave
	ret


ft_strdup__error:

	pop		rax
	mov		rax, 0

ft_strdup__end:

	pop		rsi
	pop		rdi

	leave
	ret
