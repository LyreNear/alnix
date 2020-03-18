#!Makefile

C_SOURCES = $(shell find . -name "*.c")
C_OBJECTS = $(patsubst %.c, %.o, $(C_SOURCES))
S_SOURCES = $(shell find . -name "*.s")
C_OBJECTS = $(patsubst %.s, %.o, $(S_SOURCES))

CC = gcc
LD = ld
ASM = nasm

C_FLAGS = -c -Wall -m32 -ggdb -gstabs+ -nostdinc -fno-builtin -fno-stack-protector -I include
LD_FLAGS = -T tools/kernel.ld -m elf_i386 -nostdlib
ASM_FLAGS = -f elf -g -F stabs

all: $(S_OBJECTS) $(C_OBJECTS) link update_image

.c.o:
			@echo compile file $< ...
			$(CC) $(C_FLAGS) $< -o $@

.s.o:
			@echo assemble file $< ...
			$(ASM) $(ASM_FLAGS) $<

link:
			@echo link file...
			$(LD) $(LD_FLAGS) $(S_OBJECTS) $(C_OBJECTS) -o alex_kernel

.PHONY:clean
clean:
			$(RM) $(S_OBJECTS) $(C_OBJECTS) alex_kernel

.PHONY:update_image
update_image:
			sudo mount floppy.img /mnt/kernel
			sudo cp alex_kernel /mnt/kernel/alex_kernel
			sleep 1
			sudo umount /mnt/kernel

.PHONY:mount_image
mount_image:
			sudo mount floppy.image /mtn/kernel

.PHONY:umount_image
umount_image:
			sudo umount /mnt/kernel

.PHONY:qemu
qemu:
			qemu -fda floppy.img -boot a

.PHONY:bochs
bochs:
			bochs -f tools/bochsrc.txt

.PHONY:debug
debug:
			qemu -S -s -fda floppy.img -boot a &
			sleep 1
			cgdb -x tools/gdbinit
