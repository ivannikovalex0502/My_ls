#include "uls.h"

void mx_full_path(t_data *data, t_const *data_l) {
    while (data_l != NULL) {
        if (data->path !=  NULL) {
            char *tmp = mx_strjoin(data->path, "/");

            data_l->ful_n = mx_strjoin(tmp, data_l->name);
            printf("%s\n", data_l->ful_n);
            free(tmp);
        }
        else
            data_l->ful_n = NULL;
        data_l = data_l->next;
    }
}
