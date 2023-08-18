SRCS = ./libs/string/ctos.c \
./libs/string/stringcat.c \
./libs/string/stringcpy.c \
./libs/string/stringstr.c \
./libs/string/memorycmp.c \
./libs/string/stringncmp.c \
./libs/string/stringcmp.c \
./libs/string/stringchar.c \
./libs/string/memoryset.c \
./libs/string/stringlen.c \
./libs/string/stringutil.c \
./Ker/tty.c \
./ker/io.c \
./kernel.c

OBJS = $($(SRCS):.c=.o)

CC = gcc
LD = ld

ASFLAGS = -m32
CFLAGS = -m32 -Wall -g -fno-stack-protector -nostdinc
LDFLAGS = -melf_i386 -Ttext=0x100000

kernel: $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

%.o: %.S
	$(CC) $(ASFLAGS) -c -o $@ $^

grub:
	grub-file --is-x86-multiboot kernel

iso:
	mkdir -p isodir/boot/grub
	cp kernel isodir/boot/kernel
	grub-mkrescue -o kernel.iso isodir

qemu:
	qemu-system-i386 -cdrom kernel.iso
	qemu-system-i386 -kernel kernel
clean:
	rm $(OBJS)

.PHONY: clean
