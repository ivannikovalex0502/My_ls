#include "libmx.h"

void mx_str_reverse(char *s) {
    int j = 0;
    char *copy_revers = NULL;

    if(s == NULL)
        return;
    if(!*s)
        return;
    copy_revers = mx_strnew(mx_strlen(s));
    for (int i = mx_strlen(s) - 1; i >= 0; i--, j++)
        copy_revers[j] = s[i];
    for (int i = 0; i < mx_strlen(s); i++)
        s[i] = copy_revers[i];
    free(copy_revers);
}
