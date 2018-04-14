
;
;	@PARAMS
;	RDI : buffer
;	RSI : length
;

section .text
global	ft_bzero

ft_bzero:

	enter		0, 0			; Stack frame
	push		rdi				; Save buffer
	cmp			rdi, 0			; if (buffer == NULL)
	je			ft_bzero__end	; 	goto ft_bzero__end

ft_bzero__loop:

	cmp			rsi, 0			; if (length == 0)
	je			ft_bzero__end	;	goto ft_bzero__end
	mov byte 	[rdi], 0		; *buffer = 0
	dec			rsi				; length--
	inc			rdi				; buffer++
	jmp			ft_bzero__loop	; goto ft_bzero__loop

ft_bzero__end:

	pop			rdi				; Restore buffer
	leave
	ret
