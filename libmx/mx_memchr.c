#include "libmx.h"
#include <string.h>

void *mx_memchr(const void *s, int c, size_t n)
{
    char *point = (char *)s;
    for(unsigned int i = 0; i < n && *point; i++)
    {
        if(*point == c)
            return point;
        point++;
    }
    return NULL;
}
