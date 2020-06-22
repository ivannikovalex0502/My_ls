#include "uls.h"

void mx_flags_for_sort(char *cont, t_data *app) {
    int len = mx_strlen(cont);

    if(mx_memchr(cont, 't', len))
        app->flags[11] = 1;
    if(mx_memchr(cont, 'r', len))
        app->flags[12] = 1;
    if(mx_memchr(cont, 'S', len)) {
        app->flags[10] = 1;
        app->flags[11] = 0;
    }
}

