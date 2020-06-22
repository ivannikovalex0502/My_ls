#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    char *point1 = (char *)s1;
    char *point2 = (char *)s2;

    for (unsigned int i = 0; i < n ; i++) {
        if(*point1 != *point2)
            return *point1 - *point2;
        point1++;
        point2++;
    }
    return 0;
}
