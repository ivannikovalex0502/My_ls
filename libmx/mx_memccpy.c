#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    char *point1 = (char *)dst;
    char *point2 = (char *)src;

    for(unsigned int i = 0; i < n; i++) {
        if(*point2 == c)
            return point1;
        *point1 = *point2;
        point1++;
        point2++;
    }
    return NULL;
}
