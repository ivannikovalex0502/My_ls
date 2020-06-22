#include "uls.h"

void mx_sort_revers(t_sort *gen, t_data *data) {
    t_const **tmp = malloc(sizeof(t_const) * (data->size));
    t_sort *save = gen;

    tmp[data->size] = NULL;
    for (int i = 0; i < data->size; i++) {
        tmp[i] = gen->cnst;
        gen = gen->next;
    }
    gen = save;
    for (int i = data->size - 1; i >= 0; i--) {
        gen->cnst = tmp[i];
        gen = gen->next;
    }
    free(tmp);
}
