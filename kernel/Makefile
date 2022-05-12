CC=i686-elf-g++
LD=i686-elf-ld
CFLAGS=-w -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti -fpermissive -I include
LINKFLAGS=-ffreestanding -O2 -nostdlib -lgcc
INCLUDE=-I ./include

SRCS = $(shell find -d . -name '*.cpp')
OBJS = $(shell find -d . -name '*.o')

clean:
	@rm ${OBJS}
# Kernel Build
build-bin:
	@nasm -felf32 arch/i386/boot.s -o build/boot.o
	@${CC} -c ${SRCS} ${CFLAGS}
	@${CC} -T arch/i386/linker.ld ${LINKFLAGS} -o build/os.bin ${OBJS}
run-qemu: 
	qemu-system-i386 -kernel build/os.bin