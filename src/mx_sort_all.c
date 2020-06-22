#include "uls.h"

// static void free_gen(t_sort *gen);

void mx_sort_all(t_data *data, t_sort *general) {
    if (data->flags[9]) {
        mx_creat_list(general);
        data->cnst = general->cnst;
        data->sort = general;
        return;
    }
    if(data->flags[10])
        mx_sort_size(general);
    else if (data->flags[11])
        mx_sort_time(general);
    else
        mx_sort_my_list(general);
    if (data->flags[12])
        mx_sort_revers(general, data);
    mx_creat_list(general);
    data->cnst = general->cnst;
    data->sort = general;
}

// static void free_gen(t_sort *gen) {
//     t_sort *tmp = gen->next;

//     while (tmp != NULL) {
//         free(gen);
//         gen = tmp;
//         tmp = tmp->next;
//     }
//     free(gen);
//     gen = NULL;
// }
