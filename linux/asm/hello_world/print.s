segment		.data
msg     db 'Hello, world!',0xa
len     equ $ - msg

segment		.text
global	print_hello, no_operation

print_hello:
	push eax
	push ebx
	push ecx
	push edx

	mov     edx,len
	mov     ecx,msg
	mov     ebx,1
	mov     eax,4
	int     0x80

	pop edx
	pop ecx
	pop ebx
	pop eax

	ret

no_operation:
	nop
	ret
