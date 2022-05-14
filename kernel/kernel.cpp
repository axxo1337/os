#include <kernel/tty.h>
#include <kernel/cpu/gdt.h>
#include <kernel/std/string.h>

/*
    TODO: 
    - Add IDT and setup
    - Add GDT flush
    - Add keyboard getc function to read key inputs
    - Move to pagging
*/

extern "C" void kernel_main()
{
    Kernel::gdt_install();
    terminal_initialize();
}