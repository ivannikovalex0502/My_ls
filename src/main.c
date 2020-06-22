#include "uls.h"

int main(int argc, char **argv) {
    t_data *data = malloc(sizeof(t_data));

    mx_read_flags(argv, argc, data);
    if (!data->dir_arr[0]) {
        if (mx_read_dir(".", data)) {
            if (data->flags[4] || data->flags[5] || data->flags[3])
                mx_print_l(data->cnst, data);
            else {
                if (data->flags[8] && data->size > 1)
                    mx_printstr_update("total ",
                    data->strtotal, "\n", NULL, NULL);
                mx_print_file(data);
            }
        }
    }
    else {
        mx_many_arguments(data);
        data->path = data->dir_arr[0];
        if (mx_read_dir(data->dir_arr[0], data)) {
            if (data->flags[4] || data->flags[5] || data->flags[3])
                mx_print_l(data->cnst, data);
            else {
                if (data->flags[8] && data->size > 1)
                    mx_printstr_update("total ",
                    data->strtotal, "\n", NULL, NULL);
                mx_print_file(data);
            }
        }
    }
    // system("leaks -q uls");
    exit(0);
    if (data->errors)
        return 1;
    return 0;
}











