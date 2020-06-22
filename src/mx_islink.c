#include "uls.h"

bool mx_islink(t_const *cnst) {
    if (cnst->strrwx[0] == 'l')
        return true;
    return false;
}
