#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) { 
    int n, len;
    int flag = 0;
    const char *tmp = haystack;

    if(needle == NULL)
        return (char *)haystack;
    len = mx_strlen(haystack);
    for(int i = 0; i < len; i++) {
        n = i;
        for(int j = 0; j < mx_strlen(needle); j++, n++)
            if(tmp[n] == needle[j])
                flag++;
        if(flag == mx_strlen(needle))
            return(char *)haystack;
        haystack++;
        flag = 0;
    }
    return NULL;
}
