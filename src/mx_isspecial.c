#include "uls.h"

bool mx_isspecial(t_const *cnst) {
    if (cnst->strrwx[0] == 'c' || cnst->strrwx[0] == 'b')
        return true;
    return false;
}
