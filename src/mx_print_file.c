#include "uls.h"

void mx_print_file(t_data *data) {
    char **file = data->name_all;
    int max_len = data->max_len_name;

    if (data->isattyflag == 1 || data->flags[2])
        mx_print_to_file(file, data);
    else {
        mx_check_control_char(&file);
        for (int i = 0; i < data->size_all && file != NULL; i++) {
            if (i % data->width == 0 && i != 0)
                mx_printstr("\n");
            if (file[i] != NULL) {
                mx_printstr(file[i]);
                if ((i + 1) % data->width != 0 && file[i + 1] != NULL)    
                    for (int j = mx_strlen(file[i]); j < max_len; j++)
                        mx_printstr(" ");
            }
        }
        if (data->size != 0)
            mx_printstr("\n");
    }
}
