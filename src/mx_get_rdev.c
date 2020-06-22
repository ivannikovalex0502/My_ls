#include "uls.h"

void mx_get_rdev(struct stat st, t_const *cnst) {
    cnst->rdev = st.st_rdev;
}
