#include "uls.h"

void mx_print_to_file(char **file, t_data *data) {
    for (int i = 0; i < data->size; i++) {
        mx_printstr(file[i]);
        mx_printstr("\n");
    }
}

