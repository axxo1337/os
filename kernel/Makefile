CC=i686-elf-g++
LD=i686-elf-ld
CFLAGS=-w -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti -fpermissive -I include
LINKFLAGS=-ffreestanding -O2 -nostdlib -lgcc -I ../
INCLUDE=-I ./include

ASMS = $(shell find -d . -name '*.s')
SRCS = $(shell find -d . -name '*.cpp')
OBJS = $(shell find -d . -name '*.o')

clean:
	@rm ${OBJS}
# Kernel Build
build-bin:
	for file in ${ASMS} ; do \
		nasm -felf32 $$file ; \
	done

	@${CC} -c ${SRCS} ${CFLAGS}
	@${CC} -T arch/i386/linker.ld ${LINKFLAGS} -o build/os.bin ${OBJS}
	@mv *.o build
run-qemu: 
	qemu-system-i386 -kernel build/os.bin