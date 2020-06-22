#include "uls.h"

static void flags_include_basic(char *cont, t_data *app, int len);
static int is_flag_1(char cont, t_data *app);
static int is_flag_l(char cont, t_data *app);

void mx_basic_flags(char *cont, t_data *app, int len) {
    int i = 0;

    if (mx_get_char_index(cont, 'o') >= 0)
        app->flags[5] = 1;
    if (mx_get_char_index(cont, 'g') >= 0)
        app->flags[3] = 1;
    for (i = mx_strlen(cont) - 1; i >= 0; i--) {
        if (is_flag_1(cont[i], app) == 1) // проверка на flag 1
            break;
        else if (is_flag_l(cont[i], app) == 1)
            break;
    }
    if (app->flags[3] == 1 || app->flags[4] == 1 || app->flags[5] == 1) {
        flags_include_basic(cont, app, len);
    }
}
static int is_flag_1(char cont, t_data *app) {
    if (cont == '1') {
        app->flags[2] = 1;
        app->flags[3] = 0;
        app->flags[5] = 0;
        return 1;
    }
    return 0;
}

static int is_flag_l(char cont, t_data *app) {
    if (cont == 'l') {
        app->flags[4] = 1;
        return 1;
    }
    return 0;
}

static void flags_include_basic(char *cont, t_data *app, int len) {
    
        if (mx_memchr(cont, 'h', len))
            app->flags[14] = 1;
        if (mx_memchr(cont, 'T', len))
            app->flags[6] = 1;
        if (mx_memchr(cont, 'u', len))
            app->flags[13] = 1;
}
