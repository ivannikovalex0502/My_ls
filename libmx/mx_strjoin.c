#include "libmx.h"

static char *result(int numeral, char *s1, char *s2) { 
    char *result = mx_strnew(numeral);

    for(int i = 0; i < numeral; i++) {
        if(*s1 != '\0'){
            result[i] = *s1;
            s1++;
        }
        else {
            result[i] = *s2;
            s2++;
        }
    }
    return result;
}

char *mx_strjoin(const char *s1, const char *s2) {
    int numeral;

    if(s1 == NULL && s2 == NULL)
        return NULL;
    else if (s1 == NULL) {
        char *sres = mx_strndup(s2, mx_strlen(s2));
        return sres;
    }
    else if (s2 == NULL) {
        char *sres = mx_strndup(s1, mx_strlen(s1));
        return sres;
    }
    numeral = mx_strlen(s1) + mx_strlen(s2);
    return result(numeral, (char *)s1, (char *)s2);
}
