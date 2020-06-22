#include "uls.h"

void mx_get_link(struct stat st, t_const *cnst) {
    cnst->link =  st.st_nlink;
    cnst->strlinkcount = mx_itoa(cnst->link);
}
