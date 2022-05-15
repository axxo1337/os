#include <kernel/cpu/idt.h>
#include <kernel/std/memory.h>

struct idt_info idt[256];
struct idt_ptr idtp;

// temp
void isr_common_stub()
{
}

#define inline_isr_no_code(num) __asm__("cli push byte 0 push byte %0 jmp %1" \
                                        :                                     \
                                        : "0"(num), "0" isr_common_stub)

#define inline_isr_yes_code(num) __asm__("cli push byte %0 jmp %1" \
                                         :                         \
                                         : "0"(num), "0" isr_common_stub)

void idt_load()
{
    __asm__ __volatile__("lidt %[idtp]"
                         :
                         : [idtp] "m"(idtp));
    return;
}

void Kernel::idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags)
{
    idt[num].base_lo = base & 0xff;
    idt[num].sel = sel;
    idt[num].always0 = 0;
    idt[num].flags = flags;
    idt[num].base_hi = (base >> 8) & 0xff;
}

void Kernel::idt_install()
{
    idtp.limit = (sizeof(struct idt_info) * 256) - 1;
    idtp.base = &idt;

    std::memset((int *)idt, 0, sizeof(struct idt_info) * 256);

    idt_load();
}