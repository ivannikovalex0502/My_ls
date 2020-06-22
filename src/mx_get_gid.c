#include "uls.h"

void mx_get_gid(struct stat st, t_const *cnst) {
    struct group *gr;

    gr = getgrgid(st.st_gid);
    if (gr == NULL)
        cnst->strgid = mx_itoa_sp(st.st_gid);
    else 
        cnst->strgid = gr->gr_name;
}
