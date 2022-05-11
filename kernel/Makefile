CC=i686-elf-g++
LD=i686-elf-ld
CFLAGS=-ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
LINKFLAGS=-ffreestanding -O2 -nostdlib -lgcc
INCLUDE=-I ./include

# Kernel Build
build-bin:
	nasm -felf32 arch/i386/boot.s -o build/boot.o 
	${CC} -c kernel.cpp -o build/kernel.o ${CFLAGS}
	${CC} -T arch/i386/linker.ld -o build/os.bin ${LINKFLAGS} build/boot.o build/kernel.o

run-qemu: 
	qemu-system-i386 -kernel build/os.bin