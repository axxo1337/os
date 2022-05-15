#ifndef CPU_IDT_H_
#define CPU_IDT_H_

#define disable_interrupts() __asm__("cli")
#define enable_interrupts() __asm__("sti")

struct idt_info
{
    unsigned short base_lo;
    unsigned short sel;    /* Our kernel segment goes here! */
    unsigned char always0; /* This will ALWAYS be set to 0! */
    unsigned char flags;   /* Set using the above table! */
    unsigned short base_hi;
} __attribute__((packed));

struct idt_ptr
{
    unsigned short limit;
    unsigned int base;
} __attribute__((packed));

namespace Kernel
{
    void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);
    void idt_install();
} // Kernel

#endif