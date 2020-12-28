segment		.text

global print_hello

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

	pop eax
	pop ebx
	pop ecx
	pop edx

	ret

segment     .data
msg     db 'Hello, world!',0xa
len     equ $ - msg
