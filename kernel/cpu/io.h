#ifndef CPU_IO_H_
#define CPU_IO_H_

#include <stdint.h>

namespace Kernel
{
    uint8_t inb(uint16_t port);
    void outb(uint16_t port, uint8_t data);
}

#endif