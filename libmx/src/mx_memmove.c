#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    char *point1 = dst;
    const char *point2 = src;
    char *mid = mx_strnew(len);

    for(unsigned int i = 0; i < len; i++)
        mid[i] = point2[i];
    for(unsigned int i = 0; i < len; i++)
        point1[i] = mid[i];
    free(mid);
    return dst;
}
