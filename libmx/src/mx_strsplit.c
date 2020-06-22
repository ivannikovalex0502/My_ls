#include "libmx.h"

static char **result_return(int index, char **result, int number, char *s) {
    if(index == -1) {
        *result = mx_strndup(s, mx_strlen(s));
        result++;
        *result = NULL;
        result -= number;
        return result;
    }
    *result = NULL;
    result -= number;
    return result;
}

char **mx_strsplit(const char *s, char c) {
    int index = 0;
    int number = mx_count_words(s, c);
    char **result = malloc(sizeof(char *) * (number + 1));

    for(int i = 0; i < number; i++) {
        while(*s == c)
            s++;
        index = mx_get_char_index(s, c);
        if (index == -1)
            return result_return(index, result, number, (char *)s);
        *result = mx_strndup(s, index);
        s += index;
        result++;
    }
    return result_return(index, result, number, (char *)s);
}
