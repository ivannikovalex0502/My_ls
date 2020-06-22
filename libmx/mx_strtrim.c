#include "libmx.h"

static bool chek(char tmp) {
    if (tmp == ' ' || tmp == '\t' || tmp == '\n' 
        || tmp== '\v' || tmp == '\f' || tmp== '\r' || tmp == '\b')
        return 1;
    return 0;
}

static int count(char *str, int len, int last) {
    str += last - 1;
    while (chek(*str)) {
        str--;
        len++;
    }
    str -= (last - len - 1);
    while (chek(*str)){
        str++;
        len++;
    }
    return len;
}

static char *entry(int last, int len, char *str) {
    char *new = mx_strnew(last - len); 

    for(int j = 0; j < last - len; j++){
        new[j] = *str;
        str++;
    }
    return new;
}

char *mx_strtrim(const char *str) {
    int len = 0;
    int last;
    int i;

    if (str == NULL || !*str)
        return NULL;
    last = mx_strlen(str);
    for( i = 0; str[i] != '\0' && chek(str[i]); i++);
    if(i == mx_strlen(str))
        return mx_strnew(0);
    len = count((char *)str, len, last);
    return entry(last, len, (char *)str);
}
