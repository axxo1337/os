MBALIGN  equ  1 << 0            ; align loaded modules on page boundaries
MEMINFO  equ  1 << 1            ; provide memory map
FLAGS    equ  MBALIGN | MEMINFO ; combine flags
MAGIC    equ  0x1BADB002        ; allows the bootloader to find the header
CHECKSUM equ -(MAGIC + FLAGS)   ; checksum

; Multiboot header to mark as kernel
; The bootloader will look for this signature
section .multiboot
align 4
    dd MAGIC
    dd FLAGS
    dd CHECKSUM

; The kernel has to allocates it's own stack
; Must be 16-bytes aligned
section .bss
align 16
stack_bottom:
    resb 16384 ; 16 KiB -> 1KiB is 1024 bytes
stack_top:

; The linker script specifies _start as entry to the kernel
; The bootloader will jump here
section .text:function (_start.end - _start) ; not sure
global _start
_start:
    ; Now in protected mode, the kernel has full control over the CPU

    ; Make the esp point to the top of the stack
    mov esp, stack_top

    ; Jump to the C++ code
    extern kernel_main
    call kernel_main

    ; If done, put system in infinite loop
    cli ; clear & disable interrupts
.hang:
    hlt ; wait for next interrupt but since they are disabled will block
    jmp .hang