section	.text

global	ft_strdup
extern	ft_memdup
extern	ft_strlen

ft_strdup:

	push	rsi

	call	ft_strlen
	mov		rsi, rax
	call	ft_memdup

	pop		rsi
	ret
