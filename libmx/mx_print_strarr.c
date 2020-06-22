#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    if(delim == NULL || *arr == NULL)
        return;
    for(int i = 0; arr[1] != NULL; i++) {
        mx_printstr(*arr);
        mx_printstr(delim);
        arr++;
    }
    mx_printstr(*arr);
    mx_printstr("\n");
}
