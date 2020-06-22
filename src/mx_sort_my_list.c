#include "uls.h"

void mx_sort_my_list(t_sort *gen) {
    
    for (t_sort *i = gen; i; i = i->next) {
        for (t_sort *j = gen; j->next; j = j->next) {
            if (mx_strcmp(j->cnst->name, j->next->cnst->name) > 0) {
                t_const *tmp = j->cnst;

                j->cnst = j->next->cnst;
                j->next->cnst = tmp;
            }
        }
    }
}
