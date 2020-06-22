#include "uls.h"

static t_data *get_dir(t_data *app, char **argv, int i, int argc);

int mx_dir_arr(char **argv, int argc, t_data *app) {
    int len = 0;
    int i;

    for (i = 1; i < argc; i++) {
        if (argv[i][0] != '-' || mx_strcmp(argv[i], "--") == 0) {
            if (mx_strcmp(argv[i], "--") == 0)
                i++;
            break;
        }
    }
    for (int j = i; j < argc; j++, len++);
    app->dir_arr = malloc(sizeof(char *) * len + 1);
    for (int j = 0; j <= len; j++) {
        (app->dir_arr)[j] = NULL;
    }
    app = get_dir(app, argv, i, argc);
    if (mx_strcmp(argv[i - 1], "--") == 0)
        i--;
    return i;
}

static t_data *get_dir(t_data *app, char **argv, int i, int argc) {
    for (int n = 0; i < argc; i++, n++) {
        app->dir_arr[n] = mx_strdup(argv[i]);
    }
    return app;
}

