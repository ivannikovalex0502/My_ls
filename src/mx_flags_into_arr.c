#include "uls.h"

static void check_arr_flags(t_data *app, char *s);

void mx_flags_into_arr(char *s, t_data *app) {
    int size = 14;

    app->flags = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        app->flags[i] = 0;
    }
    mx_check_flags(s, app);
    check_arr_flags(app, s);
}

static void check_arr_flags(t_data *app, char *s) {
    app->str = "-ASTagfhilorstu1";
    int i;

    for (i = 0; i < mx_strlen(s); i++)
        if (mx_get_char_index(app->str, s[i]) < 0)
            mx_printerr(INVALID_FLAGS, s[i]);
}

