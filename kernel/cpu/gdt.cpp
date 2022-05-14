#include <kernel/cpu/gdt.h>

void Kernel::gdt_set(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran)
{
    /* Setup the descriptor base address */
    gdt[num].base_low = (base & 0xFFFF);
    gdt[num].base_middle = (base >> 16) & 0xFF;
    gdt[num].base_high = (base >> 24) & 0xFF;

    /* Setup the descriptor limits */
    gdt[num].limit_low = (limit & 0xFFFF);
    gdt[num].granularity = ((limit >> 16) & 0x0F);

    /* Finally, set up the granularity and access flags */
    gdt[num].granularity |= (gran & 0xF0);
    gdt[num].access = access;
}

void Kernel::gdt_install()
{
    /* Setup the GDT pointer and limit */
    gp.limit = (sizeof(struct gdt_info) * 3) - 1;
    gp.base = (unsigned int)&gdt;

    // NULL descriptor
    gdt_set(0, 0, 0, 0, 0);

    // Code segment
    gdt_set(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);

    // Data segment
    gdt_set(2, 0, 0xFFFFFFFF, 0x92, 0xCF);

    //gdt_flush();
}