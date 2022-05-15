#include <kernel/std/memory.h>

int* std::memset(int *ptr, int value, size_t num)
{
    for (int i = 0; i < num; i++)
        ptr[i] = value;
    return ptr;
}