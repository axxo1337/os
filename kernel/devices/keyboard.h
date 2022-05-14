#ifndef DEVICE_KEYBOARD_H_
#define DEVICE_KEYBOARD_H_

extern unsigned char kmap[128];

namespace Kernel
{
    void keyboard_install();
} // Kernel

#endif