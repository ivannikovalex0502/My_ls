#include <unistd.h>
#include "libmx.h"

int mx_strlen(const char *s);

int mx_count_words(const char *str, char c) {
    if(str == NULL || !*str)
        return -1;

    const char *tmp = str;
    int count = 0;

    while (*tmp != '\0') {
        for (int j = 0; tmp[j] == c && tmp[j] != '\0'; j++)
            str++;
        tmp = str;
        if(*tmp == '\0')
            return count;
        for (int j = 0; tmp[j] != c && tmp[j] != '\0'; j++)
            str++;
        tmp = str;
        count++;
    }
    return count;
}
