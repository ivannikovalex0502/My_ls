#include "uls.h"

static void check_is_valid(char **s, int argc);

void mx_count_flags_in_str(char **argv, t_data *app, int argc) {
    char *contain = NULL;
    int size = 1;
    int num = mx_dir_arr(argv, argc, app);

    check_is_valid(argv, num);
    for (int i = 1; i < num; i++) {
        size += mx_strlen(argv[i]) - 1;   
    }
    contain = mx_strnew(size);
    for (int i = 1; i < num; i++) {          
        argv[i]++;
        mx_strcat(contain, argv[i]);
    }
    mx_flags_into_arr(contain, app);
}

static void check_is_valid(char **s, int argc) {
    for (int i = 1; i < argc; i++) {
        if (s[i][0] != '-')
            break;
        if (mx_count_substr(s[i], "-") > 1
            && mx_strcmp(s[i], "--") != 0) 
        {
            mx_printerr(INVALID_ARGV, **s);
        }
    }
    argc++;
}

