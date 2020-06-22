#include "uls.h"

void mx_get_dev(struct stat st, t_const *cnst) {
    cnst->dev = st.st_dev;
}
