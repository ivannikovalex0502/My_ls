#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) { 
    unsigned char *point1 = (unsigned char *)big;
    unsigned char *point2 = (unsigned char *)little;
    unsigned int flag = 0;
    unsigned int n = 0;

    if(big_len == 0 || little_len > big_len || little_len == 0)
        return NULL;
    for(unsigned int i = 0; i < big_len - little_len + 1; i++) {
        n = 0;
        flag = 0;
        for(unsigned int j = 0; j < little_len; j++, n++)
            if(point1[n] == point2[j])
                flag++;
        if(flag == little_len)
            return point1;
        point1++;
    }
    return NULL;
}
