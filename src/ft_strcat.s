
;
;	@PARAMS
;	RDI : dest
;	RSI : src
;
;	@RETURN
;	dest
;

section .text
global	ft_strcat

ft_strcat:

	enter		0, 0						; Stack frame
	push		rdi							; Save dest
	push		rsi							; Save src

	cmp			rdi, 0						; if (dest == NULL)
	je			ft_strcat__end				; 	goto ft_strcat__end
	cmp			rsi, 0						; if (src == NULL)
	je			ft_strcat__end				; 	goto ft_strcat__end

ft_strcat__find_0:

	cmp byte	[rdi], 0					; if (*dest == 0)
	je			ft_strcat__cpy				;	goto ft_strcat__cpy
	inc			rdi							; dest++
	jmp			ft_strcat__find_0			; goto ft_strcat__find_0

ft_strcat__cpy:

	cmp byte	[rsi], 0					; if (*src == 0)
	je			ft_strcat__append_0			; 	goto ft_strcat__append_0
	mov byte	al, [rsi]					; AL = *src
	mov byte	[rdi], al					; *dest = AL
	inc			rsi							; src++
	inc			rdi							; dest++
	jmp			ft_strcat__cpy				; goto ft_strcat__cpy

ft_strcat__append_0:

	mov byte	[rdi], 0

ft_strcat__end:

	pop			rsi							; Restore src
	pop			rdi							; Restore dest
	mov			rax, rdi					; Return value is dest
	leave
	ret
