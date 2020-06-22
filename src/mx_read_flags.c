#include "uls.h"

void mx_read_flags(char **argv, int argc, t_data *app) {
    app->dir_arr = NULL;
    app->path = NULL;
    app->errors = 0;
    mx_count_flags_in_str(argv, app, argc);
}

