%define	NEWLINE_WIN		13, 10
%define	NEWLINE_UNIX	0xa
%ifidn __OUTPUT_FORMAT__, win32
% define NEWLINE NEWLINE_WIN
% define NEWLINE_SIZE 2
% define SYSCALL_READ	0x0
% define SYSCALL_WRITE	0x1
%elifidn __OUTPUT_FORMAT__, elf32
% define NEWLINE NEWLINE_UNIX
% define NEWLINE_SIZE 1
% define SYSCALL_READ	0x0
% define SYSCALL_WRITE	0x1
%elifidn __OUTPUT_FORMAT__, elf32
% define NEWLINE NEWLINE_UNIX
% define NEWLINE_SIZE 1
% define SYSCALL_READ	0x0
% define SYSCALL_WRITE	0x1
%elifidn __OUTPUT_FORMAT__, macho32
% define NEWLINE NEWLINE_UNIX
% define NEWLINE_SIZE 1
% define SYSCALL_READ	0x0
% define SYSCALL_WRITE	0x1
%elifidn __OUTPUT_FORMAT__, macho64
 %define NEWLINE NEWLINE_UNIX
 %define NEWLINE_SIZE 1
 %define SYSCALL_READ	0x2000003
 %define SYSCALL_WRITE	0x2000004
%else
% error "Undefined output format"
%endif
%define	STDIN_FILENO		0
%define	STDOUT_FILENO		1
%define	STDERR_FILENO		2

%define	SIZEOF_LIST			0x28
%define	OFFSET_LIST_CONTENT		0x0
%define	OFFSET_LIST_CONTENTS	0x8
%define	OFFSET_LIST_NEXT		0x10
%define	OFFSET_LIST_LAST		0x18
%define	OFFSET_LIST_FIRST		0x20

%macro	PREPARE_STACK_FRAME 0
	push    rbp
	mov     rbp, rsp
%endmacro

%define	ALIGNSTACK (~15)

%macro	ALIGNEDSTACK_CALL 2
	PREPARE_STACK_FRAME
	and		%1, ALIGNSTACK(16)
	call	%2
	mov		rsp, r8
	pop		r8
	ret
%endmacro
