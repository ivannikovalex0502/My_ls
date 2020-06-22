#include "uls.h"

void mx_get_data(t_data *data, t_const *cnst) {
    while (cnst != NULL) {
        mx_get_flag_l(cnst, data);
        cnst = cnst->next;
    }
    data->strtotal = mx_itoa(data->total);
}
