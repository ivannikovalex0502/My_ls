#include "uls.h"

static void hex(int number, t_const *cnst, int flag);

void mx_get_minmaj(t_const *cnst) {
    cnst->min = MX_MINOR(cnst->rdev);
    cnst->maj = MX_MAJOR(cnst->rdev);
    if (cnst->min > 255)
        hex(cnst->min, cnst, 1);
    else
        cnst->strmin = mx_itoa(cnst->min);
    if (cnst->maj > 255)
        hex(cnst->maj, cnst, 0);
    else
        cnst->strmaj = mx_itoa(cnst->maj);
}

static void hex(int number, t_const *cnst, int flag) {
    char *hexstr = mx_nbr_to_hex((unsigned long)number);
    char *result = mx_strnew(10);

    cnst->strmaj = NULL;
    cnst->strmin = NULL;
    result[0] = '0';
    result[1] = 'x';
    for (int i = 0; i != (8 - mx_strlen(hexstr)); i++)
        result[i + 2] = '0';
    mx_strcat(result, hexstr);
    if (flag)
        cnst->strmin = result;
    if (!flag)
        cnst->strmaj = result;
    free(hexstr);
}
