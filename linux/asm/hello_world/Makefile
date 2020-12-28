src = $(wildcard *.s)
obj = $(src:.s=.o)

AS := nasm

ASFLAGS := -f elf
LDFLAGS := -s -m elf_i386

.PHONY: clean

%.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

hello: $(obj)
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	rm -f $(obj) hello
