#include <kernel/std/string.h>

int std::strlen(char *ptr)
{
    int len = 0;
    char *p = ptr;
    while (*p != '\0')
    {
        len++;
        p++;
    }
    return len;
}  