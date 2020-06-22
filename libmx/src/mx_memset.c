#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    char *res = b;

    for(unsigned int i = 0; i < len; i++)
        res[i] = c;
    return res;
}
