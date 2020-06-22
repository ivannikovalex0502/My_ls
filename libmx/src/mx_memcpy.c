#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    char *pointer1 = dst;
    char *pointer2 = (char *)src;

    for(unsigned int i = 0; i < n; i++) 
        pointer1[i] = pointer2[i];
    return dst;
}
