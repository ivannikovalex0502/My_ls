#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    unsigned int one = mx_strlen(s1);
    char *s2;

    if (!*s1 || n == 0)
        return NULL;
    if (one <= n) 
        s2 = mx_strnew(one);
    else 
        s2 = mx_strnew(n);
    for (unsigned int i = 0; i < n && i < one; i++)
        s2[i] = s1[i];
    return s2;
}
