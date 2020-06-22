#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char *point = (unsigned char *)s;

    for (unsigned int i = n - 1; i >= 0; i--)
        if(point[i] == c)
            return point += i;
    return NULL;
}
