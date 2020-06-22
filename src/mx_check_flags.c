#include "uls.h"

void mx_check_flags(char *s, t_data *app) {
    int len = mx_strlen(s);

    mx_basic_flags(s, app, len);
    mx_flags_for_sort(s, app);
    mx_other_flags(s, app);
    // for(int i = 0; i < 13; i++) {
        // printf("0  a -> %d\n", app->flags[0]);
        // printf("1  A -> %d\n", app->flags[1]);
        // printf("2  1 -> %d\n", app->flags[2]);
        // printf("3  g -> %d\n", app->flags[3]);
        // printf("4  l -> %d\n", app->flags[4]);
        // printf("5  o -> %d\n", app->flags[5]);
        // printf("6  T -> %d\n", app->flags[6]);
        // printf("7  i -> %d\n", app->flags[7]);
        // printf("8  s -> %d\n", app->flags[8]);
        // printf("9  f -> %d\n", app->flags[9]);
        // printf("10 S -> %d\n", app->flags[10]);
        // printf("11 t -> %d\n", app->flags[11]);
        // printf("12 r -> %d\n", app->flags[12]);
        // printf("13 u -> %d\n", app->flags[13]);
    free(s);
}

