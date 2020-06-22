#include "uls.h"

void mx_print_error(const char *s) {
    write(2, s, mx_strlen(s));
}

