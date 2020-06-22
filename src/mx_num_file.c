#include "uls.h"

void mx_num_file(t_const *cnst, t_data *data) {
    int num = 0;

    while (cnst != NULL) {
        if (cnst->name_c != NULL && num < mx_strlen(cnst->name_c))
            num = mx_strlen(cnst->name_c);
        cnst = cnst->next;
    }
    num = num + ( 8 - (num % 8));
    data->max_len_name = num;
    data->strtotal = mx_itoa_sp(data->total);
    if (isatty(1) != 0) {        
        data->colums = mx_columns();
        data->width = data->colums / data->max_len_name;
        data->size_all = mx_size_a(data);
    }
}
