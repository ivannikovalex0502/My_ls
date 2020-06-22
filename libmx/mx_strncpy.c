#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    char *dst1 = dst;

    for (int i = 0; i < len; i++) {
        if (*src) {
            *dst = *src;
            dst++;
            src++;
        } 
        else {
            *dst = '\0';
            dst++;
        }
    }
    return dst1;
}
