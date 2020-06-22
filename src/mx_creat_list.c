#include "uls.h"

void mx_creat_list(t_sort *gen) {
    while (gen->next != NULL) {
        gen->cnst->next = gen->next->cnst;
        gen = gen->next;
    }
    gen->cnst->next = NULL;
}
