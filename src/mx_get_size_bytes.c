#include "uls.h"

void mx_get_size_bytes(struct stat st, t_const *cnst) {
    cnst->size_bytes = st.st_size;
    cnst->strbytes = mx_itoa(cnst->size_bytes);
}
