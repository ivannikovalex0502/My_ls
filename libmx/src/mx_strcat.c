#include "libmx.h"

char *mx_strcat(char *restrict s1,const char *restrict s2) {
    int a = 0;
    int j = 0;

    if(s1 == NULL)
        return NULL;
    else if(s2 == NULL)
        return s1;
    else if(!*s2)
        return s1;
    a = mx_strlen(s1) + mx_strlen(s2);
    for(int i = mx_strlen(s1); i < a; i++, j++)
        s1[i] = s2[j];
    s1[a] = '\0';
    return s1;
}
