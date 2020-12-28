segment		.text
global		_start

extern		print_hello

_start:
	call print_hello

	mov     eax,1
	int     0x80
