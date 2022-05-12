#include <kernel/tty.h>

extern "C" void kernel_main()
{
    terminal_initialize();
    terminal_write("Hello, World!", 13);
}