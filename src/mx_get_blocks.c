#include "uls.h"

void mx_get_blocks(struct stat st, t_const *cnst) {
    cnst->blocks = st.st_blocks;
    cnst->strblocks = mx_itoa(cnst->blocks);
}
