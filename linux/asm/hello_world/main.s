%include	"print.inc"

segment		.text
global		_start

_start:
	call print_hello

	mov     eax,1
	int     0x80
