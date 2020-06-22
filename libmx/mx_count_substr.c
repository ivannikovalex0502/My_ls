#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int count = 0;
    int len = mx_strlen(sub);
    int j = mx_strlen(str) / len;
    const char *tmp  = str;

    if(str == NULL || sub == NULL)
        return -1;
    if(!*str || !*sub)
        return count;
    len = mx_strlen(sub);
    j = mx_strlen(str) / len;
    for(int i = 0; i < j; i++) 
        if(mx_strstr(tmp, sub)) {   
            tmp = mx_strstr(tmp, sub);
            count++;
            tmp += len;          
        }
    return count;
}
