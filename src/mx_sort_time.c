#include "uls.h"

static void swap(t_sort *gen);

void mx_sort_time(t_sort *gen) {
    for (t_sort *i = gen; i; i = i->next) {
        for (t_sort *j = gen; j->next; j = j->next) {
            if (j->cnst->time < j->next->cnst->time)
                swap(j);
            else if (j->cnst->time == j->next->cnst->time 
                && j->cnst->nsec < j->next->cnst->nsec) {
                swap(j);
            }
            else if (j->cnst->time == j->next->cnst->time
                 && j->cnst->nsec == j->next->cnst->nsec
                 && (strcmp(j->cnst->name, j->next->cnst->name) > 0)) {
                 swap(j);
            }
        }
    }
}

static void swap(t_sort *gen) {
    t_const *tmp = gen->cnst;

    gen->cnst = gen->next->cnst;
    gen->next->cnst = tmp;
}
