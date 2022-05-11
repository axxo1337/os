ASM=nasm
CC=i686-elf-g++
LD=i686-elf-ld
CFLAGS=-ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
LINKFLAGS=-ffreestanding -O2 -nostdlib -lgcc
ASMFLAGS=-felf32

osBoot:
	${ASM} ${ASMFLAGS} kernel/boot.s -o build/boot.o 

osKernel: 
	${CC} -c kernel/kernel.cpp -o build/kernel.o ${CFLAGS}

osLink:
	${CC} -T kernel/linker.ld -o build/os.bin ${LINKFLAGS} build/boot.o build/kernel.o

osBuild:
	${ASM} ${ASMFLAGS} kernel/boot.s -o build/boot.o 
	${CC} -c kernel/kernel.cpp -o build/kernel.o ${CFLAGS}
	${CC} -T kernel/linker.ld -o build/os.bin ${LINKFLAGS} build/boot.o build/kernel.o