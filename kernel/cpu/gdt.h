#ifndef CPU_GDT_H_
#define CPU_GDT_H_

//   Before I implement paging I'll stick to this

struct gdt_info
{
    unsigned short limit_low;
    unsigned short base_low;
    unsigned char base_middle;
    unsigned char access;
    unsigned char granularity;
    unsigned char base_high;
} __attribute__((packed)); // packed disables compiler's optimization

// GDT pointer struct
struct gdt_ptr
{
    unsigned short limit;
    unsigned int base;
} __attribute__((packed));

inline struct gdt_info gdt[3]; // NULL, CODE, DATA
inline struct gdt_ptr gp;

namespace Kernel
{
    void gdt_set(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran);
    void gdt_install();
} // Kernel

#endif