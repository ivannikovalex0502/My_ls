#include "uls.h"

void mx_sort_size(t_sort *gen) {
    for (t_sort *i = gen; i; i = i->next) {
        for (t_sort *j = gen; j->next; j = j->next) {
            if (j->cnst->size_bytes < j->next->cnst->size_bytes) {
                t_const *cnst = j->cnst;

                j->cnst = j->next->cnst;
                j->next->cnst = cnst;
            }
        }
    }
}

