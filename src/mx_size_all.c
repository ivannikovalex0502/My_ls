#include "uls.h"

int mx_size_a(t_data *data) {
    int col = data->size / data->width;

    if (data->size % data->width != 0)
        col++;
    col *= data->width;
    return col;
}
