#include "libmx.h"

static bool check_spaces(char c) {
    if (c == ' ' || c == '\t' 
        || c == '\n' || c == '\v' 
        || c == '\f' || c == '\r')
        return true;
    return false;
}

static int length(char *str) {
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (!check_spaces(str[i]))
            len++;
    return len;
}

static int num_spaces(char *str) {
    int size = 0;

    str = mx_strtrim(str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (check_spaces(str[i])) {
            size++;
            while (check_spaces(str[i]))
                i++;
            i--;
        }
    }
    free(str);
    return size;
}

static char *entry_str(char *str, int len, int size) {
    char *result = mx_strnew(len + size);
    int j = 0;

    for (int i = 0; str[i] != '\0' && j < len + size; i++) {
        if (!check_spaces(str[i]))
            result[j] = str[i];
        else if (check_spaces(str[i])) {
            result[j] = ' ';
            while (check_spaces(str[i]))
                i++;
            i--;
        }
        j++;
    }
    return result; 
}

char *mx_del_extra_spaces(const char *str) {
    int len; 
    int size;

    if (str == NULL)
        return NULL;
    if (!*str)
        return (char *)str;
    len = length((char *)str);
    size = num_spaces((char *)str);
    while (check_spaces(*str)) 
        str++;
    return entry_str((char *)str, len, size);
}
