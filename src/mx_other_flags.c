#include "uls.h"

void mx_other_flags(char *cont, t_data *app) {
    int len = mx_strlen(cont);

    if (mx_memchr(cont, 's', len))
        app->flags[8] = 1;
    if (mx_memchr(cont, 'i', len))
        app->flags[7] = 1;
    if (mx_memchr(cont, 'a', len))
        app->flags[0] = 1;
    if(mx_memchr(cont, 'f', len))
        app->flags[9] = 1;       // спросить у Влада по-поводу флага -a (он связан с флагом -f)
    else if (mx_memchr(cont, 'A', len))
        app->flags[1] = 1;
}

